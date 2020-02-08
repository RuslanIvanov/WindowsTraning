#pragma once
#include <iostream>

template <typename T> void printParamCont(const T& t)
{
	std::cout << "\n------------------------------------------------";
	std::cout << "\n name: " << typeid(t).name();
	std::cout << "\n size: "<< t.size();
	std::cout << "\n capacity: " << t.capacity();
	std::cout << "\n max_size: " << t.max_size();
	std::cout << "\n------------------------------------------------";
}

template <typename P> void printCont(const P& p)
{
	std::cout << "\nContainer '"<< typeid(p).name() << "' contains:";
	if (p.empty())
	{
		std::cout << "  IS EMPTY!";
		return;
	}

	for (size_t i = 0; i < p.size(); i++)
	{
		std::cout << "\n" << p[i];
	}
}

class Point;

template <typename T>
 void printCont<Point*>(vector<T>& p)
{
	for (size_t i = 0; i < p.size(); i++)
	{
		std::cout << "\n" << *p[i];
	}
	
}
