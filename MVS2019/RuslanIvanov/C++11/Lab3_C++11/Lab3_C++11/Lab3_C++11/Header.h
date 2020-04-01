#pragma once

constexpr unsigned int factorial(unsigned int N)
{
	return ((N == 0) ?  1 :  (N * factorial(N - 1)));
}

inline static int FactNaive(int n)
{
	int r = 1;
	for (int i = 2; i <= n; ++i)
		r *= i;
	return r;
}

constexpr  int conv2(const char* str)
{
	unsigned int i = (str[0] == '1') ? 1 << (strlen(str) - 1) : 0;

	if (*str) { i |= conv2(str + 1); };

	return i;
}


constexpr  int conv3(const char* str)
{
	 int i = 0;
	
	if (str[0] == '1')
	{
		i = 1;
		for ( int ii = 0; ii < (strlen(str) - 1); ii++)
		{
			i *= 2;
		}
		
	}

	if (*str) { i += conv3(str + 1); };
	
	return i;
}


constexpr int  mystrlen(const char* str) 
{
	return (*str) ? (mystrlen(str + 1) + 1) : 0;
}

constexpr  int mypow( int base,  int exp) noexcept
{
	return (exp == 0 ? 1 : base * mypow(base, exp - 1));//exp - степень
}

constexpr  int conv (const char* str)
{
	return (*str) ? conv(str + 1)+( (*str=='1') ? mypow(2, mystrlen(str)-1)  : 0) : 0;
}

constexpr  int operator""_b(const char* str) 
{		
	return  conv(str);	
}


inline std::string operator""_toBinStr(unsigned long long l) 
{
	std::string s="0";
	int bits = CHAR_BIT;
	const unsigned char K = 0xff;

	for (unsigned long long ki = K; ki < l; ki += K)
	{
		bits=bits + CHAR_BIT;
	}
	std::cout << "\nbits in '"<<l<<"' = " << bits;
	bool findFirstBit = false;
	for (unsigned long long i = bits; i > 0; i--)
	{
		if (l & (1 << (i-1)))
		{
			if (!findFirstBit)
				s = '1';
			else 
				s += '1';

			findFirstBit = true;
		}
		else 
		{ 
			if(findFirstBit)
			s += '0'; 
		}
		//std::cout << "\n#"<<i<<" s = " << s;
	}

	return s;
}

template<typename D>
void dl(D* s) 
{ 
	delete s; 
}