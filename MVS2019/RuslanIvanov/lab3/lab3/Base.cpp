#include <iostream>
#include "Base.h"

Base::Base(const Base& bd) 
{
}

Base& Base::operator=(const Base& bd)
{
	return *this;
}

Base::Base(Base&& bd) 
{
}

Base& Base::operator=(Base&& bd) 
{
	return *this;
}

Data& Base::operator[](const char* key) 
{
	static Data d;
	return d;
}

int Base::deletePair(const char* key) 
{
	return 0;
}
