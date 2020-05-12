#pragma once
#include <vector>
#include <iostream>
#include <thread>
#include <mutex>
#include <shared_mutex>
#include <algorithm>
class threadsafe_stack
{
	mutable std::shared_mutex m_mut;
	const size_t N = 10;
	std::vector<int> m_v;
public:

	threadsafe_stack() { m_v.reserve(N); }

	threadsafe_stack(const threadsafe_stack&);
	threadsafe_stack(threadsafe_stack&&);
	threadsafe_stack& operator=(threadsafe_stack&& st);
	threadsafe_stack& operator=(const threadsafe_stack& st);

	void push(int );
	int top() const;
	void pop(int&);
	bool empty() const;
	size_t size() const;

	void sh_lock() const { m_mut.lock_shared(); }
	void sh_unlock() const  { m_mut.unlock_shared(); }

	void lock() const { m_mut.lock(); }
	void unlock() const { m_mut.unlock(); }

	void print() const
	{
		sh_lock();
		for (size_t pos = 0; pos < m_v.size(); pos++)
		{
			std::cout << m_v[pos] << std::endl;
		}
		sh_unlock();
	}
};

void fReaders(threadsafe_stack& s);
void fWriters(threadsafe_stack& s,int);

/*
 std::shared_mutex:
¬ эксклюзивном он ведет себ€ так же, как и стандартный класс mutex.≈сли же поток заблокирует его в коллективном режиме, 
то другие потоки также могут заблокировать его в этом режиме.ќн будет разблокирован, как только последний владелец блокировки 
в коллективном режиме освободит его.ѕока мьютекс заблокирован в коллективном режиме, его нельз€ заблокировать в эксклюзивном*/