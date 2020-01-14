#pragma once

#include "Circle.h"
#include "List.h"

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
	friend std::ostream& operator<<(std::ostream& os, const Node& n);
};

std::ostream& operator<<(std::ostream& os, const Node& n);



