#pragma once
#include <iterator>
#include "MyQueue.h"

//template <typename T> class MyQueue;

template <typename T>
class MyQueueIter
{
    T* pm;
    size_t m_f;
    size_t m_l;
    size_t m_n;
    size_t m_cap;
    size_t m_ind;
public:

    typedef T value_type;
    typedef T* pointer;
    typedef T& reference;
 
    inline MyQueueIter() : pm(nullptr) { m_l = m_f = 0; m_n = 0; m_cap = 0; }
    inline MyQueueIter(T* t) : pm(t) { m_l = m_f = 0; m_n = 0; m_cap = 0; }
    inline MyQueueIter(T* t, size_t _f, size_t _l, size_t _n, size_t _cap) : pm(t), m_f(_f), m_l(_l), m_n(_n), m_cap(_cap)
    { 
        std::cout << "\nMyQueueIter(t,f,l,n,cap)"; 
    }

    inline MyQueueIter(T* t, size_t _ind) : pm(t), m_ind(_ind)
    {
        std::cout << "\nMyQueueIter(t,ind)";
    }

    inline MyQueueIter(const MyQueueIter& r) : pm(r.pm)
    {
        m_cap = r.m_cap;
        m_l = r.m_l;
        m_n = r.m_n;
        m_f = r.m_f;
    }

    inline T& operator*() const 
    { 
        return *pm; 
    }

    inline T* operator->() const
    { 
        return pm; 
    }

    inline T& operator*()  
    { 
        return *pm; 
    }
    inline T* operator->() 
    { 
        return pm; 
    }

    inline T& operator[](int j) /*const*/ { return pm[j]; }
    inline bool operator==(const MyQueueIter& o) const { return pm == o.pm; }
    inline bool operator!=(const MyQueueIter& o) const 
    { 
        return pm != o.pm; 
    }
    inline bool operator<(const MyQueueIter& other) const { return pm < other.pm; }
    inline bool operator<=(const MyQueueIter& other) const { return pm <= other.pm; }
    inline bool operator>(const MyQueueIter& other) const { return pm > other.pm; }
    inline bool operator>=(const MyQueueIter& other) const { return pm >= other.pm; }

    /*inline MyQueueIter& operator++() 
    {  //?????     
        //size_t ind1 = m_first % m_cap;
        //pm += ind1;// friend //??
        
       //size_t ind1 = m_f % m_cap;
       //pm += ind1;
       //m_f++;

        pm= &pm[m_f%m_cap];
        std::cout << " : "<<*pm;
        m_f++;
 
        return *this; 
    }//*/

    
    inline MyQueueIter& operator++()
    {      
        pm++;
        return *this;
    }//*/

    inline MyQueueIter operator++(int) { T* n = pm; ++pm; return n; }
    inline MyQueueIter& operator--() { pm--; return *this; }
    inline MyQueueIter operator--(int) { T* n = pm; pm--; return n; }
    inline MyQueueIter& operator+=(int j) { pm += j; return *this; }
    inline MyQueueIter& operator-=(int j) { pm -= j; return *this; }
    inline MyQueueIter operator+(int j) const { return MyQueueIter(pm + j); }
    inline MyQueueIter operator-(int j) const { return MyQueueIter(pm - j); }
    inline int operator-(MyQueueIter j) const { return int(pm - j.pm); }  
};