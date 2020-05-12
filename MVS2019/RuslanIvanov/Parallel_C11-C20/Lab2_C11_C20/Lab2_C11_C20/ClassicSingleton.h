#pragma once
#include <iostream>
#include <mutex>
class ClassSingleton
{
	ClassSingleton() = default;
public:

	static ClassSingleton* getInstance();

	//ClassSingleton() = default;
	ClassSingleton(ClassSingleton const&) = delete; // ���������� �� �����
	ClassSingleton& operator= (ClassSingleton const&) = delete;  // � ���

	~ClassSingleton() = default;
	void printName();
};


class ClassSingletonThread
{
	ClassSingletonThread() = default;
public:

	static ClassSingletonThread* getInstance();
	//static void setNull() { ClassSingletonThread = nullptr; };
	
	//ClassSingletonThread() = default;
	ClassSingletonThread(ClassSingletonThread const&) = delete; // ���������� �� �����
	ClassSingletonThread& operator= (ClassSingletonThread const&) = delete;  // � ���

	~ClassSingletonThread() = default;
	void printName();
};

/*
�������� (����. Singleton) � ����������� ������ ��������������, �������������, ��� � ������������ ����������
����� ������������ ��������� ���������� ������, � ��������������� ���������� ����� ������� � ����� ����������.
*/