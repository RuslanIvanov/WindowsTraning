#pragma once
#include "Pair.h"
class Base
{
	Pair* pBase; //Pair**pBase;//��������� �� ���� ������
	size_t count; //���������� ��������� � ����
	size_t capacity; //������� ����

public:
	Base() { count = 0; capacity = 10; }
	~Base() {}

	Base(const Base& bd);
	Base& operator=(const Base& bd); //����������������!!!
	Base(Base&& bd);
	Base& operator=(Base&& bd);
	Data& operator[](const char* key);
	int deletePair(const char* key);
};

