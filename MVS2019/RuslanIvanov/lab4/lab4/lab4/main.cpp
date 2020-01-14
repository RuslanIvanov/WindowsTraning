#include<iostream>
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

	//std::cout<<list;
	return 0;

}