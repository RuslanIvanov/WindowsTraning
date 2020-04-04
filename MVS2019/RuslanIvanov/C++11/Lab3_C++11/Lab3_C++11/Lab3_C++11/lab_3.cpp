
#include <string>
#include <iostream>
#include <cstdint>
#include <algorithm>
#include <iterator>
#include <memory>
#include <vector>
#include <list>

using namespace std;
#include "Header.h"
#include "classRange.h"

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
	
	//������� 1. ����� ��������� �������� (Raw String Literals)
	//�������� ������, ��������: my name is "Marina"
	//�) ��� ������������� Raw String Literals
	//�) ����������� Raw String Literals
	//�) �������� ����������� (Delimeter)

	{
		std::cout<<std::endl<< "my name is \"Ruslan\"";
		std::cout << std::endl << R"(my name is "Ruslan")";
		//delimiter:
		std::cout << std::endl << R"abc(my name is "Ruslan")abc";
		__asm nop
	}

	//////////////////////////////////////////////////////////////////////////////////////////////
	//������� 2. ���������� ���������� ���������� � ������� constexpr-�������.
	//
	//���������/�����������: 
	//		- constexpr � ������� ������ �������� �� ������������ ���������� return <���������>; (����!)
	//		- �� ��� ��������� ����� �������� ����� ������ constexpr � �������, � ��������� �����������
	//		  ����� 
	//		- ���� �������� ����������� constexpr- ������� - ��� ���������, ���������� �������� ���������
	//		  �� ����� ����������

	//��������� ��� ����, ��� ���������� ��������� �������� �� ����� ���������� (���� � ��������
	//				��������� ������������ ���������, ��������� ����������� �� ����� ����������).
	//				��� �������� ���������� ������� ���������� ������ � ������������, �����������
	//				����������� constexpr-�������:

	{	//��������:
		constexpr unsigned int rez = factorial(3);// 3 �������� �� ������ ������
		std::cout << std::endl<<"rez = "<<rez;

		int ar[factorial(3)];
		std::cout << std::endl;
		std::cout << "size ar " << std::size(ar);
		
		//���
		constexpr int n = factorial(5);//5 � n �������� �� ������ ����������
		int ar1[n];
		std::cout << "\nsize ar1 " << std::size(ar1);
		stop
		//����������:
		int m = 7;
		/*constexpr int n1 = factorial(m);// error m - �� �������� �� ����� ����������
		int ar2[n1];
		std::cout << "\nsize ar2 " << std::size(ar2);//*/
		//� ���?
		int n2 = factorial(m);// ���������� ������� ����� �_��
		//int ar3[n2];//err
		__asm nop
	}
	
	//////////////////////////////////////////////////////////////////////////////////////////////
	//������� 3a. ������� � ������� ����������������� �������� �� ��������� ������������� ����������
	//� ��������, ��������: ������ "100000000" -> � �������� 256
	//��������� ��������� ����������� �������� 0b
	//����� ����� ����������������� �������� �������� ������ � �������, ��������: 100000000_b
	//������� ������������ ���������������� ������� � ������������ ���������� - const char*

	//��� ��� ���� ���� � ���������, ������� ��������� �������� �� ����� ����������
	// => ���������� ���������������� ������� ����������� constexpr - �������
	//���������/�����������: 
	//		- constexpr � ������� ������ �������� �� ������������ ���������� return <���������>;
	//		- �� ��� ��������� ����� �������� ����� ������ constexpr � �������,
	//		- ������� ����� ���� ����������� (���� �������� ����� ������� - ��� ���������,
	//		  ���������� �������� ��������� ������ ����������� ������� �� ����� ����������)

	{
		int b = 0b100000000;
		int test  = conv("100000000");
		std::cout << std::endl << "test conv() = " << test;
		int test2 = conv2("100000000");
		std::cout << std::endl << "test conv2() = " << test2;
		int test3 = conv3("100000000");
		std::cout << std::endl << "test conv3() = " << test3;
		constexpr int test4 = mypow(2, 3);
		std::cout << std::endl << "tes4  = " << test4;

		constexpr int bb = 100000000_b;
		int ar[bb];
		std::cout << std::endl << "ar size " << std::size(ar);
		if (b == bb) { std::cout << std::endl << " OK "; }//*/
		__asm nop

	}

	//������� 3b. ������� � ��������� �������� �������������, ��������: 256 -> "0b100000000"
	//��� ��� ������ ����� ���� ����� �����, �������� � ����� ���������� ������ std::string
	//=> ������������ �������� �� ����� ���� constexpr!
	//���������: ������������ std::bin ���� ��� => �������������� � �������� ������
	//�������� ������ �������
	//���������: ���������� �������� � ����� ���������� ��������� CHAR_BIT - <cstdint>

	{
		
		std::string sBinTest = 131_toBinStr;
		std::cout << std::endl << "bin test " << sBinTest;
		std::string sBin = 256_toBinStr;
		std::cout << std::endl << "bin " << sBin;
			
		stop 
	}

	//////////////////////////////////////////////////////////////////////////////////////////////
	//������� 4�. constexpr - ������� 
	//������� ����� (������ ������?) ��� �������� � ��������������� ���������� ��������.
	//� ������ ������ ����:
	//	���������� ��� �������� ������������ � ������������� ��������,
	//	������ ��� ��������� ������� �� ��������
	//	����� ��� �������� - �������� �� ��������� �������� � ��������
	//	�����, ������� �������� ����� �������� ������� ���� � ��������� �������������� ��������:
	//							���� ����������� ���������, �� ��� � ����������
	//							���� ������ ������������ ��������, ���������� �����������
	//							���� ������ ������������� ��������, ���������� ������������

	//��������� ��� ����, ��� ���������� ��������� �������� �� ����� ����������. 
	//				��� �������� ���������� ������� ���������� ������ � ������������, �����������
	//				����������� constexpr-������:
	{
		
		c_range<int> rangeInt(10, 200);// no constexpr
		rangeInt.setValue(50);
		if (rangeInt.operator==(88)) { std::cout << "\nin range: " << rangeInt;  }
		else { std::cout << "\nno in range: " << rangeInt; }

		if (rangeInt.operator==(8)) { std::cout << "\nin range: " << rangeInt; }
		else { std::cout << "\nno in range: " << rangeInt; }

	    constexpr unsigned  char v = c_range<unsigned char>(5, 255).setValue(33);
		stop
		constexpr c_range<unsigned short> c(6,300,88);
		
		char ar[c.getValue()];
		__asm nop
	}	

	//////////////////////////////////////////////////////////////////////////////////////////////
	//������� 5. unique_ptr
	{

		//5.� - ���������� ���������� ���������� ���������
		{
			std::vector<std::string*> v = { new std::string("aa"), new std::string("bb"), new std::string("cc") };
			//������������ ��� ������
		
			__asm nop
			for (size_t i = 0; i < v.size(); i++)
			{
				//std::cout << "\nstr: " << v[i]->c_str();
				std::cout << "\nstr: " << *v[i];
			}
			//???
			stop
			for (size_t i = 0; i < v.size(); i++)
			{
				delete v[i];
		
			}
			stop
		} //???// �����, ��� ������� + ����� ������� ������
		stop
			//5.b - ������������� ������� 5.�:
			 //���������� ����������� std::unique_ptr: 
			 //����������� ���������� (��������� ��� ������ ������� ������������ std::unique_ptr), 
			 //���������� �������� ���������� �� ����������� ����������� ������� std::string, 
			 //���������������,
			 //� ������������ ��������
			 //

		{/*
		 unique_ptr �� ����� ���� ���������� ��� ����� ����� �������� ����������. 
		 ������������� unique_ptr ����� �������� �������� ����������� �������� ������� ��������� unique_ptr. 
		 const std::unique_ptr �� ����� ���� �������, ����������� ����� ����� ������������ ������� ��������, 
		 � ������� ��������� ��� ������. ����� unique_ptr ������������, �� ������� ������ � ������� Deleter.

		 ���������� ��� ������ std::unique_ptr:
		 1) ��������� �������� ����� ������ �������, ��������, ���������� � ������� ��������� new
		 2) ��������� �������� ����� �������, � ������, ������������ �� ����� ����������, ���������� � ������� new[]
		 �������� ������ ���������� std::unique_ptr ��������:
		- ����������� ������������ ���������� ��� ������� � �������, ������� ��������� ��������� � ������������ �������� �����,
		 ���������� �������� � ������ ����������� ���������� � ���������� �� ����������
		-	�������� �������� ����������� ��������� �������� � �������
		-	��������� �������� ����������� ��������� �������� �� �������
		-	� �������� ���� �������� � �����������, �������������� ��������� �����������, 
			����� ��� std::vector, ������� ������ ��������� �� ����������� ���������� ������� 
			(��������, ���� ���������� ����������� ���������)
		 */
			//������������ ��� ������
			std::unique_ptr<std::string*[]>ptrV = make_unique<std::string*[]>(3);
			ptrV[0] = new string("s1");
			ptrV[1] = new string("s11");
			ptrV[2] = new string("s111");

			for (size_t i = 0; i < 3; i++)
			{
				std::cout << "\n " << *ptrV[i];
			}

			//??list
			std::initializer_list<std::unique_ptr<string>> list = { std::unique_ptr<string>(new std::string("aa")), std::unique_ptr<string>(new std::string("bb")), std::unique_ptr<string>(new std::string("cc")) };
			//?? ������ ����� move, ��� ��� ������ ������������� ������� ���. ������������� �_�����������, ���. ���������
			vector<std::unique_ptr<string>> vs;// = { std::unique_ptr<string>(new std::string("aa")),  std::unique_ptr<string>(new std::string("bb")) };
			vs.push_back(std::unique_ptr<string>(new std::string("aaa")));//push_back(T &&)
			vs.push_back(std::unique_ptr<string>(new std::string("bbb")));
			vs.push_back(std::unique_ptr<string>(new std::string("ccc")));
		    for (size_t i = 0; i < vs.size(); i++)
		    {
				std::cout << "\nstr vs: " << *vs[i];
			}

			__asm nop
		 //??? ����������� ����������� ��������� ��������?
		} //???
		stop
		{//5.c - ��������� ������� 5.b �������� ����������� �������� ���������� ������
		 //��������� ������� (��������, �������� ��������� �������: "AAA" -> "AAA_1")  
		
			vector<std::unique_ptr<string>> vs;
			vs.push_back(std::unique_ptr<string>(new std::string("aaa")));
			vs.push_back(std::unique_ptr<string>(new std::string("bbb")));
			vs.push_back(std::unique_ptr<string>(new std::string("ccc")));
			for (size_t i = 0; i < vs.size(); i++)
			{
				std::cout << "\nstr vs: " << *vs[i];
			}
	
		
			transform(vs.begin(), vs.end(), vs.begin(), myModyString("_1"));

			for (size_t i = 0; i < vs.size(); i++)
			{
				std::cout << "\nmody str vs: " << *vs[i];
			}
			__asm nop
		}

		{//5.d - ������������ ������ ��������	

		 //�������� unique_ptr, ������� �������� �������� ��� ������������� �������
		 //� ���������� std::string
		 //� ������� unique_ptr::operator[] ��������� ��������� ������ ����������
		 //����� ���������� ������������ ������?
			std::unique_ptr<std::string[]>ptrV4(new string[3]);
			for (int i = 0; i < 3; ++i)
			{
				ptrV4[i] = string("bbb");//move 
			}

			for (size_t i = 0; i < 3; i++)
			{
				std::cout << "\nstr: " << ptrV4[i];
			}

			__asm nop
		}//������������ ~ptrV4 => delete[] 

		{//5.e - ������� ������������ �������� � ���������������� delete-������� (�������)
		 //����� �������� ������ ���������� �� ����������� ��������� �������
		 //�������� unique_ptr ��� ������ �������
		 //���������� ���������������� delete-������� (�������) ��� ����������� 
		 //������������ ������

			std::string* arStrPtr[] = { new std::string("aa"), new std::string("bb"), new std::string("cc") };
			
			//std::unique_ptr<string*[], std::default_delete< string*[] >> p(arStrPtr);//??? -  �� ������� ������ - error
		  
			myDelString killer(3);// OK
			std::unique_ptr<string*[],decltype(killer)> p(arStrPtr, killer);
			
			//std::unique_ptr<string* [], decltype(&delMass)> p(arStrPtr, delMass(arStrPtr, 3));//?? error ??
			//std::unique_ptr<string*[], void(*)(string**,size_t n)> p(arStrPtr,delMass);//?? error ??
			std::cout << "\n# " << *p[0];
			std::cout << "\n# " << *p[1];
			std::cout << "\n# " << *p[2];//*/

		
			__asm nop
		}

		{//5.f �������� � ��������� ������, ���������� unique_ptr ��� ���������� �� std::string
			//����������� ��������� copy() ���������� �������� ������� � ������ ������ � ���������� 
			//���� �� ����
			//���������: ������������ ��������� � ������ std::make_move_iterator
			std::string* s[] { new std::string("one"), new std::string("two"), new std::string("three") };
			vector<unique_ptr<string>>vv(std::make_move_iterator(std::begin(s)),std::make_move_iterator(std::end(s)));
			vv.push_back(std::unique_ptr<string>(new string("four")));
			for (size_t i = 0; i < vv.size(); i++)
			{
				std::cout << "\n# " << *vv[i];
			}

			std::list<unique_ptr<string>> l;
			
			std::copy(std::make_move_iterator(vv.begin()), std::make_move_iterator(vv.end()), std::back_inserter(l));
			//list<unique_ptr<string>>::iterator itl = l.begin();
			for (auto i = l.begin(); i != l.end(); ++i)
			{
				std::cout << "\n#l-> " <<*(i->get());
			}
			stop
			//vector<unique_ptr<string>>vvv;
			//std::copy(std::make_move_iterator(vv.begin()), std::make_move_iterator(vv.end()), std::back_inserter(vvv));
			//for (size_t i = 0; i < vvv.size(); i++)
			//{
			//	std::cout << "\n#vvv-> " << *vvv[i];
			//}
			__asm nop

		}
		__asm nop

	}

	////////////////////////////////////////////////////////////////////////////////
	//������� 6.shared_ptr + ���������������� delete-������� 

	//����������� ����������� ������ � ���� ������ (�������) �� ������ ���������� 
	//(��� ��������� ����� ����������� �������� ��� �������)
	//��� ��� ��� "��������" ����� �� ������� ���������� ���� ������ � ���� � ��� �� ����,
	//������� ������������ �� ����������� ������������ ����� � ��� �� ���������� FILE* =>
	//���������� �������� ��� ������ ��������� �������� shared_ptr
	//�. ������ �������� ������ �������/������� ���� ��� ������
	//�. ��� ��������� �������� ������ �������������� � �������������
	//�. ��������� �������� ��������� ������ ������� ����

	//���������: ����������� ������� ������ ����� � ������� ������� rand()
	/*
	{

	//"��������":
	//������� writer1, writer2


	//��������, ��������� ������:
	char ar1[] = "Writer1";
	char ar2[] = "Writer2";

	//�������� ����� �������� ��������� ������� ��������� ������ �� "���������" �������� � ����
	//���� �������
	//���������: ������� ������ ���������� � ���� ����������� ������� fputs()


	__asm nop
	}//�������� �����???

	*/

	
}