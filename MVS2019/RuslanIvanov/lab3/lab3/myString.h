#pragma once
class MyString
{
    char* m_pStr;	//строка-член класса //explicit вроде бы надо
   
public:
    MyString();
    MyString(const char* pstr); //pstr ="" - тогда не надо MyString()
    MyString(const MyString&);
    MyString(MyString&& MoveSource);// конструктор перемещения
    ~MyString();
	MyString& operator=(const MyString& r);
    MyString& operator= ( MyString&& ); // Оператор присваивания при перемещении

    const char* GetString();
    void SetNewString(const char* pstr);
    void ConcatString(const char* pstr);
};

//////////////////////////////////////////////////////////////////////
MyString ApplyString(const char *p1, ...);
