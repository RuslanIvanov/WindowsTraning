#pragma once
#include <iterator>
#include "MyQueue.h"

template <typename T> class MyQueue;

template <typename T>
class MyQueueIter
{
    T* pm;
    size_t f;
    size_t l;
    size_t n;
    size_t cap;
public:

    typedef T value_type;
    typedef T* pointer;
    typedef T& reference;
 
    inline MyQueueIter() : pm(nullptr) { l = f = 0; n = 0; cap = 0; }
    inline MyQueueIter(T* t) : pm(t) { l = f = 0; n = 0; cap = 0; }
    inline MyQueueIter(const MyQueueIter& r) : pm(r.pm)
    {
        cap = r.cap;
        l = r.l;
        n = r.n;
        f = r.f;
    }

    inline T& operator*() const { return *pm; }
    inline T* operator->() const { return pm; }

    inline T& operator*()  
    { 
        return *pm; 
    }
    inline T* operator->() 
    { 
        return pm; 
    }

    inline T& operator[](int j) const { return pm[j]; }
    inline bool operator==(const MyQueueIter& o) const { return pm == o.pm; }
    inline bool operator!=(const MyQueueIter& o) const { return pm != o.pm; }
    inline bool operator<(const MyQueueIter& other) const { return pm < other.pm; }
    inline bool operator<=(const MyQueueIter& other) const { return pm <= other.pm; }
    inline bool operator>(const MyQueueIter& other) const { return pm > other.pm; }
    inline bool operator>=(const MyQueueIter& other) const { return pm >= other.pm; }

    inline MyQueueIter& operator++() 
    { 
       
        size_t ind1 = m_first % m_cap;
        // pm++;
        pm += ind1;
        return *this; 
    }
    inline MyQueueIter operator++(int) { T* n = pm; ++pm; return n; }
    inline MyQueueIter& operator--() { pm--; return *this; }
    inline MyQueueIter operator--(int) { T* n = pm; pm--; return n; }
    inline MyQueueIter& operator+=(int j) { pm += j; return *this; }
    inline MyQueueIter& operator-=(int j) { pm -= j; return *this; }
    inline MyQueueIter operator+(int j) const { return MyQueueIter(pm + j); }
    inline MyQueueIter operator-(int j) const { return MyQueueIter(pm - j); }
    inline int operator-(MyQueueIter j) const { return int(pm - j.pm); }  
};