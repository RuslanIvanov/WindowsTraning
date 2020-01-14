#pragma once

#include "Circle.h"
class List
{
	//���������� ���������� ������ Node
	class Node
	{
		//������:
		Node* pPrev;		//��������� �� ���������� �������
		Node* pNext;		//��������� �� ��������� �������
		Circle m_Data;		//���������: ����� ����� ���� ���������� ������ ��� ��������� �� ���� (������������) ����� ������

	//������:
		Node();//������ ����� ����������� ��� �������� ��������������� ������� � �������� (Head, Tail)
	//	Node(/*�,*/ const Circle*);	//�����������, ����������� �������� ����������� Node �������������� � ������.
		Node(const Circle&, Node* next, Node* prev);
		~Node();//���������� ������ ����������� ������������ Node �� ������

		friend class List; //��� ������ ������ List ����� ����� ������� � Node
		friend std::ostream& operator<<(std::ostream& os, const Node& n)
		{
		os << n.m_Data;
		return os;
		}
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
	//	�
	void AddHead(const Circle&);
	void AddTail(const Circle&);
	bool RemoveOne(const Circle&);
	int Cleaning();
	int RemoveAll(const Circle&);
	int  Size();
	void Sort();

	friend std::ostream& operator<<(std::ostream& os, const List& l);
	};

std::ostream& operator<<(std::ostream& os, const List& l);
