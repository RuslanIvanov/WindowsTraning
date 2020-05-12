#include "MyThQueue.h"

std::atomic<int> MyQueue::m_stopAll;
MyQueue::~MyQueue()
{
 
}

MyQueue::MyQueue()
{
    m_cap = MAX_SIZE;
    m_n = 0;
    m_first = 0;
    m_last = 0;
   
}

MyQueue::MyQueue(size_t n, const char& t)
{
    m_n = n;
    m_cap =  MAX_SIZE;
    m_first = 0;
    m_last = 0;
   

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
   
}


MyQueue::MyQueue(std::initializer_list<char> list)
{

    m_n = list.size();// count elements
    m_cap = MAX_SIZE;
    m_first = 0;
    m_last = 0;

    for (auto& l : list)
    {
         m_pmass[m_last] = l;
         m_last++;
    }
   
}

MyQueue::MyQueue(MyQueue&& r)
{
    std::cout << "\nMyQueue(MyQueue&& )\n";
    m_n = r.m_n;
    // m_pmass = r.m_pmass;
    memcpy(m_pmass, r.m_pmass, r.m_n);
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
    size_t tmp = r.m_n;
    m_n=tmp;
    delete[] m_pmass;
    memcpy(m_pmass, r.m_pmass, r.m_n);
   // m_pmass = r.m_pmass;
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
    std::cout << "\npush: m_n = " << m_n << " m_cap = " << m_cap << "";

    if (m_n < m_cap)//m_n - atom
    {
       // m.lock();
        m_pmass[(m_first + m_n) % m_cap] = t;//в m_last
        std::cout << " add in mass[" << (m_first + m_n) % m_cap << "] = " << m_pmass[(m_first + m_n) % m_cap];

        m_last = (m_last + 1) % m_cap; 
        m_n++;
        //m.unlock();

        m_bInsert = true;
        m_cvInsert.notify_all();// всем или первому ожид

    }
    else
    {// wait отработки pop

        std::unique_lock <std::mutex > l(m);
        m_cvClear.wait(l, [this]() { return !isEmpty() || m_bClear ; });//ждать по ка что то не освободится
     
       
    }
}


char MyQueue::pop()
{//error

   // std::lock_guard<std::mutex> l(m);

    size_t ind1 = m_first;

    if (m_n == 0)
    { 
             std::cout<<"\nQueue is empty! Wait notify\n"; 

             std::unique_lock <std::mutex > l(m);
             //m_cvInsert.wait_for(l, [this]() { return  m_bInsert; });
             using seconds = std::chrono::duration<long long>;
             seconds sec = static_cast<seconds>(3);
            if( m_cvInsert.wait_for(l,sec, [this]() { return  m_bInsert; }))
            {
                std::cout << "\nfinished waiting";
            }
            else 
            {
                std::cout << "\ntimed out pop";
                m_stopAll = 1;
            }

            return 0;
    }

    m_first = (m_first + 1) % m_cap;
    //std::cout << "\n[pop mass[" << ind1 << "] = " << m_pmass[ind1] << "] ";
    m_n--;
  
    return m_pmass[ind1];
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
    std::cout << " m_n " << m_n << " m_cap = " << m_cap << "";
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

   // auto resPop = s.pop();
    auto resPop = static_cast<char>(tolower(static_cast<unsigned char>(s.pop())));
    std::lock_guard<std::mutex> m(mut_out);
    std::cout << "\nth[" << std::this_thread::get_id() << "]" << " resPop = " << resPop;
}

void fWritersQ(MyQueue& s, char el)
{
    s.push(el);

    std::lock_guard<std::mutex> m(mut_out);
    std::cout << "\nth[" << std::this_thread::get_id() << "]" << " push = " << el;
}