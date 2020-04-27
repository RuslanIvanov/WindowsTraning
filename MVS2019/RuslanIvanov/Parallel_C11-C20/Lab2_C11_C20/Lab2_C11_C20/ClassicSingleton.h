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
	ClassicSingleton(ClassicSingleton const&) = delete; // реализаци€ не нужна
	ClassicSingleton& operator= (ClassicSingleton const&) = delete;  // и тут

	~ClassicSingleton();
	void printName();
};


/*
ќдиночка (англ. Singleton) Ч порождающий шаблон проектировани€, гарантирующий, что в однопоточном приложении
будет единственный экземпл€р некоторого класса, и предоставл€ющий глобальную точку доступа к этому экземпл€ру.
*/