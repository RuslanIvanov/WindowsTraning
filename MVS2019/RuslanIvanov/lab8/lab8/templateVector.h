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
//#include <vector>
//#include "Point.h"
template <>
void printCont<std::vector<Point*>>(const std::vector<Point*>& p)
{
	std::cout << "\nContainer '" << typeid(p).name() << "' contains:";
	if (p.empty())
	{
		std::cout << "  IS EMPTY!";
		return;
	}
	for (size_t i = 0; i < p.size(); i++)
	{
		if (p[i] == nullptr) continue;
		
		//p[i]->print();
		//std::cout << "\n" << p[i];
		std::cout << "\n" << *p[i];
	}
	
}
