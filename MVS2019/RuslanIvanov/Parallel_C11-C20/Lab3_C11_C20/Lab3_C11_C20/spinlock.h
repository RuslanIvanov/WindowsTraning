#pragma once
#include <atomic>
#include <iostream>
class spinlock
{
	std::atomic_flag f{ ATOMIC_FLAG_INIT };

	
	public:

		spinlock() = default;
		void lock();
		void unlock();
		bool try_lock();


};

