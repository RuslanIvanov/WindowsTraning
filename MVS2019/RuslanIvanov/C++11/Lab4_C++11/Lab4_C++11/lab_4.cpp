#include <iostream>
#include <memory>
#include <vector>
#include <set>
#include <algorithm>
#include <string>
#include <list>
#include <queue>
#include <stack>
#include <iterator>
#include <set>

using namespace std;
#include "Point.h"
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
		Point* point[3] = { new Point(0,0),new Point(0,0) ,new Point(0,0) };
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

		PRINTF(point);
		PRINTF(ar);
		PRINTF(v);
		PRINTF(l);
		PRINTF(d);
		PRINTF(s);
		PRINTF(vs);
		//PRINTF(ptrV);//??

		PRINTF2(point);
		PRINTF2(ar);
		PRINTF2(v);
		PRINTF2(l);
		PRINTF2(d);
		PRINTF2(s);
		PRINTF2(vs);
		stop

		for (size_t i = 0; i < 3; i++)
		{
				delete point[i];
		}
	}

/***************************************************************/
//������� 2.
	/* ���������� ������ ������� �������� ���� ��������.
	���� ������ ��������� �������� ��������, �� ��� �������� ������� ����� ��������� �� �������� ������� ���������. 
	��� ���� �������� ������� � ������ �������� ������ ���� ������ � ���� �� ����.
	���������: if constexpr, is_same
	*/
	{
		vector<int> v = { 1,2,3,4 };
		sumV(v, 1);
		PRINTF(v);
		int n = 2;
		sumV(n, 1);
		std::cout << "\nn = "<< n;
		stop
	}


	/***************************************************************/
//������� 3.
	/* 	���������� ������ ������� ������ �� ������ �������� ��������� ������ �������� (stack, queue, priority_queue)
	���������: if constexpr, is_same
	������������� ����� ��������, ���� � �������� �������� ���������.
	*/
	{
		std::queue<int> q1;
		q1.push(-1);
		q1.push(3);
		q1.push(-2);


		std::queue<Point*> ppq1;
		ppq1.push(new Point(1, 1));
		ppq1.push(new Point(1, 3));
		ppq1.push(new Point(1, 2));

		std::stack<char> st1;
		st1.push('A');
		st1.push('C');
		st1.push('B');

		std::priority_queue<Point> pq1;
		pq1.push(Point(1, 1));
		pq1.push(Point(1, 3));
		pq1.push(Point(1, 2));

		 PRINT_ADAPT(q1);
		 PRINT_ADAPT(st1);
		 PRINT_ADAPT(pq1);
		 PRINT_ADAPT(ppq1);

		 while (!ppq1.empty())
		 {
			 delete ppq1.front();
			 ppq1.pop();
		 }

		 stop
	}

/***************************************************************/
//������� 4.
	{
		//��� ������ ��������� ���� string
		std::string strings[] = {"ccc","abc", "123", "qwerty", "#$%","321"};
		//�� ���������� ��������� ������ ������ ������������ � ������������ ����������.
		//��������� ���������� ��������������� �������� �) ��� ����������� � �) ��� ��������� �������
		//��������� � �������!
		
		//� std::set "����������" �� �������� ������� ��� �����, ������� �������� ������ ����� 
		auto DelStr = [](string*) { std::cout << "\nDelStr"; };

		std::shared_ptr<string> s1[] = {shared_ptr<string>(&strings[0], DelStr), shared_ptr<string>(&strings[1], DelStr),
										shared_ptr<string>(&strings[2], DelStr),shared_ptr<string>(&strings[3], DelStr),
										shared_ptr<string>(&strings[4], DelStr) ,shared_ptr<string>(&strings[5], DelStr) };

		std::set<std::shared_ptr<string>, SORT_SET> sp;
		//std::set < std::shared_ptr<string>, decltype(&cmp)>sp(cmp);
		//������?

		std::copy_if((std::begin(s1)), (std::end(s1)), std::inserter(sp, sp.begin()), [](std::shared_ptr<string>& s)
		{
				if ((*s->begin() >= 'a' && *s->begin() <= 'z') || (*s->begin() >= 'A' && *s->begin() <= 'Z'))
					return true;
				else return false;
		}		
		);//*/
		
		//set ��� ���������� ������ ����
		/*std::sort(sp.begin(), sp.end(), [](const std::shared_ptr<string>& l, const std::shared_ptr<string>& r) 
		{
				return (*l.get() > *r.get());
			//	return (*l->begin() > *r->begin());
		}
		);//*/
		
		//��� �������� �����
		for (auto i = sp.begin(); i != sp.end(); ++i)
		{
			std::cout << "\nsp: ";
			for (size_t j = 0; j < (*i)->size(); j++)
			{
				std::cout << "" << *((*i)->begin()+j);
			}
		}

		__asm nop
		/******************************************************************************************/

		//� std::vector "����������" ������� ��� �����, ������� �������� ������ ����� 
		//������� �� �����
		//������� �����
		
		std::vector<std::shared_ptr <std::string>> v;
		std::copy_if((std::begin(s1)), (std::end(s1)), std::back_inserter(v), [](std::shared_ptr<string>& s)
			{
				if ((*s->begin() >= '0' && *s->begin() <= '9'))
					return true;
				else return false;
			}
		);

		for (auto i = v.begin(); i != v.end(); ++i)
		{
			std::cout << "\nv: "<< (*i)->c_str();			
		}

		int sum = 0;
		for (auto i = v.begin(); i != v.end(); ++i)
		{
			sum+=std::atoi((*i)->c_str());
		}
		std::cout << "\nsum: " << sum<<"\n";
		stop
		/******************************************************************************************/
		//���� "����������" ������� ��� �����, ������� �� �������� �� �������� ����, �� �������� ����
		//� ������ �������

		ostream_iterator<std::shared_ptr <std::string>> out_it(cout, " ");
		//std::copy_if((std::begin(s1)), (std::end(s1)), out_it, [](std::shared_ptr<string>& s)
		std::vector<std::shared_ptr <std::string>> v2;
		std::copy_if((std::begin(s1)), (std::end(s1)), back_inserter(v2), [](std::shared_ptr<string>& s)
			{
				if ((*s->begin() >= '0' && *s->begin() <= '9') ||
					(*s->begin() >= 'a' && *s->begin() <= 'z') ||
					(*s->begin() >= 'A' && *s->begin() <= 'Z'))
					return false;
				else 
					return true;
			}
		);

		for (auto i = v2.begin(); i != v2.end(); ++i)
		{
			std::cout << "\nv2: "<< (*i)->c_str();	
		}

		stop
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
		auto DelStr2 = [](string*) { std::cout << "\nDelStr2"; };
		auto DelStr1 = [](string*) { std::cout << "\nDelStr1"; };
		for(size_t i = 0 ; i<sizeof(ar)/sizeof(ar[0]);i++)
			v.push_back(shared_ptr<string>(&ar[i], DelStr2));

		sort(v.begin(), v.end(), [](const std::shared_ptr<string>& l, const std::shared_ptr<string>& r)
		{
				return (*l.get() < * r.get());
				//	return (*l->begin() > *r->begin());
		}
		);

		for (auto i = v.begin(); i != v.end(); ++i)
		{
			std::cout << "\nv sort: " << (*i)->c_str();
			//i->reset(nullptr, DelStr1);
		}
		__asm nop
	}
	stop
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