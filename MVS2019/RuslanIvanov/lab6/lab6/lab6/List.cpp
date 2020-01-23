#include <iostream>
#include "List.h"

List::Node::Node() : pPrev(nullptr), pNext(nullptr) {}
List::Node::Node(const Shape* r, Node* tail, Node* head)
{//���� head = &Head

	if (head && tail == nullptr)
	{
		pPrev = head;//��� ������ �������� pPrev ������ &Head
		pNext = head->pNext;//��������� ���� ������� �.�. &Tail

		head->pNext = this; //� ������ ������������� pNext ����� ������. ��������
		pNext->pPrev = this; // ������ ������ ����� ������������� ��.

		// RTTI ��� :
		m_Data = r->clone(); //������������ �����
	}
	else if (head == nullptr && tail)
	{
		pNext = tail;// ����� ����
		pPrev = tail->pPrev;/// �� ���  ���� � ������ ����������
		pPrev->pNext = this;// tail->pPrev->pNext = this;// ���� � ���� ���  ����� ���������
		
		tail->pPrev = this;// � ������ ���� ����������

		// RTTI:

		const Rect* pR = dynamic_cast<const Rect*>(r);
		if(pR!=0)	
		{ m_Data = new Rect(*pR); }
		else 
			{ m_Data = new Circle(*(dynamic_cast<const Circle*>(r))); }
	}
	else
	{
		//��� ��� Node(����������) private ����� �� ������������ �����
	}
}

List::Node::Node(Node&& r)
{
	m_Data = r.m_Data;
	pNext = r.pNext;
	pPrev = r.pPrev;

	r.pNext = nullptr;
	r.pPrev = nullptr;
	r.m_Data = nullptr;
}

List::Node& List::Node::operator=(Node&& r)
{
	if (this == &r) return *this;

	delete m_Data;

	m_Data = r.m_Data;
	pNext = r.pNext;
	pPrev = r.pPrev;

	r.pNext = nullptr;
	r.pPrev = nullptr;
	r.m_Data = nullptr;
}

List::Node::~Node()
{
	delete this->m_Data;

	//���� ���� ����� �����
	if (pPrev)
	{//������ ������ ���  ����� ���������� �� ������� � ���������� �������� ���
		
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

List& List::operator=(const List& l)//  ������.
{
	if (this == &l) { return *this; }

	Node* pOther = l.Head.pNext;
	Node* pThis = Head.pNext;

	if (m_size >= l.m_size)
	{
		for (size_t ii = 0; ii < m_size; ii++)
		{			
			if (ii < l.m_size)
			{
				*pThis->m_Data = *pOther->m_Data;	//���������� ������� ����� ����
				pThis = pThis->pNext;
				pOther = pOther->pNext;
			}
			else 
			{
				pThis = pThis->pNext;
				delete pThis->pPrev;
			}	
			
		}
	}
	else 
	{//m_size < l.m_size
		
		for (size_t ii = 0; ii < l.m_size; ii++)
		{
			if (ii < m_size)
			{
				*pThis->m_Data = *pOther->m_Data;
				pThis = pThis->pNext;
				pOther = pOther->pNext;
			}
			else
			{
				AddTail(pOther->m_Data);
				pOther = pOther->pNext;
			}

		}
	}
		
	m_size = l.m_size;
	
	return *this;
}

List::List(List&& l)
{//����� ������� �� ������������ �������

	Head.pNext = l.Head.pNext;
	Head.pPrev = l.Head.pPrev;
	Tail.pNext = l.Tail.pNext;
	Tail.pPrev = l.Tail.pPrev;

	pHead = l.pHead;
	m_size = l.m_size;
	/////////////////////////////////
	l.Head.pNext->pPrev = &Head;
	l.Tail.pPrev->pNext = &Tail;
	/////////////////////////////////
	
	l.Head.pNext = nullptr;//&l.Tail;
	l.Head.pPrev = nullptr;
	l.Tail.pPrev = nullptr;
	l.Tail.pNext = nullptr;
	l.m_size = 0;
	l.pHead = nullptr;
}

List& List::operator=(List&& l) 
{
	if (this == &l) 
	{ 
		return *this; 
	}

	for (size_t i = 0; i < m_size; i++)//OK
	{
		delete Head.pNext;
	}

	Head.pNext = l.Head.pNext;
	Head.pPrev = l.Head.pPrev;
	Tail.pNext = l.Tail.pNext;
	Tail.pPrev = l.Tail.pPrev;

	l.Head.pNext->pPrev = &Head;
	l.Tail.pPrev->pNext = &Tail;

	pHead = l.pHead;
	m_size = l.m_size;

	l.Head.pNext = nullptr;
	l.Head.pPrev = nullptr;
	l.Tail.pPrev = nullptr;
	l.Tail.pNext = nullptr;
	l.m_size = 0;
	l.pHead = nullptr;

	return *this;
}

void List::AddHead(const Shape* c)
{// ��� ��� ��������� � ������., �� ����� ������
	new Node(c, nullptr, &Head); // &Head - ��������� �������� ������
	m_size++;
}
void List::AddTail(const Shape* c) 
{
	new Node(c, &Tail,nullptr);
	m_size++;
}
bool List::RemoveOne(const Shape* c) 
{
	// ��������� �� ������ ������
	Node* p = Head.pNext;
	while (p!=&Tail) //���� ������� ��������� �� ����� ������
	{
		if (*c == *p->m_Data)
		{

			delete p; //~Node () ��������� ������
			m_size--;

			return true;
		}
		 
		p = p->pNext;// ��������� ������� � ������

	}

	return false;
}
int List::RemoveAll(const Shape* �) 
{ // ������� ��� ����� Circle !!! 
	int count = 0;
	List::Node* p = Head.pNext;
	while (p != &Tail) //���� ������� ��������� �� ����� ������
	{
		Node* pnext = p->pNext;
		if (*� == *p->m_Data)
		{
			delete p;//�������� NN
			m_size--;
		
			count++;		
		}
		p=pnext;//NN
	}

	return count;
}

int List::Cleaning()
{ 
	Node* p = Head.pNext;
	int count = 0;
	while (p != &Tail) //���� ������� ��������� �� ����� ������
	{
		m_size--;
		p = p->pNext;
		delete p->pPrev;
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
			while (p1 != &Tail)
			{// ��������� ����� � ��� 
				if (*p1->m_Data < *pMin->m_Data)// ��������� �� S
				{// ����������� ������� ������, ���������� ����� ��� Node
					pMin = p1; // �������������� ����
				}
				p1 = p1->pNext;// ����� ���� ��� ��� ���������
			}
			//����� ������� �������� � ����������� 
			
			//������ ������ � �����
			Shape *tmp = pMin->m_Data;//�� ������, ���� ������ ����
			pMin->m_Data = p->m_Data; 
			p->m_Data = tmp; 
	
			p = p->pNext;
		}

}

void List::out()
{
	Node* p = Head.pNext;
	while (p != &Tail)
	{
		std::cout << "\nout: ";
		std::cout << p->m_Data;
		p = p->pNext;
	}
}

std::ostream& operator<<(std::ostream& os, const List& l)
{
	
	const List::Node* p =  l.Head.getNext();

	while (p != &l.Tail)
	{
		os << "\n";
		os << (*p);//Node.m_Data;
		p = p->getNext();
	}
		
	return os;
}
