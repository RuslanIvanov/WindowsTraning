#pragma once
#include <vector>
#include <iostream>
#include <thread>
#include <mutex>
#include <shared_mutex>
class threadsafe_stack
{
	mutable std::shared_mutex m_mut;
	static unsigned short countReads;
	const size_t N = 10;
	std::vector<int> m_v;
public:

	threadsafe_stack() { m_v.reserve(N); }

	threadsafe_stack(const threadsafe_stack&);
	threadsafe_stack(threadsafe_stack&&);
	threadsafe_stack& operator=(threadsafe_stack&& st);
	threadsafe_stack& operator=(threadsafe_stack& st);

	void push(int );
	int top() const;
	void pop(int&);
	bool empty();
	size_t size();
};

void fReaders(threadsafe_stack& s);
void fWriters(threadsafe_stack& s,int);

/*
 std::shared_mutex:
¬ эксклюзивном он ведет себ€ так же, как и стандартный класс mutex.≈сли же поток заблокирует его в коллективном режиме, 
то другие потоки также могут заблокировать его в этом режиме.ќн будет разблокирован, как только последний владелец блокировки 
в коллективном режиме освободит его.ѕока мьютекс заблокирован в коллективном режиме, его нельз€ заблокировать в эксклюзивном*/