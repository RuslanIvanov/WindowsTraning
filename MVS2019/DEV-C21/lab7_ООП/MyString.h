
#pragma once
#include <iostream>
using namespace std;
class MyString
{
	//friend 	void Swap(MyString& a, MyString& b); //если используем перегрузку имен функции
 friend ostream& operator<<(ostream& os, const MyString& s);

    char* m_pStr;	//строка-член класса

public:
// конструктор с параметрами
 explicit	MyString(const char* pStr );  //запрет не€вного преобразовани€

// конструктор по умолчанию
	  MyString();		
	// конструктор копировани€
 MyString(const MyString& other );
 // конструктор копировани€ (move semantics)
 MyString(MyString&& other );  
 

// деструктор
    ~MyString();   

//char* GetString(){	return m_pStr;} //Ёто может привести к ошибкам(см.main)
//char& GetString(){	return  *m_pStr;}     //const дл€ того, чтобы нельз€ было по возвращенному адресу что-то присвоить
const char* GetString(){	return  m_pStr;}   //было char* GetString();
 
//MyString&	 GetString(){	return *this;}
	  
	void SetNewString (const char* pStr);

	  MyString& operator=(const MyString& s);
	  MyString& operator=(const char* str);

	  // оператор присваивани€ (move semantics)
 MyString& operator=(MyString&& s);

MyString operator+(const MyString& s);
MyString operator+(const MyString& s)const ; //предлагает Ёлджер
MyString& operator+=(const MyString& s);

	  bool operator==(const MyString& other);
	  bool operator==(const char* other);

	//  friend void Swap(MyString& a, MyString& b);   //Ёто, если используем перегрузку имен функций 
	// template <>  friend void Swap(MyString& a, MyString& b); //специализацию шаблона нельз€ сделать другом 
	  //обратить внимание на пор€док записи: friend  после template!!!!!  
	// template <typename T> friend void Swap(T& a, T& b);  // так можно
	  template<typename T> friend  void Swap(T& s1, T& s2);
	
};
//глобальные функции
ostream& operator<<(ostream& os, const MyString& s);


/*#pragma once
#include <iostream>
class MyString
{
    char* m_pStr;	//строка-член класса
public:
    MyString(const char* pStr );  // объ€вление конструктора
	
    ~MyString();           // объ€вление деструктора
const char* GetString();   

//MyString&	 GetString(){	return *this;}
	  MyString(const MyString& other );  // конструктор копировани€
	  void SetNewString (const char* pStr);
	  MyString();	// объ€вление конструктора по умолчанию
	  MyString& operator=(const MyString& s);
	    bool operator==(const MyString& other);

		friend std::ostream& operator<<(std::ostream& os, const MyString& s);
//перегрузка имен функций
//friend void Swap(MyString& a, MyString& b);
//специализаци€ шаблона дл€  типа MyString
//template <> friend void Swap(MyString& a, MyString& b);
	  friend void Swap(MyString& a, MyString& b);
};
*/