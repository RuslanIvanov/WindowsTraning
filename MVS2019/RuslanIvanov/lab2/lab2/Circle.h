#pragma once
#include "Shape.h"
#include "myRect.h"

class Circle: public Shape
{
	int m_D;
	int m_x0;
	int m_y0;

	public:
		Circle(COLOR c = RED);
		Circle(const Circle&);
		Circle(const Rect&) {};
		virtual ~Circle();	
		virtual void WhereAmI();
};
