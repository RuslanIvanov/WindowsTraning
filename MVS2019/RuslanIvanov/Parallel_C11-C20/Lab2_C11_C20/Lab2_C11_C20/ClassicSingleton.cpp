#include "ClassicSingleton.h"

ClassicSingleton* ClassicSingleton::instance;

ClassicSingleton* ClassicSingleton::getInstance()
{
	if (instance == nullptr)
	{
		instance = new ClassicSingleton();
	}

	return instance;
};

ClassicSingleton* ClassicSingleton::getInstanceForThread()
{

}

ClassicSingleton::ClassicSingleton() {};
ClassicSingleton::~ClassicSingleton() { delete instance;  }
void ClassicSingleton::printName() { std::cout << "\nClassicSingleton"; }