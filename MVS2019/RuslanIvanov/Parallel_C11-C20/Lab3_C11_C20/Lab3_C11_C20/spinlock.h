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
	

	/////////////////////////////////////////
	unsigned long m_num_readers=0;
	unsigned long m_write_entered = 0;
	unsigned long m_state = 0;
	static const unsigned long m_max_readers = -1;// 32 потока => 32 бита
	public:
		
		spinlock(const spinlock&) = delete;
		~spinlock() = default;
		spinlock() = default;

		void lock();
		void unlock();
		bool try_lock();
		void lock_shared();
		void unlock_shared();

		//////////////////////////////////////
		private:
        unsigned long number_of_readers() const;
        bool maximal_number_of_readers_reached() const;
        bool someone_has_exclusive_lock() const;
        void increment_readers();
        void decrement_readers();
     
        void do_lock_shared();
        void do_unlock_shared();
      
};

/*
Test-and-set — простая неразрывная (атомарная) процессорная инструкция, которая копирует значение переменной в регистр, 
и устанавливает некое новое значение. Во время исполнения данной инструкции процессор не может прервать её выполнение и переключиться
на выполнение другого потока. Если используется многопроцессорная архитектура, то, пока один процессор выполняет эту инструкцию с ячейкой памяти, 
другие процессоры не могут получить доступ к этой ячейке, что может достигаться путём кратковременного блокирования шины памяти.
*/