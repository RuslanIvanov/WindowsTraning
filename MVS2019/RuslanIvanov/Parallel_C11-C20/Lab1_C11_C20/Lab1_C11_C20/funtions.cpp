
#include "Header.h"
#include "functions.h"

using namespace std;
using namespace chrono_literals;

string& mytolowerString(std::string& st)
{

	for (std::string::iterator it = st.begin(); it != st.end(); it++)
		*it = tolower(*it);
	return st;
}

string& mytoupperString(std::string& st)
{

	for (std::string::iterator it = st.begin(); it != st.end(); it++)
		*it = toupper(*it);
	return st;
}

void writeToFile(const char* filename, const string& str)
{
	ofstream f;
	f.open(filename);

	if (f.is_open())
	{
		std::cout << "\nfile " << filename << " is opened:\n";

		f << str;

	}
	else 	throw "file open write is error";

	f.close();
}

void readFromFile(const char* filename, string& str)
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

	}
	else 	str += "file open for read is error";

	f.close();
}

void readWriteAndChangeFromFile(const string& filename)
{
	ifstream f(filename); 
	string pref = "_";
	ofstream f2(pref+filename);//filename + '_'

	if (f.is_open() && f2.is_open())
	{
		std::cout << "\nfiles:  " << filename <<" and "<< pref + filename << " is opened\n";
		transform(istreambuf_iterator<char>(f), istreambuf_iterator<char>(),
			ostreambuf_iterator<char>(f2), toupper);
	}

}

void MyBeep(unsigned int F, unsigned int MC)
{
	Beep(F, MC);
}