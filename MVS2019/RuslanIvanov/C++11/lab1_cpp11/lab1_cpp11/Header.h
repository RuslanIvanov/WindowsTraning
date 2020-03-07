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

template<typename T> void NegateAll(T& tt)
{
	for (auto& t : tt)
	{
		t *= -1;
	}
}

template<> void NegateAll(std::list<std::string>& c)
{
	for (std::string& s : c)
	{
		for (char& c : s)
		{
			if (c >= 'A' && c <= 'Z') { c = tolower(c); }
			else if (c >= 'a' && c <= 'z') { c = toupper(c); }
		}
	}

}

template <typename T>void absSort(/*const*/ T& vd) 
{
	std::sort(std::begin(vd), std::end(vd), [](/*C++11*/decltype(*std::begin(vd)) a,/*C++14*/ auto b)->bool 
											{ return abs(a) < abs(b); });
}

template <typename FIRST, typename SECOND> 
auto SumCont(FIRST& ar, std::list < SECOND >& l)
{
	auto N = (std::size(ar) >= std::size(l))? std::size(ar): std::size(l);

	std::vector<decltype(N)> v;
	v.resize(N);
 
	//копируем из меньшего в большее
	if (N == std::size(ar))
	{		
		transform(std::begin(l), std::end(l), std::begin(ar), std::begin(ar), [](const auto& a, const auto& b) { return a + b; });
		copy(std::begin(ar), std::end(ar), v.begin());// std::back_inserter(v));
	}
	else 
	{
		transform(std::begin(ar), std::end(ar), std::begin(l), std::begin(l), [](const auto& a, const auto& b) { return a + b; });
		copy(std::begin(l), std::end(l), v.begin());
	}
	
	return v;
}

template <typename FIRST, typename SECOND>
auto SumCont(std::vector < FIRST>& ar, std::list < SECOND>& l)
{
	auto N = (std::size(ar) >= std::size(l)) ? std::size(ar) : std::size(l);

	std::vector<decltype(N)> v;
	v.resize(N);

	//копируем из меньшего в большее
	if (N == std::size(ar))
	{
		transform(std::begin(l), std::end(l), std::begin(ar), std::begin(ar), [](const auto& a, const auto& b) { return a + b; });
		copy(std::begin(ar), std::end(ar), v.begin());// std::back_inserter(v));
	}
	else
	{
		transform(std::begin(ar), std::end(ar), std::begin(l), std::begin(l), [](const auto& a, const auto& b) { return a + b; });
		copy(std::begin(l), std::end(l), v.begin());
	}

	return v;
}

template <typename FIRST, typename SECOND>
auto SumCont(std::set < FIRST>& ar, std::deque < SECOND>& l)
{
	auto N = (std::size(ar) >= std::size(l)) ? std::size(ar) : std::size(l);

	std::vector<std::string> v;
	v.resize(N);

	//копируем из меньшего в большее
	if (N == std::size(ar))
	{
		transform(std::begin(l), std::end(l), std::begin(ar), std::begin(ar), [](const auto& a, const auto& b) { return std::string(a) + std::string(b); });
		copy(std::begin(ar), std::end(ar), v.begin());// std::back_inserter(v));
	}
	else
	{
		//transform(std::begin(ar), std::end(ar), std::begin(l), std::begin(l), []( auto& a,  auto& b) { return std::string(a) + std::string(b); });
		copy(std::begin(l), std::end(l), v.begin());
	}

	return v;
}

template <typename T, typename C> auto SUM(T& ar, C& l) 
{
	auto N = (std::size(ar) >= std::size(l)) ? std::size(ar) : std::size(l);

	std::cout << "N  = " <<N ;

	std::vector<decltype(N)> tmp;
	tmp.resize(N);
	/*if (N == std::size(ar))
	{
		transform(std::begin(l), std::end(l), std::begin(ar), std::begin(ar), [](const auto& a, const auto& b) { return a + b; });
		copy(std::begin(ar), std::end(ar), tmp.begin());
	}
	else
	{
		transform(std::begin(ar), std::end(ar), std::begin(l), std::begin(l), [](const auto& a, const auto& b) { return a + b; });
		copy(std::begin(l), std::end(l), tmp.begin());
	}*/
	return tmp;
}