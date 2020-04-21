
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
#include <thread>
#include <chrono>
#include <iostream>
#include <fstream>
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

void test() { cout << " test "; }

int _tmain(int argc, _TCHAR* argv[])
{

#if  _WIN32 
	setlocale(LC_CTYPE, ".UTF8");
	cout << "Привет, лаб1 parallel!";
#endif
	//thread t[sizeof(filespec) / sizeof(filespec[0])];
	string s[sizeof(filespec) / sizeof(filespec[0])] = { "" };
	for (size_t i = 0; i < sizeof(filespec) / sizeof(filespec[0]); i++)
	{
		//
		readFromFile(filespec[i], s[i]);
		{
			// t[i].(test);
		}
		stop
	}

	return  0;
}