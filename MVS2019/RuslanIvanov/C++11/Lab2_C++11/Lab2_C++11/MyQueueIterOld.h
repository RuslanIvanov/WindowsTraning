#pragma once
#include <iterator>
#include "MyQueue.h"

template <typename T> class MyQueue;

template <typename T>
class MyQueueIter
{
   
public:
  
    T* pm;
 
    inline MyQueueIter() : pm(nullptr) {}
    inline MyQueueIter(T* t) : pm(t) {}
    inline MyQueueIter(const MyQueueIter& r) : pm(r.pm) {}

    inline MyQueueIter begin() { return &MyQueue<T>::m_pmass[MyQueue<T>::m_first];    }
    inline MyQueueIter end() { return  &MyQueue<T>::m_pmass[(MyQueue<T>::m_first + MyQueue<T>::m_n) % MyQueue<T>::m_cap];     }
    inline MyQueueIter begin() const { return   &MyQueue<T>::m_pmass[MyQueue<T>::m_first]; }
    inline MyQueueIter end() const { return  &MyQueue<T>::m_pmass[(MyQueue<T>::m_first + MyQueue<T>::m_n) % MyQueue<T>::m_cap]; }
    inline T& operator*() const { return MyQueue<T>::m_pmass; }
    inline T* operator->() const { return MyQueue<T>::m_pmass; }
    // inline T& operator[](int j) const { return i[j].t(); }
     //inline bool operator==(const MyQueueIter& o) const { return i == o.i; }
    // inline bool operator!=(const MyQueueIter& o) const { return i != o.i; }
    // inline bool operator<(const MyQueueIter& other) const { return i < other.i; }
    // inline bool operator<=(const MyQueueIter& other) const { return i <= other.i; }
    // inline bool operator>(const MyQueueIter& other) const { return i > other.i; }
    // inline bool operator>=(const MyQueueIter& other) const { return i >= other.i; }

    inline MyQueueIter& operator++() { MyQueue<T>::m_first++;  return MyQueue<T>::m_pmass[(MyQueue<T>::m_first + MyQueue<T>::m_n) % MyQueue<T>::m_mcap]; }// return *this;

    //  inline MyQueueIter operator++(int) { Node* n = i; ++i; return n; }
     // inline MyQueueIter& operator--() { i--; return *this; }
     // inline MyQueueIter operator--(int) { Node* n = i; i--; return n; }
    //  inline MyQueueIter& operator+=(int j) { i += j; return *this; }
     // inline MyQueueIter& operator-=(int j) { i -= j; return *this; }
     // inline MyQueueIter operator+(int j) const { return MyQueueIter(i + j); }
      //inline MyQueueIter operator-(int j) const { return MyQueueIter(i - j); }
     // inline int operator-(MyQueueIter j) const { return int(i - j.i); }
};