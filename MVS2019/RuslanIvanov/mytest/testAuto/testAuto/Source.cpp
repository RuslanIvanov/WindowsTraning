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

	size_t ind1 = 0;
	unsigned char m_pmass[10];
	unsigned char r_m_pmass[10] = {1,2,3,4,5,6,7,8,9};
	for (size_t i = 0; i < 20; i++)
	{
		m_pmass[i] = r_m_pmass[ind1 % 10];
		std::cout << " " << ind1 % 10;
		ind1++;
	}
	return 0;
}