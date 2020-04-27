#pragma once
#include <iostream>
#include <mutex>
class ClassicSingleton
{
private:
	static ClassicSingleton *instance;
	static thread_local ClassicSingleton* instanceTh;
	std::mutex m;

public:

	static ClassicSingleton* getInstance();
	static void setNullForTh() { instanceTh = nullptr; };
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