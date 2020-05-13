#pragma once
#include <mutex>
#include <atomic>
#include "spinlock.h"

//enum SINXRO {ATOMIC,MUTEX,SPIN};

template <typename T>
class A
{
	static size_t countA;
	T m_a;
	static std::mutex m;
	static std::atomic<int> a;
	static spinlock s;

public:
	A(T _a = 0)noexcept :m_a(_a) 
	{
		if (m_a == 0) 
		{
			a.fetch_add(1);
			countA = a;
		}

		if (m_a==1) 
		{
			m.lock();
			countA++;
			m.unlock();
		}

		if (m_a == 2)
		{
			s.lock();
			countA++;
			s.unlock();
		}
	}

	static int getCountObj() 
	{
		
		//std::cout << "objects A = "<< countA<<"  ";

		return countA;
	}


};


size_t A<int>::countA;
std::atomic<int> A<int>::a;
std::mutex A<int>::m;
spinlock A<int>::s;

void funcMakeA(int _a);