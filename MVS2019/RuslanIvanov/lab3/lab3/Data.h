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
};

