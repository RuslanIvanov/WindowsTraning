#include <iostream>
#include "Node.h"

Node::Node(): pPrev(nullptr), pNext(nullptr) {}
Node::Node(const Circle& �, Node* next, Node* prev) 
{//���� prev = &Head
	pPrev = prev;//��� ������ �������� pPrev ������ &Head
	pNext = prev->pNext;//��������� ���� ������� �.�. &Tail

	prev->pNext = this; //� ������ ������������� pNext ����� ������. ��������
	pNext->pPrev = this; // ������ ������ ����� ������������� ��.
}
Node::~Node() 
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

std::ostream& operator<<(std::ostream& os, const Node& n)
{
	os << n.m_Data;
	return os;
}