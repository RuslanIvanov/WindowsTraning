
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
using namespace chrono_literals;
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
	
	vector<thread> tv;
	string s_rez[sizeof(filespec) / sizeof(filespec[0])] = { "" };
	tv.reserve(sizeof(filespec) / sizeof(filespec[0]));
	chrono::time_point<chrono::system_clock> start , end;
	for (int i = 0; i < sizeof(filespec) / sizeof(filespec[0]); i++)
	{
		start = chrono::system_clock::now();
		tv.emplace_back(readFromFile,filespec[i], ref(s_rez[i]));
		tv[i].join();// иначе пардает
		end = chrono::system_clock::now();
		chrono::duration<double> diff = end - start;
		cout << "diff " << diff.count() << " s\n";
		stop
	}

	transform(begin(s_rez),std::end(s_rez),begin(s_rez), predUpperStr());// можно было в птоке

	for (int i = 0; i < sizeof(_filespec) / sizeof(_filespec[0]); i++)
	{
		thread th(writeToFile, _filespec[i], ref(s_rez[i]));
		stop
		th.join();// иначе пардает
	}

	return  0;
}