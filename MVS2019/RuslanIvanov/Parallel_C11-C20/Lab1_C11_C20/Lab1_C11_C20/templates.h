#pragma once
#include <iterator>
#include <iostream>

class predUpperStr
{
	std::string m_st;

public:
	predUpperStr()
	{
		m_st = "str";
	}

	std::string operator()(std::string& st)
	{

		for (std::string::iterator it = st.begin(); it != st.end(); ++it)
		{
			if ((*it >= 'a' && *it <= 'z'))
				*it = toupper(static_cast<char>(*it));

		}
		m_st = st;
		return m_st;
	}

};

template <typename TFunc> void RunAndMeasure(const char* title, TFunc func)
{
    const auto start = std::chrono::steady_clock::now();
    auto ret = func();
    const auto end = std::chrono::steady_clock::now();
    std::cout << title << ": " << 
              std::chrono::duration <double, std::milli>(end - start).count() 
              << " ms, res " << ret << "\n";
}
