// lab6 RTTI
#include <tchar.h>
#include <iostream>
#include "myRect.h"
#include "Circle.h"
#include "List.h"

#define	  stop __asm nop

int _tmain(int argc, _TCHAR* argv[])
{
	List list;

	list.AddHead(&Circle(1,1,1,RED));

	list.AddHead(&Rect(2,2,2,2,GREEN));
	list.AddTail(&Rect(3, 3, 3, 3, GREEN));

	std::cout<<list;
	return 0;
}//endmain

