#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
#include <typeinfo>
#include <utility>


#include "lab2_cpp11_14.h"
#include "MyVector.h"

using namespace std;

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


int main(int, char**)
{

#if  _WIN32 
	setlocale(LC_CTYPE, ".UTF8");
	cout << "Привет, лаб2 C++11,14,17!";
#endif
	MyVector<int> mv1;
	mv1.printVect();

	MyVector<int> mv2(1,8,{1,2,3,4,4,5,6,7,8,9,10,11,12,13,14,15});
	mv2.printVect();
	mv2.applyList(2, 55, { 9,8,7,7,6,55,5,5,4,4,3,2,1,0,10,33,12,13,66,77,88 });
	mv2.printVect();
	mv2.deleteList(0, 5,{1,2,3,4,5,6,7,8,9,10});
	mv2.printVect();
	mv2.sort(true);
	mv2.printVect();
	mv2.sort(false);
	mv2.printVect();

	
	return 0;
}