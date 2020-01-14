#pragma once

#include "Circle.h"
class List
{
	//встроенное объ€вление класса Node
	class Node
	{
		//ƒанные:
		Node* pPrev;		//указатель на предыдущий элемент
		Node* pNext;		//указатель на следующий элемент
		Circle m_Data;		//«амечание: здесь может быть встроенный объект или указатель на свою (динамическую) копию данных

	//ћетоды:
		Node();//скорее всего понадобитс€ дл€ создани€ вспомогательных оберток Ц Ђстражейї (Head, Tail)
	//	Node(/*Е,*/ const Circle*);	//конструктор, посредством которого создаваемый Node Ђподключаетс€ї в список.
		Node(const Circle&, Node* next, Node* prev);
		~Node();//деструктор должен Ђисключатьї уничтожаемый Node из списка

		friend class List; //все методы класса List имеют права доступа к Node
		friend std::ostream& operator<<(std::ostream& os, const Node& n)
		{
		os << n.m_Data;
		return os;
		}
	};

	//данные
	Node Head;	// фиктивный элемент, который €вл€етс€ признаком начала списка
	Node Tail;	// фиктивный элемент, который €вл€етс€ признаком конца списка
	Node* pHead;
	size_t m_size;	//количество элементов
public:
	List(); //сформировать Head, Tail и m_size 
	~List();
	List(const List&);
	//	Е
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
