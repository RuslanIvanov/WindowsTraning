#include "MyThQueue.h"

std::atomic<int> MyQueue::m_stopAll;
MyQueue::~MyQueue()
{
    stopQ();
}

void MyQueue ::stopQ() 
{ 
    m_stopAll = 1; 
    m_cvPop.notify_all();
    m_cvPush.notify_all();

    std::cout << "\nSTOP QUEUE\n";
}

MyQueue::MyQueue()
{
    m_cap = MAX_SIZE;
    m_n = 0;
    m_first = 0;
    m_last = 0;

    m_stopAll = 0;
   
}

MyQueue::MyQueue(size_t n, const char& t)
{
    m_n = n;
    m_cap =  MAX_SIZE;
    m_first = 0;
    m_last = 0;
    m_stopAll = 0;

    for (; m_last < m_n; m_last++)
    {
         m_pmass[m_last] = t;
    }
   
  
}

MyQueue::MyQueue(size_t n)
{
    m_cap = MAX_SIZE;
    m_n = n;
    m_first = 0;
    m_last = 0;
    m_stopAll = 0;
   
}


MyQueue::MyQueue(std::initializer_list<char> list)
{

    m_n = list.size();// count elements
    m_cap = MAX_SIZE;
    m_first = 0;
    m_last = 0;
    m_stopAll = 0;
    for (auto& l : list)
    {
         m_pmass[m_last] = l;
         m_last++;
    }
   
}

MyQueue::MyQueue(MyQueue&& r)
{
    std::cout << "\nMyQueue(MyQueue&& )\n";
   // m_n = r.m_n;//no = разный атомарные переменые не атомарны друг к другу

    size_t n = r.m_n.load();
    m_n.store(n);
    r.m_n = 0;

    std::unique_lock <std::mutex > l(r.m);
    {
        memcpy(m_pmass, r.m_pmass, n);

        m_cap = r.m_cap;//при премещении забирать весь объем (всю емкость)
        m_last = r.m_last;//net perezapisi - ostavit indeksi kak est'
        m_first = r.m_first;

        r.m_cap = 0;
        r.m_last = r.m_first = 0;

        r.stopQ();// под защитой, что б  выйти на wait сигнальой перем с флагом стоп
    }

}

MyQueue& MyQueue::operator=(MyQueue&& r)
{
    std::cout << "\nMyQueue::move oper=()\n";

    if (&r == this) return *this;

   // size_t n = r.m_n; T operator(T t), где n копия будет

    m_stopAll = 1;// надо установить свои в стоп потоки, а => нужно уже успеть переписать за таймаут данные??

    size_t n = r.m_n.load();
    m_n.store(n);
    r.m_n = 0;

    std::lock(m, r.m);

    memcpy(m_pmass, r.m_pmass, n);
   
    m_cap = r.m_cap;//при премещении забирать весь объем (всю емкость)
    m_last = r.m_last;
    m_first = r.m_first;

    r.m_cap = 0;
    r.m_last = r.m_first = 0;

    r.stopQ();//что б  выйти на wait сигнальной пременной

    r.m.unlock();
    m.unlock();

    return *this;
}

void MyQueue::push(const char& t)
{//producer-производитель

        std::cout << "\npush: m_n = " << m_n.load() << " m_cap = " << m_cap << "";

        std::unique_lock <std::mutex > l(m);
        using seconds = std::chrono::duration<long long>;
        seconds sec = static_cast<seconds>(1);
        bool b = m_cvPop.wait_for(l, sec, [this]() {return !isFull() || !(m_stopAll == 0); });

        if (b)
        {
            if (m_stopAll == 1)
            {
                m_cvPop.notify_all();
                m_cvPush.notify_all();
            }
            else
            {
                m_pmass[(m_first + m_n.load()) % m_cap] = t;//в m_last
                // std::cout << " add in mass[" << (m_first + m_n) % m_cap << "] = " << m_pmass[(m_first + m_n) % m_cap];

                m_last = (m_last + 1) % m_cap;
                m_n.fetch_add(1);
                          
                m_cvPush.notify_one();// уведомлени одному читателю что вставили 
               // m_cvPush.notify_all();
            }
        }
        else 
        {// по тайауту
            std::cout << "\ntimed out push, no readers\n";

            m_stopAll = 1;//0;
            m_cvPop.notify_all();
            m_cvPush.notify_all();
        }
}

char MyQueue::pop()
{//consumer - читатель

           
                std::unique_lock <std::mutex > l(m);

                using seconds = std::chrono::duration<long long>;
                seconds sec = static_cast<seconds>(5);

                if (m_cvPush.wait_for(l, sec, [this]() { return (!isEmpty()) || !(m_stopAll == 0); } ))
                {//очередь не пуста и что то вставили

                    //под защитой m

                    if (m_stopAll == 1)
                    {
                        m_cvPop.notify_all();
                        m_cvPush.notify_all();
                    }
                    else 
                    {
                        std::cout << "\nfinished waiting";
                        size_t ind1 = m_first;
                        m_first = (m_first + 1) % m_cap;

                        m_n.fetch_sub(1);
                                     
                        m_cvPop.notify_one();// уведомить одного из писателей, что в очереди есть  место   
                       // m_cvPop.notify_all();
                        return m_pmass[ind1];
                    }
                }
                else
                {// по тайауту
                    std::cout << "\ntimed out pop, no writers\n";

                    m_stopAll = 1;
                    m_cvPop.notify_all();
                    m_cvPush.notify_all();

                }
            

                return 0;
}

void MyQueue::printQueueRaw()
{
    std::lock_guard<std::mutex> l(m);

    std::cout << "\nPRINTF RAW MyQueue: ";
    std::cout << " m_n " << m_n << " m_cap = " << m_cap << "";
    if (m_n == 0)
    {
        std::cout << " is EMPTY! "; return;
    }

   
    for (size_t i = 0; (i < m_n); ++i)
    {
        std::cout << "\nmass[" << i << "] = " << m_pmass[i];
    }
}


void MyQueue::printQueue()
{
    std::lock_guard<std::mutex> l(m);

    std::cout << "\nPRINTF MyQueue: ";
    std::cout << " m_n " << m_n<< " m_cap = " << m_cap << "";

    if ( m_n == 0 )
    {
        std::cout << " is EMPTY! "; return;
    }

    std::cout << "\nfirst " << m_first;
    std::cout << " last " << (m_first + m_n) % m_cap;
    size_t ind1 = m_first;
    for (size_t i = 0; i < m_n; ++i)
    {
        std::cout << "\n#" << i << " mass[" << ind1 % m_cap << "] = " << m_pmass[ind1 % m_cap];//m_n
        ind1++;
    }
}

std::mutex mut_out;
void fReadersQ(MyQueue& s)
{
    //std::this_thread::sleep_for(90ms);

    while ( 1 )//s.size()>0
    {
        
        auto resPop = static_cast<char>(tolower(static_cast<unsigned char>(s.pop())));
        std::lock_guard<std::mutex> m(mut_out);
        std::cout << "\nth[" << std::this_thread::get_id() << "]" << " resPop = " << resPop;

        if (s.getStop() == 1 || s.isEmpty())
        {
            break;
        }
    }
}

void fWritersQ(MyQueue& s, char el)
{
    s.push(el);

    std::lock_guard<std::mutex> m(mut_out);
    std::cout << "\nth[" << std::this_thread::get_id() << "]" << " push = " << el;
}