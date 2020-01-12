#include <iostream>
#include "List.h"

List::List() 
{
	m_size = 0; // ������ ����
	pHead = nullptr;
	Head.pNext = &Tail;
	Tail.pPrev = &Head;
}

List::~List() 
{
	for (size_t i = 0; i < m_size; i++)
	{
		delete Head.pNext;
	}
}

List::List(const List& l)
{
	m_size = l.m_size;
	//����_� Head & Tail ��� ��� �� ����� ���� � ����� ����������
	Head.pNext = &Tail;
	Tail.pPrev = &Head;

	Node* pOther = l.Head.pNext;// ����� ������ ���������� ����������� 
	Node* pThis = &Head;

	for (size_t i = 0; i < m_size; i++)
	{
		pThis = new Node(pOther->m_Data, nullptr, pThis);
		pOther = pOther->pNext; //����� ������ ���������� ��� ����������� � �������� � ����������� Node

	}
}

void List::AddHead(const Circle& c)
{// ��� ��� ��������� � ������., �� ����� ������
	new Node(c, NULL, &Head); // &Head - ��������� �������� ������
	m_size++;
}
void List::AddTail(const Circle&) {}
bool List::RemoveOne(const Circle& c) 
{
	// ��������� �� ������ ������
	Node* p = Head.pNext;
	while (p!=&Tail) //���� ������� ��������� �� ����� ������
	{
		if (c == p->m_Data)
		{
			delete p; 
			m_size--;

			return true;
		}
		 
		p = p->pNext;// ��������� ������� � ������

	}

	return false;
}

bool List::Cleaning() { return false;  }
int List::RemoveAll(const Circle&) { return 0; }

int List::Size()
{
	size_t i = 0;
	for (; i < m_size; i++)
	{

	}

	return i;
}

void List::Sort(){}

std::ostream& operator<<(std::ostream& os, const List& l)
{
	for (size_t i = 0; i < l.m_size; i++)
	{
		os << "#" << i + 1 << l.Head;
	}

	return os;
}