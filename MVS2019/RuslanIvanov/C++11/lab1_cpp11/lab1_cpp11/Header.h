#pragma once

template <typename T> void printCont(const T& t)
{
	std::cout << "\nContainer:\n";
	for (typename T::const_iterator i = t.begin(); i != t.end(); ++i)
	{
		std::cout << *i << " ";
	}

}

template <typename T> void PrintAnyCont(const T& t) 
{
	
	std::cout << "\n";
	for (auto& tt : t) 
	{
		std::cout <<"| "<< tt <<" |";
	}
}

class L
{
public:
	bool operator()(const char* x, const char* y)
	{
		return strcmp(x, y) < 0;
	}

};

class compareFirstCh4
{
	char m_ch;
public:
	compareFirstCh4(char ch)
	{
		m_ch = ch;
	}

	bool operator()(const char* stl)
	{

		if (stl[0] == m_ch)
		{
			return true;
		}

		return false;
	}
};

char mytolower_char(char st)
{
	return static_cast<char>(tolower(static_cast<int>(st)));

}

template<typename T> void NegateAll( T& t) 
{	
	for (auto& tt : t)
	{
		std::cout << "\ntype is: " <<typeid(tt).name() << "";
		//if (strcmp("double", typeid(tt).name()) == 0) 
		//{		tt *= -1 ;		}

		//std::transform(t.begin(), t.end(), t.begin(), mytolower_char);
		//int i = atoi(tt);
		//if (i != 0) { tt *= -1; }
		//else
		//tt = toupper(tt);*/
		//if (tt == 0) { tt *= -1; }
		//for(auto it = std::begin(tt); it != std::end(tt); ++it)
		{
			//if (ttt >= 'A' && ttt <= 'Z') { tolower(ttt); }
			//else if (ttt >= 'a' && ttt <= 'z') { toupper(ttt); }
			//else { ttt *= -1; }
		}

		std::cout << "\n " << tt;
	}
}