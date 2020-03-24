#pragma once
#include <vector>
#include <algorithm>
#include <string.h>
#include <iterator>
#include <utility>
#include <initializer_list>

template<typename T>
class MyUniquePTR
{
	//T* m_p;
	T* m_p = nullptr;

	protected:
		MyUniquePTR(const MyUniquePTR&) = delete; //{}
		MyUniquePTR& operator=(const MyUniquePTR&) = delete; //{ return *this; }

	public:
	
	MyUniquePTR(MyUniquePTR&& r)
	{ 
		m_p = r.m_p; 
		r.m_p = nullptr; 
	}

	MyUniquePTR& operator=(MyUniquePTR&& r)
	{ 
		if(this==&r) return *this; 		

		delete [] m_p;

		m_p = r.m_p; 
		r.m_p = nullptr;
		
		return *this; 
	}

	//MyUniquePTR(){ m_p = nullptr; }
	MyUniquePTR() { }
	MyUniquePTR(T* p):m_p(p){}
	~MyUniquePTR(){delete m_p;}

	T* get() const { return m_p; }
	T* operator->() const { return m_p; }
	T& operator*()  const { return *m_p; }

	explicit operator bool() const noexcept
	{
		//if(get()==nullptr) return false;
		if (m_p == nullptr) return false;
		else return true;
	}
};
