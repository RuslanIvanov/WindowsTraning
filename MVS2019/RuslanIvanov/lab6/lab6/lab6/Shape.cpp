#include <iostream>
#include "Shape.h"

Shape::Shape(COLOR c)
{
	m_S = 0;
	m_color = c;
	std::cout << "\nI am in Shape's constr!";
}

Shape::Shape(const Shape& r)
{
	m_S = r.m_S;
	m_color = r.m_color; //доступ к privat того же тип объекта разрешен
	//r.m_color = RED; - нельзя т.к. const
	std::cout << "\nI am in Shape's constr copy!";
}

Shape::~Shape()
{
	std::cout << "\nNow I am in Shape's destructor!";
}

const char* Shape::getColorName() 
{
	switch (m_color)
	{
		case RED:return		"RED";
		case GREEN:return	"GREEN";
		case BLUE:return	"BLUE";
		case YELLOW:return	"YELLOW";
		case BLACK:return	"BLACK";
		case WHITE: return  "WHITE";
		default: return "";
	}
}

void Shape::WhereAmI()
{
	std::cout << "\nNow I am in class Shape";
}