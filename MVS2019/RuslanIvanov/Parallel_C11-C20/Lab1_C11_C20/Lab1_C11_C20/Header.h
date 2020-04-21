#pragma once
const char* filespec[] = { "1.txt", "2.txt", "3.txt","4.txt"};

inline void writeToFile(const char* filename, const string& str)
{
	ofstream f;
	f.open(filename);

	if (f.is_open())
	{
		std::cout << "\nfile "<< filename <<" is opened:\n";
		
		f << str;
		
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

		f >> str;

		cout << "\n'" << str<< "'";

	}else 	throw "file open for read is error";

	f.close();
}