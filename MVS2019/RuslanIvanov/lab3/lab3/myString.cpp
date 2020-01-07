#include <string>
#include <iostream>
#include <cstdarg>
#include "myString.h"
using namespace std;

// ќпределение конструктора.

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

// ќпределение деструктора.
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
	cout << "\nMyString::operator=()";

	if (this == &r)
	{ return *this; }

	int n_cur = strlen(m_pStr)+1;
	int n_copy = strlen(r.m_pStr) + 1;

	if (n_cur < n_copy)
	{
		delete[] m_pStr;
		m_pStr = new char[n_copy];
	}

	strcpy(m_pStr, r.m_pStr);
	
	return *this;
}

MyString::MyString(MyString&& MoveSource) 
{/* огда он доступен, компил€тор C++11 автоматически выбирает конструктор перемещени€ 
 дл€ временного Уперемещени€Ф ресурса, а следовательно, избегает этапа глубокого копировани€!!!*/
	if (MoveSource.m_pStr != nullptr) 
	{
		//вз€ть собственнеость и переместить
		m_pStr = MoveSource.m_pStr;
		MoveSource.m_pStr = nullptr;
	}
	cout << "\nMyString::move constructor";
}

MyString& MyString::operator= ( MyString&& MoveResource) 
{
	cout << "\nMyString::move operator=()";

	if (this == &MoveResource)
	{
		return *this;
	}

	delete[] m_pStr;// освобожление собственного ресурса
	m_pStr = MoveResource.m_pStr; // вз€ть в сообственность - начало перемещени€
	MoveResource.m_pStr = nullptr; // освободить источник перемещени€ от собственности

	return *this;
}

/////////////////////////////////////////////////////////////////////
MyString ApplyString(const char *p1, ...)
{
	MyString strConcat;
	int count = 0;
	const char* pstr = p1;// так как первым параметром может быть 0 и в цикл не попадем
	va_list p;// универсальынй указатель
	va_start(p, p1);//направл. универсального указ. на первый необ€хат парам.

	while (pstr!=nullptr)
	{
		std::cout << "\n#" << count << ": " << pstr;
		strConcat.ConcatString(pstr);
		pstr = va_arg(p, char*);
		count++;
		
	}

	return strConcat; //дл€ оптимизаци move копирование дл€ MyString
}
MyString& MyString::operator+(const MyString& s)
{
	int n_cur = strlen(m_pStr) + 1;
	int n_new = strlen(s.m_pStr) + 1;
	char* p = new char[n_cur + n_new];
	
	strcpy(p, m_pStr);
	strcat(p, s.m_pStr);

	delete[] m_pStr;

	m_pStr = p;

	return *this;

}

MyString& MyString::operator+=(const MyString& s) 
{
	//this->operator=(this->operator+(s));
	//(*this) =	(*this) + s;
	return (*this) + s;
}

////////////////////////////////////////////////////////////////////////////////
ostream& operator<<(ostream& os, const MyString& s) 
{
	os << "\nconent: " << s.m_pStr;
	return os;
}

MyString Concat(const char* p1, ...) 
{
	int count = 0;
	const char* pstr = p1;// так как первым параметром может быть 0 и в цикл не попадем
	va_list p;// универсальынй указатель
	va_start(p, p1);//направл. универсального указ. на первый необх. парам.

	int len = 0;
	
	while (pstr != nullptr)
	{
		std::cout << "\n#" << count << ": " << pstr;
		len += strlen(pstr) + 1;
		pstr = va_arg(p, char*);
		count++;
	}
	std::cout << "\n#LEN ALL " << count << ": " << len;
	char* ppp = new char[len];
	*ppp = 0;
	//const char** pp = &p1;
	const char* pstr2 = p1;
	va_start(p, p1);
	for (int i = 0; i < count; i++)
	{
		strcat(ppp, pstr2);
		pstr2 = va_arg(p, char*);
	
	}
	MyString strConcat(ppp);
	delete[] ppp;
	return strConcat;
}