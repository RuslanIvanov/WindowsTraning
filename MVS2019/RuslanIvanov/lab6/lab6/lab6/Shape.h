#pragma once
enum COLOR { RED, GREEN, BLUE };
class Shape
{
	protected:
	COLOR m_color;
	int m_S;
	public:
		Shape(const Shape&);
		Shape(COLOR c = RED);
		virtual ~Shape();
		//  �.�. ������� ��� ������� , �� ����� ���� ������� �� ������  ��� � �� ��� �����������,
		virtual void Inflate(int) = 0 ; 
		virtual int square() = 0;
			
		virtual void WhereAmI();
		//virtual void print() = 0; // ������������ &os
		virtual Shape* clone()  const = 0;
		virtual bool operator == (const Shape& s) const = 0 { /*�������� ����*/ return s.m_color == m_color; };
		virtual bool operator != (const Shape& s) const = 0 { return s.m_color != m_color; };
		virtual std::ostream& print(std::ostream& os)=0;
		bool operator<(const Shape& s) const { return m_S < s.m_S;  };

		//virtual int RemoveAll(const Shape* �) = 0;
		//virtual int RemoveOne(const Shape* �) = 0;

		virtual 
		COLOR getColor() { return m_color; };
		void printColor();
		
};

