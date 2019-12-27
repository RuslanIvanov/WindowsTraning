#pragma once
class MyString
{
    char* m_pStr;	//строка-член класса //explicit вроде бы надо
   
public:
    MyString();
    MyString(const char* pstr); //pstr ="" - тогда не надо MyString()
    MyString(const MyString&);
    ~MyString();
	MyString& operator=(const MyString& r);

    const char* GetString();
    void SetNewString(const char* pstr);
    void ConcatString(const char* pstr);
};

//////////////////////////////////////////////////////////////////////
MyString ApplyString(const char *p1, ...);
