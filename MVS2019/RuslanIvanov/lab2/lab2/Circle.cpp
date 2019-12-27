#include "Circle.h"
#include <iostream>

Circle::Circle(COLOR c):Shape(c)
{
	m_D = 0;
	m_x0 = 0;
	m_y0 = 0;
}

Circle::Circle(int x, int y, int D,COLOR c):Shape(c)
{
	m_D = D;
	m_x0 = x;
	m_y0 = y;
}

Circle::Circle(const Circle& r):Shape(r)//где Shape(r) - указание компилятору вызвать констр. копирование базового кл.
{
	m_D = r.m_D;
	m_x0 = r.m_x0;
	m_y0 = r.m_y0;
	std::cout << "\nI am in Circle's constr copy!";
}

Circle::~Circle()
{
	std::cout << "\nNow I am in Circle's destructor!";
}

void Circle::WhereAmI()
{
	std::cout << "\nNow I am in class Circle";
}

void Circle::Inflate(int d) 
{
	std::cout << "\nCircle::Inflate";
	m_D += d;
}

void Circle::print()
{
	std::cout << "\nCircle:\n";
	std::cout << "x = " << m_x0 << " y = " << m_y0 << "\n";
	std::cout << "D = " << m_D << "";
}

Circle::Circle(const Rect& rr)
{ 
	int l, t, r, b, H, W;
	l = r = t = b = H = W = 0;
	
	rr.GetAll(&l,&r,&t,&b);

	H = b - t;
	W = r - l;

	if (W > H)
	{ 
		m_D = H;
	}
	else 
	{ 
		m_D = W; 
	}

	m_x0 = W / 2.;
	m_y0 = H / 2.;
};