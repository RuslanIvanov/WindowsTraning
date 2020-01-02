#pragma once
class MyString
{
    char* m_pStr;	//������-���� ������ //explicit ����� �� ����
   
public:
    MyString();
    MyString(const char* pstr); //pstr ="" - ����� �� ���� MyString()
    MyString(const MyString&);
    MyString(MyString&& MoveSource);// ����������� �����������
    ~MyString();
	MyString& operator=(const MyString& r);
    MyString& operator= ( MyString&& ); // �������� ������������ ��� �����������

    const char* GetString();
    void SetNewString(const char* pstr);
    void ConcatString(const char* pstr);
};

//////////////////////////////////////////////////////////////////////
MyString ApplyString(const char *p1, ...);
