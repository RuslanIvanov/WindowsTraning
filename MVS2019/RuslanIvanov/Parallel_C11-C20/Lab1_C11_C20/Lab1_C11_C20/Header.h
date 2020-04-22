#pragma once
const char* filespec[] = { "1.txt", "2.txt", "3.txt","4.txt"};
const char* _filespec[] = { "_1.txt", "_2.txt", "_3.txt","_4.txt" };

inline void writeToFile(const char* filename, const string& str)
{
	ofstream f;
	f.open(filename);

	if (f.is_open())
	{
		std::cout << "\nfile "<< filename <<" is opened:\n";
		//while (!f.eof())
		{
			f << str;
		}
	}else 	throw "file open write is error";

	f.close();
}

inline void readFromFile(const char* filename, string& str)
{
	ifstream f;
	f.open(filename);

	if (f.is_open())
	{
		std::cout << "\nfile " << filename << " is opened\n";
		while (!f.eof())
		{
			string s;
			f >> s;
			
			str += s;
			str += " ";
		}
		
		cout << "\n'" << str<< "'";

	}else 	str+= "file open for read is error";

	f.close();
}

inline string& mytolowerString(std::string& st)
{

	for (std::string::iterator it = st.begin(); it != st.end(); it++)
		*it = tolower(*it);
	return st;
}

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
			if((*it >= 'a' && *it <= 'z'))
			*it = toupper(static_cast<char>(*it));

		}
		m_st = st;
		return m_st;
	}

};