#include "ClassicSingleton.h"

ClassSingleton* ClassSingleton::getInstance()
{
	//if (instance == nullptr){instance = new ClassSingleton();}	return instance;

	static ClassSingleton singletone;
	return &singletone;
}

void ClassSingleton::printName() { std::cout << "\nClassSingleton"; }


 ClassSingletonThread* ClassSingletonThread::getInstance() 
{
	 static thread_local ClassSingletonThread singletone;
	 return &singletone;
}

void ClassSingletonThread::printName() { std::cout << "\nClassSingletonThread"; }