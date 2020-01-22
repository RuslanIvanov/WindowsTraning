#pragma once
enum COLOR { RED, GREEN, BLUE };
class Shape
{
	protected:
	COLOR m_color;
	public:
		Shape(const Shape&);
		Shape(COLOR c = RED);
		virtual ~Shape();
		//  т.к. создаем его объекты , то чисто вирт функцию не вводим  что б не был абстрактным,
		virtual void Inflate(int) = 0 ; 
		virtual int square() = 0;
			
		virtual void WhereAmI();
		virtual void print() = 0; // использовать &os
		virtual Shape* clone()  const = 0;
		virtual bool operator == (const Shape& s) const = 0 { /*сравнить цвет*/ return s.m_color == m_color; };
		virtual bool operator != (const Shape& s) const = 0 { return s.m_color != m_color; };
		//virtual int RemoveAll(const Shape* с) = 0;
		//virtual int RemoveOne(const Shape* с) = 0;

		virtual 
		COLOR getColor() { return m_color; };
		void printColor();
		
};

