#include <iostream>
#include "Pair.h"

Pair::Pair(): key("empty"), data(Data()) { } //?? Data()
Pair::Pair(const char* k, const Data& d):key(k),data(d) { }
Pair::Pair(const Pair& r) 
{

}

Pair::Pair( Pair&& r) 
{

}

bool Pair::operator == (const char* k) const 
{
	//return false;
	//return (k == key);//глоб оператор ==
	return (key == k); //оператор == перегрузить	
}