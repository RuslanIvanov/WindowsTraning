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

    MyString& operator+(const MyString& s);
    MyString& operator+=(const MyString& s);

    const char* GetString();
    void SetNewString(const char* pstr);
    void ConcatString(const char* pstr);
    friend std::ostream& operator<<(std::ostream& os, const MyString& s);
};
 
//////////////////////////////////////////////////////////////////////
MyString ApplyString(const char *p1, ...);
std::ostream& operator<<(std::ostream& os, const MyString& s);