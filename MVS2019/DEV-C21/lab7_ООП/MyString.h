
#pragma once
#include <iostream>
using namespace std;
class MyString
{
	//friend 	void Swap(MyString& a, MyString& b); //���� ���������� ���������� ���� �������
 friend ostream& operator<<(ostream& os, const MyString& s);

    char* m_pStr;	//������-���� ������

public:
// ����������� � �����������
 explicit	MyString(const char* pStr );  //������ �������� ��������������

// ����������� �� ���������
	  MyString();		
	// ����������� �����������
 MyString(const MyString& other );
 // ����������� ����������� (move semantics)
 MyString(MyString&& other );  
 

// ����������
    ~MyString();   

//char* GetString(){	return m_pStr;} //��� ����� �������� � �������(��.main)
//char& GetString(){	return  *m_pStr;}     //const ��� ����, ����� ������ ���� �� ������������� ������ ���-�� ���������
const char* GetString(){	return  m_pStr;}   //���� char* GetString();
 
//MyString&	 GetString(){	return *this;}
	  
	void SetNewString (const char* pStr);

	  MyString& operator=(const MyString& s);
	  MyString& operator=(const char* str);

	  // �������� ������������ (move semantics)
 MyString& operator=(MyString&& s);

MyString operator+(const MyString& s);
MyString operator+(const MyString& s)const ; //���������� ������
MyString& operator+=(const MyString& s);

	  bool operator==(const MyString& other);
	  bool operator==(const char* other);

	//  friend void Swap(MyString& a, MyString& b);   //���, ���� ���������� ���������� ���� ������� 
	// template <>  friend void Swap(MyString& a, MyString& b); //������������� ������� ������ ������� ������ 
	  //�������� �������� �� ������� ������: friend  ����� template!!!!!  
	// template <typename T> friend void Swap(T& a, T& b);  // ��� �����
	  template<typename T> friend  void Swap(T& s1, T& s2);
	
};
//���������� �������
ostream& operator<<(ostream& os, const MyString& s);


/*#pragma once
#include <iostream>
class MyString
{
    char* m_pStr;	//������-���� ������
public:
    MyString(const char* pStr );  // ���������� ������������
	
    ~MyString();           // ���������� �����������
const char* GetString();   

//MyString&	 GetString(){	return *this;}
	  MyString(const MyString& other );  // ����������� �����������
	  void SetNewString (const char* pStr);
	  MyString();	// ���������� ������������ �� ���������
	  MyString& operator=(const MyString& s);
	    bool operator==(const MyString& other);

		friend std::ostream& operator<<(std::ostream& os, const MyString& s);
//���������� ���� �������
//friend void Swap(MyString& a, MyString& b);
//������������� ������� ���  ���� MyString
//template <> friend void Swap(MyString& a, MyString& b);
	  friend void Swap(MyString& a, MyString& b);
};
*/