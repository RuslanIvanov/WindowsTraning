//����������

//�������: 
	//		������� �������,
	//		������� �������,

#include <tchar.h>
//#include <stdexcept>
#include "templ.h"
#include "MyString.h"
#include "MyStack.h"

#define stop __asm nop

int _tmain(int argc, _TCHAR* argv[])
{
	
	
	////////////////////////////////////////////////////////////////////////////
	//����. ������� �������.
	//�������� ������ ������� ������������ ������� ����
	//�������� - Swap(). ��������� ����������������� ����������
	//������� � ������� ������������ ���� ��������� ����.
	//��������� 1: ���������� ������� ���������� ��������� � .h-����.

	int iX = 1, iY = -1;
	Swap(iX, iY);

	stop

	double dX = 0.5, dY = -5.5;
	Swap(dX, dY);

	stop
	//��������� 2: ���������, ��� ����� �����������, ��� ����,
	//			����� ��������� ����� ������� � ��������� MyString
	//			�� ������ ���������, �� � ����������
	MyString str1("One"), str2("Two");
	Swap(str1, str2);
	stop
		//*/
		/////////////////////////////////////////////////////////////////////

			//����. ������� �������.
			//������� 1.
			//�������� ������ ������ MyStack ��� �������� ��������� ������ ���� T.
			//���������: 1.�������� ����� ���-�� ������� - ������� � ������� ���������
			//			��� �������� ��������������� ������������� � ������ ���������
			//			�������� ������, 
			//			2.��� ������� ������������� ������� ����� ����� ���� �����������
			//			��������-��������� �������
			//			3.������������� ���������� �� ������ �������� "push" � "pop". ���
			//			����, ����� ������������� ���������� ���������� ���� �������� 
			//			������ ���� �� ������������ ���������� � ��������� ��������
			//			4. ������������� ���������� operator[] ����� �������, ����� ������������
			//			��� ������/�������� �������� ������ ��� ���������, ������� �� ����������


			//� ������� ������� MyStack �������� ���� �� 5 ��������� int - iStack �
			//���� �� 10 ��������� MyString - strStack � ������������������� � ���������
			//push() � pop(), operator[]

		MyStack <int>st(5);
		st.pop(1);
		st.pop(2);
		st.pop(4);
		st.pop(3);

		int i;
		st.push(i)



	//������� 2. ���������� ������ ����� - MyStack2 ����� �������, ����� 
	//��� �������� ��������� ������������� ����������� ������.
	//���������� ����������� ����������� �������� ����� � ��� �������, � ������� �� ������� (push())
	//������������






	

	return 0;
}

