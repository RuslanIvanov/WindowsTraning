#include <iostream>
#include "List.h"

List::Node::Node() : pPrev(nullptr), pNext(nullptr) {}
List::Node::Node(const Circle& r, Node* tail, Node* head): m_Data(r)
{//���� head = &Head

	if (head && tail == nullptr)
	{
		pPrev = head;//��� ������ �������� pPrev ������ &Head
		pNext = head->pNext;//��������� ���� ������� �.�. &Tail

		head->pNext = this; //� ������ ������������� pNext ����� ������. ��������
		pNext->pPrev = this; // ������ ������ ����� ������������� ��.
	}
	else if (head == nullptr && tail)
	{
		pNext = tail;// ����� ����
		pPrev = tail->pPrev;/// �� ���  ���� � ������ ����������
		pPrev->pNext = this;// tail->pPrev->pNext = this;// ���� � ���� ���  ����� ���������
		
		tail->pPrev = this;// � ������ ���� ����������

	}
	else
	{
		//?? 
		//��� ��� Node(����������) private ����� �� ������������ �����
	}
}
List::Node::~Node()
{
	//���� ���� ����� �����
	if (pPrev)
	{//������ ������� ���  ����� ���������� �� ������� � ���������� �������� ���
		pPrev->pNext = this->pNext;
	}

	if (pNext)
	{// ������ ����� ���. ������ ����������� , ������� ��� �������� � ����������
		pNext->pPrev = this->pPrev;
	}
}

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
	new Node(c, nullptr, &Head); // &Head - ��������� �������� ������
	m_size++;
}
void List::AddTail(const Circle& c) 
{
	new Node(c, &Tail,nullptr);
}
bool List::RemoveOne(const Circle& c) 
{
	// ��������� �� ������ ������
	Node* p = Head.pNext;
	while (p!=&Tail) //���� ������� ��������� �� ����� ������
	{
		if (c == p->m_Data)
		{
			delete p; //~Node () ��������� ������
			m_size--;

			return true;
		}
		 
		p = p->pNext;// ��������� ������� � ������

	}

	return false;
}
int List::RemoveAll(const Circle& �) 
{ 
	int count = 0;
	Node* p = Head.pNext;
	while (p != &Tail) //���� ������� ��������� �� ����� ������
	{
		if (� == p->m_Data)
		{
			delete p;
			m_size--;

			count++;
		}

		p = p->pNext;// ��������� ������� � ������

	}

	return count;
}

int List::Cleaning()
{ 
	Node* p = Head.pNext;
	int count = 0;
	while (p != &Tail) //���� ������� ��������� �� ����� ������
	{
		delete p;
		m_size--;
		p = p->pNext;
		count++;
	}
	return count;  
}


int List::Size()
{
	return m_size;
}

void List::Sort()
{
		Node* p = Head.pNext;
		while (p != &Tail) 
		{//����� ������������ �� ���������� ��������
		
			Node* pMin = p;// ����� ��� �� ������ ������
			Node* p1 = p->pNext; // ��� ���������� �������
			while (p1)// ���� �� ����� ������
			{// ��������� ����� � ��� 
				if (p1->m_Data < pMin->m_Data)// ��������� D
				{// ����������� ������� ������, ���������� ����� ��� Node
					pMin = p1; // �������������� ����
				}
				p1 = p1->pNext;// ����� ���� ��� ��� ���������
			}
			//����� ������� �������� � ����������� Circle
			Circle tmp = pMin->m_Data;
			pMin->m_Data = p->m_Data; 
			p->m_Data = tmp; 
	
			p = p->pNext;
		}

}

std::ostream& operator<<(std::ostream& os, const List& l)
{	

/*	List::Node* p = l.Head;
	
	while (p != 0)
	{
		os << p->m_Data;
		p = p->List::pNext;
	}

	*/
	return os;
}
