#pragma once
#include <algorithm>
#include <string.h>
#include <iterator>
#include <utility>
#include <initializer_list>
#include <iostream>
#include <functional>
#include <condition_variable>
#include <mutex>
#include <atomic>

#define SIZE_QUEUE 10
class MyQueue
{
   
	char m_pmass[SIZE_QUEUE];
  
    size_t m_n;
    size_t m_cap;  
	size_t m_first;
	size_t m_last;
    bool m_bClear;
    bool m_bInsert;

    mutable std::mutex m; 
    mutable std::mutex m2;
    std::condition_variable m_cvInsert;
    std::condition_variable m_cvClear;
    static std::atomic<int> m_stopAll;
   
    const size_t MAX_SIZE = SIZE_QUEUE;
  
public:

	MyQueue( std::initializer_list<char> );
	MyQueue(size_t n);
	MyQueue(size_t n, const char& );
	MyQueue();
	~MyQueue();

	MyQueue(const MyQueue&) = delete;
	MyQueue(MyQueue&&);
	MyQueue& operator=(const MyQueue& ) = delete;
	MyQueue& operator=(MyQueue&&);
           
   	void push(const char&);
	char pop();

	void printQueue();
    void printQueueRaw();

    static void stopQ();
   // работает
   
   char* begin()
   {
       std::lock_guard<std::mutex> lm(m2);
       size_t l = ((m_first + m_n) % m_cap);
       if (m_first < l)
           return &m_pmass[m_first];
       else
           return m_pmass;
   }
   char* end()
   {
       std::lock_guard<std::mutex> lm(m2);
       size_t l = ((m_first + m_n) % m_cap);
       if (m_first < l)
           return &m_pmass[(m_first + m_n) % m_cap];
       else
           return m_pmass + m_n;
   }//*/

    size_t size() { return  m_n;}
    bool isEmpty() { return  (m_n==0); }
    size_t capacity() { return m_cap;}

 
	friend  std::ostream& operator<< (std::ostream& os, const MyQueue& s)
	{
        for (size_t i = s.m_first; (i < s.m_n); ++i)
		{
             os << s.m_pmass[i%s.m_cap] << "";
		}
		return os;
	}
	
};

void fWritersQ(MyQueue& s, char el);
void fReadersQ(MyQueue& s);