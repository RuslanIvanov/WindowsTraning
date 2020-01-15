#include <iostream>
#include "Pair.h"

Pair::Pair(): key("empty"), data(Data()) { } //move for Data()
Pair::Pair(const char* k, const Data& d):key(k),data(d) { }

Pair::Pair(const Pair& r) 
{
	data = r.data;
	key = r.key;
}

Pair::Pair( Pair&& r) 
{
	data = std::move(r.data);
	key = std::move(r.key);

	//r.data = Data();
	//r.key = MyString();
}

bool Pair::operator == (const char* k) const 
{
	//return false;
	//return (k == key);//глоб оператор ==
	return (key == k); //оператор == перегрузить	
}

Pair& Pair::operator=(const Pair& r)
{
	if (this == &r)
	{
		return *this;
	}

	data = r.data;
	//data.operator=(r.data);
	key = r.key;
	//key.operator=(r.key);

	return *this;
}

Pair& Pair::operator=(Pair&& r)
{
	if (this == &r)
	{
		return *this;
	}

	data = r.data;
	key = r.key;

	r.data = Data();// move
	r.key = MyString();//move

	return *this;
}

std::ostream& operator<<(std::ostream& os, const Pair& pair)
{
	os << "|name: " << pair.key <<" "<< pair.data;
	return os;
}