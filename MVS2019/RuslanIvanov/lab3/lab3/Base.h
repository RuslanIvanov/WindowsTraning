#pragma once
#include "Pair.h"
class Base
{
	Pair* pBase; //Pair**pBase;//указатель на базу данных
	size_t count; //количество элементов в базе
	size_t capacity; //емкость базы

public:
	Base() { count = 0; capacity = 10; }
	~Base() {}

	Base(const Base& bd);
	Base& operator=(const Base& bd); //оптимизированный!!!
	Base(Base&& bd);
	Base& operator=(Base&& bd);
	Data& operator[](const char* key);
	int deletePair(const char* key);
};

