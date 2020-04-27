#pragma once
#include <iostream>
#include <mutex>
class ClassicSingleton
{
private:
	static ClassicSingleton *instance;
	std::mutex m;

public:

	static ClassicSingleton* getInstance();

	static ClassicSingleton* getInstanceForThread();

	ClassicSingleton();
	ClassicSingleton(ClassicSingleton const&) = delete; // ���������� �� �����
	ClassicSingleton& operator= (ClassicSingleton const&) = delete;  // � ���

	~ClassicSingleton();
	void printName();
};


/*
�������� (����. Singleton) � ����������� ������ ��������������, �������������, ��� � ������������ ����������
����� ������������ ��������� ���������� ������, � ��������������� ���������� ����� ������� � ����� ����������.
*/