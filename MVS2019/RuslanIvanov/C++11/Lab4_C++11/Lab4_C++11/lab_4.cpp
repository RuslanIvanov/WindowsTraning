#include <iostream>
#include <memory>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <list>
#include <queue>
#include <iterator>

using namespace std;
#include "Header.h"

#if  _WIN32 

#define	  stop __asm nop
#include <tchar.h>

#else

#define _tmain main
#define _TCHAR char 

void mystop()
{//Linux
	std::cout << "\nPause\n";
	getchar();
}

#define  stop  {mystop();}
#endif


int main(int,char**)
{
	
/***************************************************************/
//������� 1.
	/*
	���������� ������ ������� ��� ������ ����� ������������������� (vector, list, deque, set � ����������� �������), ������� ����� ���������:
	�	��� ������� ������ ����,
	�	��� � ��������� �� ������� ������ ���� (��������� ������������� ����������� => � ���� ������ ������� �������� �������� �� ������)
	���������: if constexpr
	*/
	{
		size_t ar[] = { 1,3,6,7,4,5,2 };
		vector<int> v = { 11,22,33,44,55 };
		list<string> l = {"s6","s7","s8","s9","s10"};
		deque<char> d = {'A','B','C'};
		set<short> s = {33,44,55};

		std::vector<std::string*> vs = { new std::string("aa"), new std::string("bb"), new std::string("cc") };


		std::unique_ptr<std::string* []>ptrV = make_unique<std::string* []>(3);
		ptrV[0] = new string("s1");
		ptrV[1] = new string("s11");
		ptrV[2] = new string("s111");

		PRINTF(ar);
		PRINTF(v);
		PRINTF(l);
		PRINTF(d);
		PRINTF(s);
		PRINTF(vs);
		//PRINTF(ptrV);
		stop
	}

/***************************************************************/
//������� 2.
	/* ���������� ������ ������� �������� ���� ��������.
	���� ������ ��������� �������� ��������, �� ��� �������� ������� ����� ��������� �� �������� ������� ���������. ��� ���� �������� ������� � ������ �������� ������ ���� ������ � ���� �� ����.
	���������: if constexpr, is_same
	*/
	{

	}


	/***************************************************************/
//������� 3.
	/* 	���������� ������ ������� ������ �� ������ �������� ��������� ������ �������� (stack, queue, priority_queue)
	���������: if constexpr, is_same
	������������� ����� ��������, ���� � �������� �������� ���������.
	*/
	{

	}

/***************************************************************/
//������� 4.
	{
		//��� ������ ��������� ���� string
		std::string strings[] = {"abc", "123", "qwerty", "#$%"};
		//�� ���������� ��������� ������ ������ ������������ � ������������ ����������.
		//��������� ���������� ��������������� �������� �) ��� ����������� � �) ��� ��������� �������
		//��������� � �������!
		
		//� std::set "����������" �� �������� ������� ��� �����, ������� �������� ������ ����� 
		

		__asm nop
		/******************************************************************************************/

		//� std::vector "����������" ������� ��� �����, ������� �������� ������ ����� 
		//������� �� �����
		//������� �����
		
		//std::vector<std::shared_ptr < std::string>>

		/******************************************************************************************/
		//���� "����������" ������� ��� �����, ������� �� �������� �� �������� ����, �� �������� ����
		//� ������ �������


	}

	
/******************************************************************************************/
//������� 5. 
	{
		//����:
		std::string ar[] = {"my","Hello", "World"};
		std::vector < std::shared_ptr<std::string>> v = {std::make_shared<std::string>("good"), std::make_shared<std::string>("bye")};
		


		//�) ��������� �������� � ������ ������� ��� ��������� �������, �� ������� �������� �������! 
		//�) ������������� ������ �� �������� � ������� �� �����
		//�) ���������� ���������� ������������ ������


		__asm nop
	}
	/***************************************************************/
		//������� 6. shared_ptr � weak_ptr
		//������� ��������������� ������ ����������� ������ human. � ������ ��������:
		//��� - string
		//�������� �������: ��� ��� ��� ���...
		//�������� - shared_ptr (�������� �� ������ ��������...)
		//���� - ��������� �� weak_ptr (����� �������� ����������� ������������)

		//������ ������ human:
		//����������� - ��� ������������� ����� � ��������
		//����������� �����������, �������� ������������, move ???
		//����������� ����� child() - 
		//				������ ������� ������� � ������� ������� ��� ����������� ��������
		//				+ ������������ ��� ����� ������� � ���������� � ��������

		//������ ����������� ����������� ��������������� ������ ��� ���������� ����������

	{
		//������� ������ � ����-�� ���������� => "����-���� ��� �� ����, ��������, ���� � ���"
		//(�� ���� �� ����� ���� ��� ���� � ��� ����):


		//std::shared_ptr<human> grandM1(new human("Eva"));
		//...

		//� ��� ��������� ���� - child():


		//� � ����� � ���� ������� ���� ����:


		//...
		__asm nop
	}



//***************************************************************/
//������� 7.

	/*���������������� deduction guide � ��� ������ ����� ���������� �������
	����� ������ ������, ������� ������������� ���������� ������������ ������ ���������
	����������� � ���������� ������ ����. */
/*
template<typename T, size_t size> class MyArray
	{
		T ar[size]; //��� ���������� ������������� ��������� �������� ���� �� ��������� �����?
		�
	};

*/
/*
//��������� ���������� ����������������� ����������� �������� �������������.
	{
		MyArray<int, 5> ar1;//MyArray<int,5>
		MyArray ar2{"ABC"}; //MyArray<char,4>
		int ar[] = { 1,2,3 };
		MyArray ar3{ ar };

	}
*/

	__asm nop

}