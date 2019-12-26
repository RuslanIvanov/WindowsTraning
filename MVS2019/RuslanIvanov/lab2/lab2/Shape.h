#pragma once
enum COLOR { RED, GREEN, BLUE };
class Shape
{
	COLOR m_color;
	public:
		Shape(const Shape&);
		Shape(COLOR c = RED);
		virtual ~Shape();
		virtual void Inflate(int) {}; //= 0 ;

		COLOR getColor() { return m_color; };
		void printColor();
		virtual void WhereAmI();
		virtual void print() {}//; = 0;
};

