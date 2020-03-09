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
auto SumCont(FIRST& f, SECOND& l)
{
	size_t N = (std::size(f) >= std::size(l)) ? std::size(f) : std::size(l);
	
	auto it = *std::begin(f);
	std::vector< decltype( it) > v;
	v.resize(N);

	std::cout << "\ntype vector is: " << typeid(v).name() << "";

	copy(std::begin(f), std::end(f), v.begin());
	transform(std::begin(l), std::end(l), std::begin(v), std::begin(v), [](const auto& a, const auto& b) { return  a + b; });

	return v;
}

template <typename T, typename C> auto SUM(T& f, C& l) 
{
	size_t N = (std::size(f) >= std::size(l)) ? std::size(f) : std::size(l);

	std::vector<double> v;
	v.resize(N);

	copy(std::begin(f), std::end(f), v.begin());
	transform(std::begin(l), std::end(l), std::begin(v), std::begin(v), [](const auto& a, const auto& b) { return  static_cast<double>(a) + static_cast<double>(b); });

	return v;

}

template <typename FIRST, typename SECOND>
auto SUM(std::set < FIRST>& f, std::deque < SECOND>& l)
{
	size_t N = (std::size(f) >= std::size(l)) ? std::size(f) : std::size(l);

	std::vector<std::string> v;
	v.resize(N);

	copy(std::begin(f), std::end(f), v.begin());
	transform(std::begin(l), std::end(l), std::begin(v), std::begin(v), [](const auto& a, const auto& b)
	{ return  (a) + (b); });
	
	return v;
}

template<typename SOURCE, typename FIRST, typename SECOND,typename F>
void Separate(const SOURCE& src, FIRST& f, SECOND& s, F func)
{
	
	f.resize(src.size());
	s.resize(src.size());
	auto itf = std::begin(f);
	auto its = std::begin(s);
	std::cout << "\n";
	for(auto tmp: src)
	{
		if(func(tmp))
		{
			std::cout << " even ";
			*itf = tmp;
			++itf;
		}		
		else 
		{
			std::cout << " no even ";
			*its = tmp;
			++its;
		}
	}
}
