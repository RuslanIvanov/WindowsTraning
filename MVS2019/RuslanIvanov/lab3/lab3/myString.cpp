#include <string>
#include <iostream>
#include <cstdarg>
#include "myString.h"
using namespace std;

// Определение конструктора.

MyString::MyString()
{
	/////////////////////////////////////
	//m_pStr = nullptr;
	//m_pStr = new char(0);// или так
	//strcpy(m_pStr, "");// не экономно
	////////////////////////////////////

	m_pStr = new char[1];
	*m_pStr = 0;
	cout << "\nMyString::def constructor";
}

MyString::MyString(const char* pstr) 
{
	int n = strlen(pstr) + 1;
	m_pStr = new char[n];
	///////////////////////////////////////////////
	strcpy(m_pStr, pstr);
	//strcpy_s(m_pStr, n ,pstr);//где  n размер принимающего буффера
	///////////////////////////////////////////////
	cout << "\nMyString::constructor, param";
}

MyString::MyString(const MyString& r) 
{
	int n = strlen(r.m_pStr) + 1;
	m_pStr = new char[n];
	strcpy(m_pStr, r.m_pStr);

	std::cout << "\nMyString::constructor copy";
}

// Определение деструктора.
MyString::~MyString()
{
	delete[] m_pStr;
	std::cout << "\nNow I am in nMyString's destructor!";
}


const char* MyString::GetString() 
{
	return m_pStr;
}


void MyString::SetNewString(const char* pstr) 
{
	int n_new = strlen(pstr) + 1;
	int n = strlen(m_pStr) + 1;

	if (n_new <= n) 
	{
		strcpy(m_pStr, pstr);
		return;
	}

	delete[] m_pStr;

	m_pStr = new char[n_new];
	strcpy(m_pStr, pstr);

}

void MyString::ConcatString(const char* pstr)
{
	if (pstr == nullptr) return ;

	int n_new = strlen(pstr) + 1;
	int n_current = strlen(m_pStr) + 1;

	char* p_new = new char[n_new + n_current];
	strcpy(p_new, m_pStr);
	strcpy(p_new + n_current-1, pstr);
	//strcat(p_new, pstr);

	delete[] m_pStr;

	m_pStr = p_new;
}

MyString& MyString::operator=(const MyString& r)
{
	if (this == &r) { return *this; }

	int n_cur = strlen(m_pStr)+1;
	int n_copy = strlen(r.m_pStr) + 1;

	if (n_cur < n_copy)
	{
		delete[] m_pStr;
		m_pStr = new char[n_copy];
	}

	strcpy(m_pStr, r.m_pStr);

	return *this;

	/*if (n_cur >= n_copy)
	{
		strcpy(m_pStr, r.m_pStr);
		return *this;
	}

	delete[] m_pStr;
	m_pStr = new char[n_copy];

	strcpy(m_pStr, r.m_pStr);

	return *this;*/
}

/////////////////////////////////////////////////////////////////////
MyString ApplyString(const char *p1, ...)
{
	MyString strConcat;
	int count = 0;
	const char* pstr = p1;// так как первым параметром может быть 0 и в цикл не попадем
	va_list p;// универсальынй указатель
	va_start(p, p1);//направл. универсального указ. на первый необяхат парам.

	while (pstr!=nullptr)
	{
		std::cout << "\n#" << count << ": " << pstr;
		strConcat.ConcatString(pstr);
		pstr = va_arg(p, char*);
		count++;
		
	}

	return strConcat; //для оптимизаци move копирование для MyString
}