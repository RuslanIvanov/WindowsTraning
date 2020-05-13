#include "MyThQueue.h"

std::atomic<int> MyQueue::m_stopAll;
MyQueue::~MyQueue()
{
    stopQ();
}

void MyQueue ::stopQ() 
{ 
    m_stopAll = 1; 
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
   // m_n = r.m_n;

    size_t n = r.m_n.load();
    m_n.store(n);

    memcpy(m_pmass, r.m_pmass, n);

    m_cap = r.m_cap;//при премещении забирать весь объем (всю емкость)
    m_last = r.m_last;//net perezapisi - ostavit indeksi kak est'
    m_first = r.m_first;

    r.m_n = 0;
  
    r.m_cap = 0;
    r.m_last = r.m_first = 0;
}

MyQueue& MyQueue::operator=(MyQueue&& r)
{
    std::cout << "\nMyQueue::move oper=()\n";

    if (&r == this) return *this;

   // size_t n = r.m_n; T operator(T t), где n копия будет
  //  m_n=n;

    size_t n = r.m_n.load();
    m_n.store(n);

    memcpy(m_pmass, r.m_pmass, n);
 
    m_cap = r.m_cap;//при премещении забирать весь объем (всю емкость)

    m_last = r.m_last;
    m_first = r.m_first;

    r.m_n = 0;
   // r.m_pmass = nullptr;
    r.m_cap = 0;
    r.m_last = r.m_first = 0;

    return *this;
}

void MyQueue::push(const char& t)
{//producer-производитель

   // if (m_stopAll == 0)
   // {

        std::cout << "\npush: m_n = " << m_n.load() << " m_cap = " << m_cap << "";

        std::unique_lock <std::mutex > l(m);
        using seconds = std::chrono::duration<long long>;
        seconds sec = static_cast<seconds>(1);
        bool b = m_cvClear.wait_for(l, sec, []() {return !isEmpty() && (m_stopAll == 0); });
        if (b)
        {
            if (m_stopAll == 1)
            {
                m_cvClear.notify_all();
                m_cvInsert.notify_all();
            }
            else
            {
                m_pmass[(m_first + m_n.load()) % m_cap] = t;//в m_last
                // std::cout << " add in mass[" << (m_first + m_n) % m_cap << "] = " << m_pmass[(m_first + m_n) % m_cap];

                m_last = (m_last + 1) % m_cap;
                m_n.fetch_add(1);
                m_bInsert = true;
             
                m_cvInsert.notify_one();// всем или первому ожид...
            }
        }
        else 
        {
            m_stopAll = 0;
            m_cvClear.notify_all();
            m_cvInsert.notify_all();
        }

        //if (m_n.load() < m_cap)//m_n - atom
        //{
        //    {
        //        std::unique_lock <std::mutex > l(m);//улс перем с t wait_for 

        //        m_pmass[(m_first + m_n.load()) % m_cap] = t;//в m_last
        //       // std::cout << " add in mass[" << (m_first + m_n) % m_cap << "] = " << m_pmass[(m_first + m_n) % m_cap];

        //        m_last = (m_last + 1) % m_cap;
        //        // m_n++;
        //    }

        //    m_n.fetch_add(1);
        //    m_bInsert = true;
        //    // m_cvInsert.notify_all();// всем или первому ожид...
        //    m_cvInsert.notify_one();// всем или первому ожид...

        //}
        //else
        //{// wait отработки pop

        //    std::unique_lock <std::mutex > l(m);
        //    //m.lock()
        //    //ждать по ка что то не освободится
        //    m_cvClear.wait(l, [this]() { return !isEmpty() || m_bClear; });//m.unlock()
        //    //m/lock()
        //}
    //}//m.unlock()
}

/*
void MyQueue::push(const char& t)
{//producer-производитель

    if (m_stopAll == 0)
    {

        std::cout << "\npush: m_n = " << m_n.load() << " m_cap = " << m_cap << "";
       
        // std::unique_lock <std::mutex > l(m);

        if (m_n.load() < m_cap)//m_n - atom
        {
            {
                std::unique_lock <std::mutex > l(m);//улс перем с t wait_for 

                m_pmass[(m_first + m_n.load()) % m_cap] = t;//в m_last
               // std::cout << " add in mass[" << (m_first + m_n) % m_cap << "] = " << m_pmass[(m_first + m_n) % m_cap];

                m_last = (m_last + 1) % m_cap;
                // m_n++;
            }

            m_n.fetch_add(1);
            m_bInsert = true;
           // m_cvInsert.notify_all();// всем или первому ожид...
            m_cvInsert.notify_one();// всем или первому ожид...

        }
        else
        {// wait отработки pop

           std::unique_lock <std::mutex > l(m);
            //m.lock()
            //ждать по ка что то не освободится
            m_cvClear.wait(l, [this]() { return !isEmpty() || m_bClear; });//m.unlock()
            //m/lock()
        }
    }//m.unlock()
}//*/


char MyQueue::pop()
{//error

    if (m_stopAll == 0)
    {

        //size_t ind1 = m_first;
      //  std::unique_lock <std::mutex > l(m);//mutex lock

        if (m_n.load() == 0)
        {
            std::cout << "\nQueue is empty! Wait notify...\n";

            {
                std::unique_lock <std::mutex > l(m);

                using seconds = std::chrono::duration<long long>;
                seconds sec = static_cast<seconds>(15);

                if (m_cvInsert.wait_for(l, sec, [this]() { return  m_bInsert; })) //m_n = 0
                {
                    //под защитой m
                    std::cout << "\nfinished waiting";
                    size_t ind1 = m_first;
                    m_first = (m_first + 1) % m_cap;
                    //m_n--;
                    m_n.fetch_sub(1);

                    return m_pmass[ind1];

                }
                else
                {
                    std::cout << "\ntimed out pop, no writers\n";
                    m_stopAll = 1;
                }
            }

            m_bClear = true;
            m_cvClear.notify_all();// уведомить что очередь пуста

            return 0;
        }

        std::unique_lock <std::mutex > ll(m);//mutex lock

        m_cvInsert.wait(ll, [this]() { return  m_bInsert; }); //mutex unlock while wait notify or perd return true (pred return false - если продолжать ждать)
       //mutex lock
       
        size_t ind1 = m_first;
        m_first = (m_first + 1) % m_cap;
        ////std::cout << "\n[pop mass[" << ind1 << "] = " << m_pmass[ind1] << "] ";
       // m_n--;
        m_n.fetch_sub(1);

        return m_pmass[ind1];
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