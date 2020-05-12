#pragma once
#include <iostream>
#include <mutex>
class ClassSingleton
{
	ClassSingleton() = default;
public:

	static ClassSingleton* getInstance();

	//ClassSingleton() = default;
	ClassSingleton(ClassSingleton const&) = delete; // реализаци€ не нужна
	ClassSingleton& operator= (ClassSingleton const&) = delete;  // и тут

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
	ClassSingletonThread(ClassSingletonThread const&) = delete; // реализаци€ не нужна
	ClassSingletonThread& operator= (ClassSingletonThread const&) = delete;  // и тут

	~ClassSingletonThread() = default;
	void printName();
};

/*
ќдиночка (англ. Singleton) Ч порождающий шаблон проектировани€, гарантирующий, что в однопоточном приложении
будет единственный экземпл€р некоторого класса, и предоставл€ющий глобальную точку доступа к этому экземпл€ру.
*/