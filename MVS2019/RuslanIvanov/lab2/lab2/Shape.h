#pragma once
enum COLOR { RED, GREEN, BLUE };
class Shape
{
	COLOR m_color;
	public:
		Shape(const Shape&);
		Shape(COLOR c = RED);
		virtual ~Shape();

		COLOR getColor() { return m_color; };
		void printColor();
		virtual void WhereAmI();
};

