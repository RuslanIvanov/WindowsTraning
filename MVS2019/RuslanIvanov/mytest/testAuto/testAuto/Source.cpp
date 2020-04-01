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

inline std::string toBinStr(unsigned long long l)
{
	std::string s = "*";
	std::cout << "\nl = " << l;
	//std::cout << "\nbits = " << CHAR_BIT;
	int bits = CHAR_BIT;
	//unsigned long long K = 1;
	//for (int a = 0; a < CHAR_BIT; a++)
	///{
	//	K = K * 2;//2^CHAR_BIT
	//}
	//std::cout << "\nK = " << K;//256
	const unsigned char K = 0xff;
	for (unsigned long long ki = K; ki < l; ki += K)
	{
		bits = bits + CHAR_BIT;
	}
	std::cout << "\nbits = " << bits;
	bool findFirstBit = false;
	for (unsigned long long i = bits; i > 0; i--)
	{
		if (l & (1 << (i - 1)))
		{
			s += '1';
		}
		else
		{
			s += '0';
		}
		std::cout << "\n#" << i << " s = " << s;
	}

	return s;
}


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

	unsigned long long l = 256;
	std::cout << "\nenter l "; std::cin >> l;
	std::cout << " l =" << l << " k " << l % 256;
	unsigned long long count = 0;
	unsigned long long K = 1;
	for (unsigned char a = 0; a < 8; a++)
	{
		K = K * 2;
	}
	std::cout << "\nK = " << K;
	for (unsigned long long k = K; k <= l; k+=K)
	{
		count++;
	}
	std::cout << "\ncount = " << count;

	unsigned char c = 256;
	unsigned char cc = 1 << 7;
	unsigned char ccc = 1 << 8;
	string ss = "";
	ss += '1';
	ss += '2';
	ss += '3';
	std::cout << std::endl << "ss =  " << ss;
	return 0;
}