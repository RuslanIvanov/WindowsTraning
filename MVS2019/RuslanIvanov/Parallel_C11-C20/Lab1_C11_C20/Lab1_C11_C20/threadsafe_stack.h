#pragma once
#include <vector>
#include <iostream>
#include <thread>
#include <mutex>
#include <shared_mutex>
class threadsafe_stack
{
	mutable std::shared_mutex m_mut;
	const size_t N = 10;
	std::vector<int> m_v;
public:

	threadsafe_stack() { m_v.resize(N); }

	threadsafe_stack(const threadsafe_stack&);
	threadsafe_stack(threadsafe_stack&&);
	threadsafe_stack& operator=(threadsafe_stack&& st);
	threadsafe_stack& operator=(threadsafe_stack& st);
	void push(int );
	void top(int&) const;
	void pop(int&) const;
	bool empty();
	size_t size();
};

