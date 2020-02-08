//����������� ���������� �������� - STL 
	//���������� ����������� ���������� - vector
	//���������

#include <iostream>
#include <vector>
#include "templateVector.h"
#include "MyString.h"
#include "Point.h"

#pragma warning(disable: 4786)


using namespace std;	

#if  _WIN32 
#define	  stop __asm nop
#else

void mystop()
{//Linux
	std::cout << "\nPause\n";
	getchar();
}

#define  stop  {mystop();}
#endif

int main(int arg, char** parg)
{
	// ��������� ����������� ���������� vector 

//////////////////////////////////////////////////////////////////////
	//�������� ��������. 

	//�������� ��������� �������:
	//---------------------------
	//������ ������ ����� ����� - vInt � ��������� � ������� ������� size(),
	//��� ��� ������ �������. 

	std::vector<int> vInt;
	std::cout << "\nsize Vint: " << vInt.size();
	stop
		//���������������� ��������� ��������, ��������� - ��� �� ���������
		//���� ���� ��������������, - ���������

	vInt.push_back(1);//��������� ������� � ����� �������
	std::cout << "front " << vInt.front(); //���������� ������ �� ����� ������ �������
	//vInt.front()=2;
	stop

		//� ������� ������� push_back() � ����� ��������� ������ ������-���� ����������.
		//�� ������ �������� ����� ������� �� �������� ������� � ������� �������
		//size(), capacity(), max_size() � �������� �������� ���������. 
		//
		//���������: ��� ��� ����� �������� ����������� ��� � � ��������� ��������,
		//�������� ������ �������, ������� ��� �������, ����������� �������� ������ ����
		//������� ��� "���������" � �������� ��������� �� �������.

	for (int i = 0; i < 10; i++)
	{
		vInt.push_back(i+1);
		printParamCont(vInt);
		stop
	}

	printCont(vInt);
	
	stop

	//������ ������������ - vDouble1 � �������� ���� ��������� ��������  �
	//��������� ��������� � ������� ���������� ���� �������. ��� �����
	//������������������� �������� �������?

	vector<double> vDouble1(10);

	printParamCont(vDouble1);
	printCont(vDouble1);
	stop
		//������ �������� ���� MyString � ��������� �������� - 5 ���������
		//� �������������� ������� �������� ������� "A"
		//C ������� ������� at() � ����� � ������� ���������
		//�������������� []  �������� �������� �����-���� ���������.
		//���������� "�����" �� ������� ������� � ������� at() �
		//� ������� []. 

	vector<MyString> vStr(5, "A");
	printCont(vStr);
	stop

		//������ ������������ - vDouble3, ������� �������� ������ ���������
		// [0,5) ������� ������������ ����� dMas. �������������� ������ dMas 
		//����� ������� � �������������������!
		double dMas[] = { 0,1,2,3,4,5 };
		vector<double> vDouble3(dMas, dMas + (sizeof(dMas)/sizeof(dMas[0])));
		printCont(vDouble3);
		stop

		vector<double> vDouble33;
		for (size_t i = 0; i < sizeof(dMas) / sizeof(dMas[0]); i++)
		{
			vDouble33.insert(vDouble33.begin() + i, 1, dMas[i]);//��������� ����� �������� �� ��������� [i,j) ����� ��. �� �����. ����. ��������
		}

		printCont(vDouble33);
		stop
		vector<double> vDouble333(6);
		vDouble333.insert(vDouble333.begin()+1,4,5.);//������� 4 ������� [1,5)
		printCont(vDouble333);
		stop
			
		//������ ������������ - vDouble4, ������� �������� ������ ���������
		// [2,5) ������� vDouble3. 

		vector<double> vDouble4(vDouble3.begin() + 2, vDouble3.begin() + 6);

		printCont(vDouble4);
		stop


			//������ ��������� ���� Point - vPoint1 �) � ��������� �������� 3. ����� �����������
			//����� ������ ��� ������� ��������?
			//b) vPoint2 � ��������� �������� 5 � ������������������ ������ ������� ������������ (1,1).

		vector<Point> vPoint1;// ������ ����� ���������� ������
		printCont(vPoint1);
		stop

		vector<Point> vPoint2(5, Point(1, 1));
		printCont(vPoint2);
		stop
		//������ ���������� �� Point - vpPoint � ��������� �������� 5
		//���������: ��� ��������� ��������� ��� ��������� "���������" �� ������� Point
		{
			vector<Point*> vpPoint(5,nullptr);
			vector<Point*> vpPoint2(5,new Point(0,0));
	
			for (size_t i = 0; i < 5/*vpPoint.size()*/; i++)// � vpPoint.size() ���������� ����������� ����!!
			{
				vpPoint.insert(vpPoint.begin() + i,new Point(i,i));
			}

			printCont<>(vpPoint);
			printCont(vpPoint2);
		stop
		//���������: ��� ������ �� ������ �������� ������ ����� ��� �����������
		//�) ������������� ����� ��������� �������
		//�) ��� ���������� operator<< ��� Point*

			for (size_t i = 0; i < 5; i++)
			{
				delete vpPoint[i]; vpPoint[i] = nullptr;
				delete vpPoint2[i]; vpPoint2[i] = nullptr;
			}
	
	}//����� �������������� �������� ����� ����������� ��� ������ �������?

	stop
	///////////////////////////////////////////////////////////////////////
	//�������������� ������.
	//���������, ������ �� ����� ����������� ���� ��������?
		/*
		{
		size_t n=...
		vector<int> v(n);
		v.resize(n/2);
		if(v.capacity() == n) //true?
		}
		*/

		/*
		{
		int n=...
		size_t m=...	
		vector<int> v(n);
		v.reserve(m);
		if(v.capacity() == m) //true?
		}
		*/

		/*
		{
		vector<int> v(3,5);
		v.resize(4,10); //��������?
		v.resize(5); //��������?
	
		}
		*/

	//�������� ��� "������" ������� � ����������
	//������ (�� ������ � ���� �� ����) ����. 
	//� ������ ������� �������������� ������ ��� 5 ���������, � ����� ���������
	//��� ���������� � ������� push_back.
	//������ ������ ������ ��������� ���������� ����������� push_back.
	//
	//�������� ������, ������� �������� � �������� ���������



	



	//!!! shrink_to_fit - ���������� ������� �������.
	//��� ������ ������� �� ����������� ������� ��������� ��������� �������
	//�� size.

	
	

	//�������� "����������� �������" - ������� ��������
	//����� ���������� ������ int ar[] = {11,2,4,3,5};
	//�������� ������ �������� ��������� �������:
	//������ vv[0] - �������� 11 ��������� �� ��������� 11
	//vv[1] - �������� 2,2
	//vv[2] - �������� 4,4,4,4
	//...
	//������������ ���������� ������ ����������� ������� �� �������
	
	 stop

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	//������� �������� ������������������ insert().
	//� ������ vChar2 �������� � ������ ������� ������ ������ ���
	//�������, ��� � ������� ������ ��� ���.


	
	//�������� ����� ������ ��������� ������� vChar2 ����� 'W'
	


///////////////////////////////////////////////////////////////////
	//�������� �������, ������� ������ ������� ������ ������������� ������������������.
	//��������: ���� - "qwerrrrty12222r3", ����� - "qwety1r3"




	stop

///////////////////////////////////////////////////////////////////

	//�������� �������� ������������������ erase()
	//�������� ������� �������� �� ������ ������� ���� ������ 



	

///////////////////////////////////////////////////////////////////
	//�������� ����� ������ ����� �������, ����� ��� �������� �����
	//������� ��������� ������ �� ��������� ����� ��������, �� �����������
	//���� �� � �������� �������






///////////////////////////////////////////////////////////////////

	//������� 1. ������. ��������, ����������� ��� �������.
	//�������� ������ ������ �� ��������� Point - ptList1 � ���������
	//��� ���������� � ������� ������� push_back(),
	//push_front, insert()
	

	//�������� ������ �������, ������� ����� �������� ��������
	//������ ���������� �� ������. ��������� ������ ������� �� �����������
	//vector � list. ��������� - �������� �� ������� ��� ����������.


	//�������� ����� �� ������� "�����������" - reverse()


	//�������� ������ ptList2 �� ��������� Point ����� �������, ����� �� ���� 
	//������ ������� ��������� ���� Point, �� �������� ��������� ������ �������������
	//�� � �������� ������� 



	//������������ ������  ptList1 � ptList2 - ������� ������ list - sort()
	//�� �����������.
	//���������: ��� ������ ���� ����������� � ������ Point ��� ����, �����
	//�������� ����������


	


	stop

	//���������� ��������������� ������ - merge(). ����������: ���
	//��� ���� ���������� � ������ �������.

	
	stop

	//���������� �������� �� ������ - remove()
	//��������� �� ������ ������� � ������������ ���������.
	//���������: ��� ������ ���� ����������� � ������ Point?
	

	//���������� �������� �� ������, ���������������� ��������� �������:
	//����� �� ��������� ������������ - remove_if(). 


	//���������� �� ������ ������ ������������� ������ - unique(). 

	stop

///////////////////////////////////////////////////////////////////
	//������� 2.������� � ����� ������� - ��������� deque

	//�������� ������ deque � ���������� ���� Point. � �������
	//assign ��������� deque ������� ��������� �������. � �������
	//�������������� ���� � ���������� ������� �������������� �������
	//�������� �������� ��������� �� ������



	//�������� deque � ���������� ���� MyString. ��������� ��� ����������
	//� ������� push_back(), push_front(), insert()
	//� ������� erase ������� �� deque ��� ��������, � ������� �������
	//���������� � 'A' ��� 'a'




	return 0;
}