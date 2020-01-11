#pragma once
#include "myString.h"
#include "Data.h"

class Pair
{
	MyString key;//���� - �������
	Data data;// MyData* pData;//������ � ����������

	Pair();
	Pair(const char* k, const Data& d);

	Pair(const Pair&);
	Pair(Pair&&);

	Pair& operator=(const Pair& other);
	Pair& operator=(Pair&& other);

	bool operator == (const char* k) const;

	friend class Base;
	friend std::ostream& operator<<(std::ostream& os, const Pair& pair);
};

std::ostream& operator<<(std::ostream& os, const Pair& pair);
