#pragma once
class MyString
{
    char* m_pStr;	//������-���� ������
   
public:
    MyString();
    MyString(const char* pstr); //pstr ="" - ����� �� ���� MyString()
    MyString(const MyString&);
    ~MyString();
    const char* GetString();
    void SetNewString(const char* pstr);
    void ConcatString(const char* pstr);
};

//////////////////////////////////////////////////////////////////////
MyString ApplyString(const char *p1, ...);
