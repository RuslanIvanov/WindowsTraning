#pragma once
#include "Pair.h"
class Base
{
	Pair* pBase; //Pair**pBase;//��������� �� ���� ������
	size_t count; //���������� ��������� � ����
	size_t capacity; //������� ����

public:
	Base();
	~Base();

	Base(const Base& bd);
	Base& operator=(const Base& bd); //����������������!!!
	Base(Base&& bd);

	Base& operator=(Base&& bd);
	Data& operator[](const char* key);

	int deletePair(const char* key);

	friend std::ostream& operator<<(std::ostream& os, const Base& d);
};

std::ostream& operator<<(std::ostream& os, const Base& d);

