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
