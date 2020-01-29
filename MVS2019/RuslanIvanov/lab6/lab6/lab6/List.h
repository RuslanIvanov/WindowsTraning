#pragma once
#include "myRect.h"
#include "Circle.h"
class List
{
	//���������� ���������� ������ Node
	class Node
	{
		//������:
		Node* pPrev;		//��������� �� ���������� �������
		Node* pNext;		//��������� �� ��������� �������
		Shape* m_Data;		//��������� �� ���� (������������) ����� ������

		//������:
		Node();//������ ����� ����������� ��� �������� ��������������� ������� � �������� (Head, Tail)
		Node(const Shape*, Node* next, Node* prev);
		Node(Node&&);
		Node& operator=(Node&&);
		~Node();//���������� ������ ����������� ������������ Node �� ������

		friend class List; //��� ������ ������ List ����� ����� ������� � Node
	public:
		friend std::ostream& operator<<(std::ostream& os, const Node& n)
		{ // virtual prinf() ��� RTTI
			//os << n.m_Date; //??
			//os <<
			n.m_Data->print(os);
			return os;
		}

		friend std::ifstream& operator>>(std::ifstream& in, /*const*/ Node& n)
		{ 			
			n.m_Data->read(in);
			return in;
		}
		
		Node* getNext() const { return pNext; }
	};

	//������
	Node Head;	// ��������� �������, ������� �������� ��������� ������ ������
	Node Tail;	// ��������� �������, ������� �������� ��������� ����� ������
	Node* pHead;
	size_t m_size;	//���������� ���������
public:
	List(); //������������ Head, Tail � m_size 
	~List();
	List(const List&);
	List(List&&);
	List& operator=(List&&);
	List& operator=(const List&);
	//	�
	void AddHead(const Shape*);
	void AddTail(const Shape*);
	bool RemoveOne(const Shape*);
	int Cleaning();
	int RemoveAll(const Shape*);
	int  Size();
	void Sort();
	void out();
	bool compare(const Shape*, const Shape*);
	friend std::ostream& operator<<(std::ostream& os, const List& l);
	friend std::ifstream& operator>>(std::ifstream& in,/* const*/ List& l);
	};

std::ostream& operator<<(std::ostream& os, const List& l);
std::ifstream& operator>>(std::ifstream& in,/* const*/ List& l);