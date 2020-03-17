#pragma once
#include <algorithm>
#include <string.h>
#include <iterator>
#include <utility>
#include <initializer_list>
template<typename T>
class MyQueue
{
	T* m_pmass;
	size_t m_n;
	size_t m_cap;
	size_t m_first;
	size_t m_last;
public:
	MyQueue( std::initializer_list<T> );
	MyQueue(size_t n);
	MyQueue();
	~MyQueue();
	void push(const T&);
	T pop();
	void printQueue();

	T* begin() 
	{
		return m_pmass;
	}

	T* end() { return m_pmass + m_n; }
	size_t size() { return  m_n;  }

	friend  std::ostream& operator<< (std::ostream& os, const MyQueue& s)
	{
		for (size_t i = m_first; (i < m_n) && (i < m_last); ++i)
		{
			os << m_pmass[i] << "|";
		}
		return os;
	}
	
};


template<typename T>
MyQueue<T>::~MyQueue()
{
	delete[] m_pmass;
}
template<typename T>
MyQueue<T>::MyQueue() 
{
	m_cap = 10;
	m_n = 0;
	m_first = 0;
	m_last = 0;
	try 
	{
		m_pmass = new T[m_cap];
	}
	catch (std::bad_alloc) 
	{
		m_pmass = nullptr;
		m_n = 0;
		m_cap = 0;
	}
}

template<typename T>
MyQueue<T>::MyQueue(size_t n)
{
	m_cap = 10;
	m_n = n;
	m_first = 0;
	m_last = 0;
	try
	{
		m_pmass = new T[m_cap + m_n];
	}
	catch (std::bad_alloc)
	{
		m_pmass = nullptr;
		m_n = 0;
		m_cap = 0;
	}
}

template<typename T>
MyQueue<T>::MyQueue( std::initializer_list<T> list )
{
	m_cap = 10;
	m_n = list.size();
	m_first = 0;
	m_last = 0;
	try
	{
		m_pmass = new T[m_cap+m_n];

		for (auto& l : list) 
		{
			m_pmass[m_last] = l;
			m_last++;
		}
	}
	catch (std::bad_alloc)
	{
		m_pmass = nullptr;
		m_n = 0;
		m_cap = 0;
	}
}

template<typename T> 
void MyQueue<T>::push(const T& t) 
{

}
template<typename T>
T MyQueue<T>::pop()
{
	return m_pmass[0];
}

template<typename T>
void MyQueue<T>::printQueue()
{
	std::cout << "\nMyQueue is:";

	if (m_n==0 || m_pmass==nullptr)
	{
		std::cout << " EMPTY! "; return;
	}
	
	/*for (const auto& element : m_pmass)
	{
		std::cout << element << ",";
	}//*/

	for (size_t i = m_first; (i < m_n) && (i < m_last); ++i)
	{
		std::cout << m_pmass[i] << ".";
	}
}
