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
	Data():sex(UNDEF),tm_age(0), m_job("N/A"), m_salary(0)
	{ }

	Data(const Data& r) 
	{
		sex = r.sex;
		tm_age = r.tm_age;
		m_job = r.m_job;
		m_salary = r.m_salary;
	}

	Data(Sex _sex, size_t _tm_age, const char* str, float salary): sex(_sex), tm_age(_tm_age), m_job(str), m_salary(salary)
	{	
	}

	Data& operator=(const Data& r)
	{
		if (this == &r) return *this;

		sex = r.sex;
		tm_age = r.tm_age;
		m_job = r.m_job;
		m_salary = r.m_salary;

		return *this;
	}

	Data(Data&& r)
	{
		m_job = r.m_job;
		r.m_job = nullptr;

		tm_age = r.tm_age;
		m_job = r.m_job;
		m_salary = r.m_salary;

		r.sex = UNDEF;
		r.tm_age = 0;
		r.m_salary = 0;
	}


	Data& operator=(Data&& r)
	{
		if (this == &r) { return *this; }

		sex = r.sex;
		tm_age = r.tm_age;
		m_job = r.m_job;
		m_salary = r.m_salary;

		r.sex = UNDEF;
		r.tm_age = 0;
		r.m_job = nullptr;
		r.m_salary = 0;

		return *this;
	}
};

