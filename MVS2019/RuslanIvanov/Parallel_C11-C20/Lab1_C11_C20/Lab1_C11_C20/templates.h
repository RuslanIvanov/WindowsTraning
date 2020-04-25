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
