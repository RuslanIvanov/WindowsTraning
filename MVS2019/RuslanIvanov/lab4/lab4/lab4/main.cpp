#include<iostream>
#include <fstream>
#include <tchar.h>

#include "Circle.h"
#include "List.h"

#define	  stop __asm nop

int _tmain(int argc, _TCHAR* argv[])
{
	List list;
	list.AddHead(Circle(1, 1, 1));
	list.AddHead(Circle(2, 2, 2));
	list.AddHead(Circle(3, 3, 3));

	std::cout << "\n---------------------------------";
	std::cout << list;

	list.AddTail(Circle(5, 5, 5));
	list.AddTail(Circle(4, 4, 4));
	list.AddHead(Circle(5, 5, 5));

	std::cout << "\n---------------------------------";
	std::cout << list;
		   	
	list.Sort();
	std::cout << "\nSort list:-----------------------";
	std::cout << list;
	
	std::ofstream fout("list.txt");
	fout << "\nsort list:\n" << list << std::endl;
	fout.close();

	list.RemoveAll(Circle(5, 5, 5));
	std::cout << "\n---------------------------------";
	list.RemoveAll(Circle(1, 1, 1));
	std::cout << list;

	list.Cleaning();

	std::cout << "\nCleaning:-------------------------";
	std::cout << list;

	return 0;

}