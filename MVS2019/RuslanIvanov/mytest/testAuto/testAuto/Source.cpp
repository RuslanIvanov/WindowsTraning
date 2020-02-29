#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <initializer_list>

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
	int ar[] = {1,2};

	auto [a, b] = ar;
	a++;
	stop
	auto& [x, y] = ar;

	x++;
	stop


	{
		int ar[/*2*/][3] = {{1,2,3},{4,5,6}};
		for (size_t i = 0; i < 3; i++)
		{
			auto [a, b, c] = ar[i];
			stop
		}

	}
	{
		auto x = "qwery";
		short a = 1, b = 2;
		auto y = a / b;
		stop
	}
	return 0;
}