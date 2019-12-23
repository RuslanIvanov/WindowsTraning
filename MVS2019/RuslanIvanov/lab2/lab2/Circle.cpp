#include "Circle.h"
#include <iostream>

Circle::Circle(COLOR c):Shape(c)
{
	m_D = 0;
	m_x0 = 0;
	m_y0 = 0;
}

Circle::Circle(const Circle& r):Shape(r)
{
	m_D = r.m_D;
	m_x0 = r.m_x0;
	m_y0 = r.m_y0;
}

Circle::~Circle()
{

}

void Circle::WhereAmI()
{
	std::cout << "\nNow I am in class Circle";
}
