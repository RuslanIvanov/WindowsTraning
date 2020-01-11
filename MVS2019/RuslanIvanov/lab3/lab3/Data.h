#pragma once
#include "myString.h"
class Data
{
public:
	enum Sex{ UNDEF, MALE, FMALE };
private:

	Sex sex;
	size_t tm_age;
	MyString m_job;
	float m_salary;

public:
	Data();
	Data(const Data& r);	
	Data(Sex _sex, size_t _tm_age, const char* str, float salary);
	Data& operator=(const Data& r);
	Data(Data&& r);
	Data& operator=(Data&& r);

	friend std::ostream& operator<<(std::ostream& os, const Data& d);
};

std::ostream& operator<<(std::ostream& os, const Data& d);
