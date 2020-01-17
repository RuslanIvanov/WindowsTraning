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

List::Node::Node(Node&& r)
{
	m_Data = r.m_Data;
	pNext = r.pNext;
	pPrev = r.pPrev;

	r.pNext = nullptr;
	r.pPrev = nullptr;
}

List::Node::~Node()
{
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

List& List::operator=(const List& l)
{
	if (this == &l) { return *this; }

	m_size = l.m_size;

	Cleaning();

	Head.pNext = &Tail;
	Tail.pPrev = &Head;

	Node* pOther = l.Head.pNext;
	Node* pThis = &Head;

	for (size_t i = 0; i < m_size; i++)
	{
		pThis = new Node(pOther->m_Data, nullptr, pThis);
		pOther = pOther->pNext;

	}

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
	/*Node* pN = l.Head.pNext;
	Node* pT = l.Tail.pPrev;
	Node* pN_new = Head.pNext;
	Node* pT_new = Tail.pPrev;

	for (size_t i = 0; i < m_size-; i++)
	{
		pN_new->pNext = pN->pNext;
		pN_new->pPrev = pN->pPrev;

		pN=pN->pNext;
		//pT = pN->pPrev;

		pN_new = pN_new->pNext;
		//pT_new = pT_new->pPrev;

		//delete l.Head.pNext;// ������� ������������
	}//*/

	l.Head.pNext = nullptr;
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

	for (size_t i = 0; i < m_size; i++)
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

void List::AddHead(const Circle& c)
{// ��� ��� ��������� � ������., �� ����� ������
	new Node(c, nullptr, &Head); // &Head - ��������� �������� ������
	m_size++;
}
void List::AddTail(const Circle& c) 
{
	new Node(c, &Tail,nullptr);
	m_size++;
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
	List::Node* p = Head.pNext;
	while (p != &Tail) //���� ������� ��������� �� ����� ������
	{
		if (� == p->m_Data)
		{
			//delete p;
			m_size--;
			p = p->pNext;
			delete p->pPrev;
			count++;
			//continue;
		}
		else
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
		//delete p;
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
{	//� Release ������ �������� (?)
	
	const List::Node* p =  l.Head.getNext();//// const ???

	while (p != &l.Tail)
	{
		os << "\n";
		os << (*p);//Node.m_Data;
		p = p->getNext();
	}
		
	return os;
}
