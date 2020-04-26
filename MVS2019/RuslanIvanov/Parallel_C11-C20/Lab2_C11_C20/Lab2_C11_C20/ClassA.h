#pragma once
#include <iostream>
#include <sstream>
#include <mutex>

class ClassA
{
	static size_t m_count;// на этапе компил
	static thread_local size_t m_countInTh;//на этапе выполнения для каждого потока
	std::string m_name;
	static std::mutex m;
public:
	ClassA();
	~ClassA();

	static size_t getCount() { return  m_count; }
	static size_t getCountInTh() { return  m_countInTh; }
	void printName() { std::cout<<"\nclass: "<<m_name; }

	static void lock() 
	{
		m.lock();
	}

	static void unlock()
	{
		m.unlock();
	}
};


//func
size_t funcMakeA(const std::string, unsigned int );
