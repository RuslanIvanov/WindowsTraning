// lab6 RTTI
#include <tchar.h>
#include <iostream>
#include <fstream>
#include "myRect.h"
#include "Circle.h"
#include "List.h"

#define	  stop __asm nop
List test();
int _tmain(int argc, _TCHAR* argv[])
{
	List list;

	list.AddHead(&Circle(1, 1, 1,RED));
	list.AddHead(&Circle(10, 10, 10, RED));
	list.AddHead(&Circle(10, 10, 100, GREEN));
	list.AddHead(&Rect(2,2,2,2,GREEN));
	list.AddTail(&Rect(3, 3, 3, 3, GREEN));
	list.AddTail(&Rect(3, 3, 3, 3, BLUE));
	list.AddTail(&Rect(3, 3, 3, 3, BLACK));
	list.AddTail(&Rect(3, 3, 3, 3, BLACK));

	std::cout << "\nlist:--------------------------";
	std::cout<<list;

	list.RemoveOne(&Rect(3, 3, 3, 3, GREEN));
	std::cout << "\nlist after remove:--------------------";
	std::cout << list;

	List list2;
	list2 = list;

	std::cout << "\nlist2:--------------------------";
	std::cout << list2;

	list2.Sort();
	std::cout << "\nSort list:-----------------------";
	std::cout << list2;

	std::ofstream fout("list.txt");
	fout << "\nsort list:\n" << list2 << std::endl;
	fout.close();

	List list3 = list;
	std::cout << "\nlist3:--------------------------";
	std::cout << list3;

	list3.RemoveAll(&Rect(3, 3, 3, 3, BLACK));
	std::cout << "\nlist3 after all remove:------------------------";
	std::cout << list3;

	list3.Cleaning();
	std::cout << "\nlist3 after cleaning:--------------------------";
	std::cout << list3;

	List list5 = test();

	std::cout << "\nlist5 after move:--------------------------";
	std::cout << list5;

	List list6;
	list6 = test();

	std::cout << "\nlist6 after copy move:--------------------------";
	std::cout << list6;

	//std::ifstream f1;
	//f1.open("..\\lab6\\list.txt");
	//std::cout << "\nf1: ";
	//List l;
	//if /*while*/(f1.good())
	//{
	//	f1 >> l;		
	//}
	//std::cout << l << " ";
	return 0;
}//endmain

List test()
{
	List list4;
	list4.AddTail(&Circle(5, 5, 555));
	list4.AddTail(&Circle(4, 4, 444));
	list4.AddHead(&Rect(5, 5,5, 5));
	list4.AddHead(&Rect(4, 4, 4, 4));
	list4.AddHead(&Circle(5, 5, 111));

	return list4;
}
