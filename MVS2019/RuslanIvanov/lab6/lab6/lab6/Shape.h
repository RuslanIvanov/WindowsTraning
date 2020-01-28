#pragma once
enum COLOR { RED, GREEN, BLUE, YELLOW, BLACK, WHITE };
class Shape
{
	protected:
	COLOR m_color;
	int m_S;
	public:
		Shape(const Shape&);
		Shape(COLOR c = RED);
		virtual ~Shape();
		//  т.к. создаем его объекты , то чисто вирт функцию не вводим  что б не был абстрактным,
		virtual void Inflate(int) = 0 ; 
		virtual int square() = 0;
		virtual void WhereAmI();
		virtual Shape* clone()  const = 0;
		virtual bool operator == (const Shape& s) const = 0 { /*сравнить цвет*/ return s.m_color == m_color; };
		virtual bool operator != (const Shape& s) const = 0 { return s.m_color != m_color; };
		virtual std::ostream& print(std::ostream& os)=0;
		virtual std::ifstream& read(std::ifstream& in) = 0;
		bool operator<(const Shape& s) const { return m_S < s.m_S;  };

		COLOR getColor() { return m_color; };
		COLOR setColor(COLOR color) {  m_color = color; };
		const char* getColorName();
		void setColorName(const char*);
		
};

