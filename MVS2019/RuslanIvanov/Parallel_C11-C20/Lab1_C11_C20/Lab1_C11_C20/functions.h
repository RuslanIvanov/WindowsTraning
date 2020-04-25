#pragma once

using namespace std;

string& mytolowerString(std::string& st);
string& mytoupperString(std::string& st);
void writeToFile(const char* filename, const string& str);
void readFromFile(const char* filename, string& str);
void readWriteAndChangeFromFile(const string& filename);
void MyBeep(unsigned int F, unsigned int MC);
void tr(const vector<int>& v, vector<int>& r, int first, int last,double& );

inline void  SLEEP(int ss)
{
	std::cout << "\nSLEEP "<<ss<<" s";
	//this_thread::sleep_for(std::chrono::0s+ss);
	std::cout << "\nRESUME";
}

inline void test()
{
	std::cout << "\ntest ";
}

