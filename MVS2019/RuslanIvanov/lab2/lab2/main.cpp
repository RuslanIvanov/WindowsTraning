// ����:
// ������� ������������. ����������� �������. ����������� ������.
// ������� ����.


#include <tchar.h>
#include <iostream>
#include "myString.h"
#include "myRect.h"
#include "Circle.h"
#include "Header.h"

#define	  stop __asm nop

int _tmain(int argc, _TCHAR* argv[])
{
	//MyString sss("qqq");
	//sss.GetString()[0] = 'W';// ������ ��� ��� GetString ����� ���������� �� �����
	//������� 1.������ �������� ������.
	{
	//�������� � ������������������ ������ ar �� ��������
	//���� MyString. 
		
	//const int N=3;
	const int N=5;
	MyString str1[N] = {MyString("1 string"),MyString("2 string"),MyString("3 string")};//� ��������� ������ �� �������� ��� 5 N
  
	//�������� - ������ �����-������ ������
	for (int i = 0; i < N; i++)
	{
		if (str1[i].GetString() != nullptr)
		{
			std::cout << "\n#" << i << ": '" << str1[i].GetString() << "'";
		}
		else std::cout << "\n#" << i << " NULL";
	}

	//�������� ������ const int N=5; , �� ������� ������ ���������������.
		

	}
	stop

	//������� 2.������ ���������� �� ������� ������.
	{
	//�������� � ������������������ ������ arPtr �� N
	//���������� �� ������� ���� MyString.
	//const int N=3;
	const int N = 5;
	MyString* arPtr[N] = { new MyString("aaa"), new  MyString("bbb"), new MyString("ccc") }; //NULL, NULL -  ������� �� ������ ������������� �������! - ������ � NULL
	//������ �����-������ ������
	for (int i = 0; i < N; i++)
	{
		if (arPtr[i] != nullptr)
		{
			std::cout << "\n#" << i << ": '" << arPtr[i]->GetString() << "'";
		}
		else std::cout << "\n#" << i << " NULL";
	}

	for (int i = 0; i < N; i++)
	{
		delete arPtr[i];// delete c nullptr �������� ���������
	}
	
   	//�������� ������ const int N=5; , �� ������� ������ ���������������.

	}
		stop


		//������� 3.������� ������������.��������� ������������,
		// ������������ � ������� �����.

		//�������� �������� �������:
		//������� ����� Shape (������� ��������� ����� ������)
		//� ��� ����������� ������ Rect � Circle.
		//���������: ����� ������ � ������ ����� ������ � �������
		//� ����������� ������ (��������, ����� ������ ����� �������
		//������� => � ������� ������ ����� ������ ����������, �������
		//����� ���������� ���� ������.
		//���������: ��� �������� ����� �������� ������������ (RED,GREEN,BLUE...);


		//� ������������� ����������� ������� ������������� ��������
		//���������-����� ������������ �������� ������.
		//��� �������� � ����������� ������� ������������ ���� ����������
		//������������������ ������� ������������� � ������������ ��������
		//� ������������ �������
	{
		Rect rA;// ��������� ����������� ��������, ����� ������������
		Rect rB(1,2,4,5,BLUE);  // ����������� c ����������� ��������, ����� ������������
		Circle cA;
		Circle cB(GREEN);
		rA.printColor();
		rB.printColor();
		cA.printColor();
		cB.printColor();
	}//�����. ������������, ����� �������� ()
	stop
//////////////////////////////////////////////////////////////////////

	//������� 4.����������� �������.
	//4�) ������������� ������ Shape,Rect � Circle:
	//�������� � ������ ����� public ����� void WhereAmI().
	//���������� ������ ������� ������ �������� ��������� 
	//���������� ���� "Now I am in class Shape(Rect ��� Circle)".
	//��������� ����������� ��������, ��������� ���������.

	//4�) �������� ����� WhereAmI() �����������.
	//����� ��������� ����������� ��������, ��������� �������.

	{
		Shape s(BLUE);
		Rect r(1,2,5,9);
		Circle c(GREEN);

	
		//����� ������ ������ ���������� � ��������� ��������???
		s.WhereAmI();	//	����������� ������� ���������� �����. ����� ������
		r.WhereAmI();	//	����������� ������� ���������� �����. ����� ������
		c.WhereAmI();	//	����������� ������� ���������� �����. ����� ������
		stop


		Shape* pShape = &s; // ����� Shape � ��������
		Shape* pRect = &r; // ������ . �������� ����� ������ � ��������
		Shape* pCircle = &c; // ������ . �������� ����� ������ � ��������
    	pShape->WhereAmI();	//	����������� ��������� ����. ������� ����� ������ ��. Shape 
		pRect->WhereAmI();	//	����������� ��������� ����. ������� ����� ������ ����������� ��. Rect
		pCircle->WhereAmI(); //	����������� ��������� ����. ������� ����� ������ ����������� ��. Circle

		stop


		//��������� ... �������� ������������
		Shape& rShape = s; //��������� s
		Shape& rRect = r; //��������� r, �������� ������. ����� � ��������
		Shape& rCircle = c; //��������� c, �������� ������. ����� � ��������
		rShape.WhereAmI();	//����������� ��������� ����. ������� ����� ������ ��. Shape 
		rRect.WhereAmI();	//����������� ��������� ����. ������� ����� ������ ����������� ��. Rect
		rCircle.WhereAmI(); //����������� ��������� ����. ������� ����� ������ ����������� ��. Circle
		//*/
		stop
			
	}
		stop
//////////////////////////////////////////////////////////////////////

	//������� 5.����������� �����������.
	//������������� ������:
	//a) ������� ���������������
	// ����������� (��� ��������� ����� virtual).
	//���������� ������� �����������
	//������ �������� ��������� ���������� ����
	// "Now I am in Shape's destructor!" ���
	// "Now I am in Rect's destructor!"
	//��������� ��������. ��������� ���������.

	//���: c virtual ����������
	// ����� ������������ �� ����. ������ ������� �, ����� ��� ������� ����� s, 
	// ����� ������������ �� ����. ������ ������� r, ����� ��� ������� ����� s
	// ����� ����������� �������� ������ s

	stop
	// b) �������� � ���������� ������������ �������� ����� virtual 
	//��������� ��������.��������� �������.

	//���: ��� virtual �����
	//���������� ����� ����� ����� ��� � � ��������� ����, ��� ������� r,c,s �� ������������ (�� �����  ��������� �������� ������������ � �������)
	
	stop
	//���������: ����� ������������ ���������� � ��������� ������?
		//���� � ������������� ������� �����-�� �������������
		//�� ������� - ����������
		//���� �� ��������, ��� � ����������� ��������� ����-��
		//�� ������� - ��������

		Rect r(1,20,3,40,RED);
		Shape* ar[]={new Shape(r), new Rect(r), new Circle(r)/*??*/, new Circle() };
		//�������� ��� ������� �������� ������� ����� WhereAmI()
	
		for (int i = 0; i < sizeof(ar) / sizeof(ar[0]); i++)
		{
			ar[i]->WhereAmI();
			ar[i]->print();
		}
		stop
		for (int i = 0; i < sizeof(ar) / sizeof(ar[0]); i++)
		{
			delete  ar[i];// ��� ��� �����.  ����. � ������� ����. ����������� �� ���������� ������ ����� ������������, ����� ��������
		}
		stop
	//������� 6*. � ��� ����������� ������� 1) � 2)
	{
		Shape* pShapes = new Rect[10];//1)������ ���������� �� ������� ��
		Rect* pRects = new Rect[10];//2)������ ���������� �� ����������� ��

		//1)  ������ ���������� �� 10 ��. � ������ �������� ��� sizeof(Rect)*10, ����������� �� ���������
		//2) ---//---

		//���������� ������� ����� WhereAmI() ��� ������� �������� ����� �������� -
		//� ��� ����������� ��������???
		//�������� � ��� ��� ������������������ ������ 1 ������� �������

		Shape* pS = pShapes;
		Rect* pR = pRects;
		for (int i = 0; i < 10; i++)
		{
			if (pS != nullptr)
				pS->WhereAmI(); // ����� ������ ��� ��������� ���. ����. ����. => rect 
			stop
			if (pR != nullptr)
				pR->WhereAmI();// ����� ������ ��� ��������� ���. ����. ����. => rect
			stop

			pS = pR++;//����� ��������� �� ����������� ���� ������ � ������. �������� ��� � ���. �� �������
			
			stop
		}
		stop
		//���������� ����������� ����������� ������
	
		delete  [] pShapes; // ����������� �������, �������  �������� Rect*10, ����� ����������� ��� ������� �������� �������
		delete  [] pRects; // --//-- ����� ����������� ��� ������� �������� �������
		
		stop
	}

//*/

//////////////////////////////////////////////////////////////////////

	//������� 7.����������� ������� � �������� ���������� ������� ���������. 

	{
		Rect r(1,2,3,4,GREEN);
		Shape* p = &r;	
		p->WhereAmI();//����� ������  ��. Rect � ������� ���. ���. ����.
		stop

		//4a �������� ���������� ������� ���������.
		//����������� ������� r � ��������� p �������� ����������� �������
		//WhereAmI()������ Shape

		r.Shape::WhereAmI(); // �� ����� ���������� ���� ������� ����������� ��� �������, ����� ��� �������_� �������
		p->Shape::WhereAmI(); // ���� ������� ��� �������� ����������� �� ����� ������. ��� ��������, ��� ���. ���� �������.
		stop	
	}
//*/

//////////////////////////////////////////////////////////////////////

	//������� 8.����� ����������� �������. 
	//������� � ������� ����� ����� void Inflate(int); ���������:
	//����� �� ����������� ����� ����� ��� �������� ������? => ��� ��� ����� ��������.
	//���������� ���� ����� ��� ����������� �������.
	{//���� ���:  virtual void Inflate(int) �.�. ���. ��������� �� ������� ��.
		Rect r(3,4,5,6,BLUE);
		Shape* p = &r;
		p->Inflate(5);
		Circle c(2,3,10,RED);
		p = &c;
		p->print();
		stop
		p->Inflate(5);
		p->print();
		p->printColor();
		stop
	}
//*/


//////////////////////////////////////////////////////////////////////
	//������� 9. �������� ���������� �������, ������� ����� ��������� �����
	//���������� ���������� �� ������, � ���������� ������ MyString,
	//� ������� ������ ����� ������������� ����������
	const char* pstr1 = "one";
	const char* pstr2 = "two";
	const char* pstr3 = "three";
	MyString strs = ApplyString(pstr1, pstr2, pstr3,0);
	std::cout<<"\nrez: "<<strs.GetString();
	stop
////////////////////////////////////////////////////////////////////////

	//������� 10.����������� (union) C++. ������� ����.
	//1.
	//�������� ��������� ������ ��� ��������� ������������� �������� �����:
	//Bin - ��� ��������� �������������
	//Hex - ��� ����������������� �������������
	//Oct - ��� ������������� �������������.
	//��������� 1: - ��� �������� ����������� ������� ����.
	//��������� 2: - ������������� � ����� ��������������� ������� ���� �� ������,
	//��� ��� ��� ��� ����� ������� ����������� (union).
	//2.
	//� ������ ������ ������� ����� Show, ������� ������ �������� �������� �
	//��������������� ����
	//3.
	//����������� ����������� MyByte ������������ ������������ ����������� ��������������
	//����� � ��� �� ��������� ��-�������:
	//�) ��������: ����������, �����������������, ������������, �������� �������� ����� 
	//          � ����� ������, ��������������� ��������� �������� (���� ���� ������������);
	//�) �������� ��������� (��������� ����������� ���������) �����������������,
	//			������������, �������� �����;
	//�) �������� ��������� ��������, ������������ ��� ����������������� �����;

	//MyBytes byte(0x1f);
	//MyBytes byte('c');
	MyBytes byte(1);

	byte.ShowHex();
	byte.ShowBin();
	byte.ShowChar();
	byte.ShowOct();
	stop
	//...
	byte.ShowBinPos(1);
	byte.ShowHexPos(1);
	byte.ShowOctPos(1);

	byte.ShowBinPos(2);
	byte.ShowHexPos(2);
	byte.ShowOctPos(2);

	byte.EditBin(2, 1);// � ��������� � ����� � ��� �� ������� ������! 
	byte.ShowBin();
	byte.EditHex(2, 0x6);
	byte.ShowHex();
	byte.EditOct(2, 4);
	byte.ShowOct();
	//...
	return 0;
}//endmain

