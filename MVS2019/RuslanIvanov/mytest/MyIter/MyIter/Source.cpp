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

#include "OwnContainer.h"


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
	cout << "Привет лаб2 C++11,14,17!";
	stop
#endif

		return 0;
}