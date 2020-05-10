#pragma once
#include <atomic>
#include <iostream>
#include <shared_mutex>
#define SPINLOCK

class spinlock
{
	std::atomic_flag f{ ATOMIC_FLAG_INIT };
	static size_t count;
	std::atomic<int> a{0};
	std::atomic<int> numLock{ 0 };
	
	public:

		spinlock() = default;
		void lock();
		void unlock();
		bool try_lock();
		void lock_shared();
		void unlock_shared();


};

