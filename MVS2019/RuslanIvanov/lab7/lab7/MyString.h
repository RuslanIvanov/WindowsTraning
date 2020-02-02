#pragma once
#include <string>
#include <iostream>
#include <cstdarg>

class MyString
{
    char* m_pStr;	//������-���� ������ //explicit ����� �� ����
   
public:
    MyString();
    //explicit
        MyString(const char* pstr); //pstr ="" - ����� �� ���� MyString()
    MyString(const MyString&);
    MyString(MyString&& MoveSource);// ����������� �����������
    ~MyString();

	MyString& operator=(const MyString& r);
    MyString& operator= ( MyString&& ); // �������� ������������ ��� �����������

    MyString operator+(const MyString& s); // ������� ������ ���������� �����
    MyString& operator+=(const MyString& s);

	bool operator == (const char* k) const;

    const char* GetString();
    void SetNewString(const char* pstr);
    void ConcatString(const char* pstr); 
    friend std::ostream& operator<<(std::ostream& os, const MyString& s);
	friend bool operator == (const char* k,const MyString&); //???
};
bool operator == (const char* k ,const  MyString& );
//////////////////////////////////////////////////////////////////////
MyString ApplyString(const char *p1, ...);
std::ostream& operator<<(std::ostream& os, const MyString& s);
MyString Concat(const char* p1, ...);