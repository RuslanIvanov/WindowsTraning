#pragma once
#include "myString.h"
#include "Data.h"
//#include "Base.h"

class Pair
{
	MyString key;//ключ - фамилия
	Data data;// MyData* pData;//данные о сотруднике
	Pair();
	Pair(const char* k, const Data& d);

	Pair(const Pair&);
	Pair(Pair&&);

	bool operator == (const char* k) const;
	friend class Base;
};

