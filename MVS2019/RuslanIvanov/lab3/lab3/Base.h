#pragma once
#include "Pair.h"
class Base
{
	Pair* pBase; //Pair**pBase;//указатель на базу данных
	size_t count; //количество элементов в базе
	size_t capacity; //емкость базы

public:
	Base();
	~Base();

	Base(const Base& bd);
	Base& operator=(const Base& bd); //оптимизированный!!!
	Base(Base&& bd);

	Base& operator=(Base&& bd);
	Data& operator[](const char* key);

	int deletePair(const char* key);

	friend std::ostream& operator<<(std::ostream& os, const Base& d);
};

std::ostream& operator<<(std::ostream& os, const Base& d);

