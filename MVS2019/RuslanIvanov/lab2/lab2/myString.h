#pragma once
class MyString
{
    char* m_pStr;	//строка-член класса
   
public:
    MyString();
    MyString(const char* pstr); //pstr ="" - тогда не надо MyString()
    MyString(const MyString&);
    ~MyString();
   const char* GetString();
    void SetNewString(const char* pstr);
};
