#include <iostream>
#include "Base.h"

Base::Base() 
{ 
	count = 0; 
	capacity = 10; 

	pBase = new Pair[capacity];//def constructor
}

Base::Base(const Base& base) 
{
	capacity = base.capacity;
	count = base.count;

	pBase = new Pair[capacity];

	for (size_t i = 0; i < base.count; i++)
	{
		pBase[i] = base.pBase[i];//pBase[i].operator=(base.pBase[i]) для Pair
	}
}

Base::~Base()
{
	delete[] pBase;
}

Base& Base::operator=(const Base& base)
{//условно затираем ту базу в которую копруем (пока так)
	if (&base == this) { return *this; }

	capacity = base.capacity; 
	count = base.count;
	//надо проанализировать емкость base.capacity > capacity

	if (base.capacity > capacity)
	{
		delete[] pBase;
		Pair* pBase = new Pair[base.capacity];
	}

	for (size_t i = 0; i < base.count; i++)
	{
		pBase[i] = base.pBase[i];
	}

	return *this; 
}

Base::Base(Base&& base) 
{
	capacity = base.capacity;
	count = base.count;
	pBase = base.pBase;

	base.capacity = 0;
	base.count = 0;
	base.pBase = nullptr;
}

Base& Base::operator=(Base&& base) 
{
	if (&base == this) { return *this; }

	capacity = base.capacity;
	count = base.count;
	pBase = base.pBase;

	base.capacity = 0;
	base.count = 0;
	base.pBase = nullptr;

	return *this;
}

Data& Base::operator[](const char* key) 
{
	for (size_t i = 0; i < capacity; i++)
	{
		if (pBase[i] == key)//pBase[i].operator=(key)
		{
			return pBase[i].data;
		}

		//ключа нет - вставка
		if (i >= capacity)
		{// места нет - перераспределение памяти
			capacity += 10;
			Pair* p = new Pair[capacity];// def constructor
			//копия данных в выделеную память
			for (size_t c = 0; c < count; c++)
			{
				p[c] = std::move(pBase[c]);
			}
			delete[] pBase; // удалить не нужно
			pBase = p;
		}
		//добавление нового ключа
		pBase[i].key = key; 
		//pBase[i].key.operator=(key);
		count++;
		return pBase[i].data; 
	}

	return pBase[0].data; // первая строка пустой базы
}

int Base::deletePair(const char* key) 
{
	size_t i = 0;
	for (; i < count; i++)
	{
		if (pBase[i] == key)//pBase[i].operator==(key)
		{
			pBase[i] = Pair();//move
			count--;
			return i;
		}
	}

	return i;
}

/////////////////////////////////////////////////////////
std::ostream& operator<<(std::ostream& os, const Base& db)
{

	if (db.count == 0) { os << "\nDB is empty!!!\n"; return os; }

	for (size_t i = 0; i < db.count; i++)
	{
		os << "\nN[" << i + 1 << "]: " << db.pBase[i];
	}
	os << "\n";
	return os;
}