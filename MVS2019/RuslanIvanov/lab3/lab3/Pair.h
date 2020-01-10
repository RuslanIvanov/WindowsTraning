#pragma once
#include "myString.h"
#include "Data.h"
//#include "Base.h"

class Pair
{
	MyString key;//���� - �������
	Data data;// MyData* pData;//������ � ����������
	Pair();
	Pair(const char* k, const Data& d);

	Pair(const Pair&);
	Pair(Pair&&);

	bool operator == (const char* k) const;
	friend class Base;
};

