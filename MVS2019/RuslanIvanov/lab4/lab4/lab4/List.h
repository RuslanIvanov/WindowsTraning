#pragma once
#include "Node.h"
class Node;
class List
{
	//���������� ���������� ������ Node

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
	bool Cleaning();
	int  RemoveAll(const Circle&);
	int  Size();
	void Sort();

	friend std::ostream& operator<<(std::ostream& os, const List& l);

	};

std::ostream& operator<<(std::ostream& os, const List& l);