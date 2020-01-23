#include <iostream>
#include "Circle.h"

Circle::Circle(int x, int y, int D,COLOR c):m_Point(x, y),Shape(c)
{
	m_D = D;
	m_x0 = x;
	m_y0 = y;

	square();
}

Circle::Circle(const Circle& r):m_Point(r.m_x0,r.m_y0),Shape(r)
{
	m_D = r.m_D;
	m_x0 = r.m_x0;
	m_y0 = r.m_y0;
	m_S = r.m_S;
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

bool Circle::operator == (const Shape& c) const
{
	const Circle* pR = dynamic_cast<const Circle*>(&c);
	if (pR == 0) return false;

	if (pR->m_D == m_D && pR->m_x0 == m_x0 && pR->m_y0 == m_y0 && m_Point == pR->m_Point && Shape::operator==(c) ) // и цвет сравнить так  Shape::operator==(c) (т.е. явно вызвать оператор==() базового),  иначе будет бесконечная рекурсия т.к. будет вызоваться текущий Circle::operator == (const Shape& c) const
																												//Shape::operator==(c) 	- отмена полиморфизма
		return true;
	else
		return false;

}

bool Circle::operator !=(const Shape& c) const
{
	return	!operator==(c);
}

std::ostream& Circle::print(std::ostream& os)
{
	os << "\nCircle:";  os << " color " << getColorName() << "\n";
	os << "x = " << m_x0 << " y = " << m_y0 << "";
	os << "D = " << m_D << "\nS = " << m_S << "\n";
	return os;

}

int Circle::square() 
{
	//std::cout << "\nCircle S = ";
	m_S = 3.14 * (m_D / 2);
	//std::cout << m_S;
	return 0;
}

Shape* Circle::clone() const
{
	return new Circle(*this);
}

std::ostream& operator<<( std::ostream& os, const Circle& c)
{
	os << "x = " << c.m_x0 << " y = " << c.m_y0 << " ";
	os << "D = " << c.m_D << "";
	return os;
}

