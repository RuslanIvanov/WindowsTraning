#pragma once
#include <iostream>
#include <sstream>
#include <mutex>
#include <thread>
#include <queue>
#include <functional>
#include <condition_variable>
#include <atomic>
class thread_pool 
{
	mutable std::mutex m; //для безопасной многопоточной работы с очередью
	mutable std::mutex m_sinx_out; //для вывода
	std::condition_variable cv;

	std::queue<std::function<void()>> tasks; //очередь заданий
	std::vector<std::thread> threads; //совокупность рабочих потоков
	std::atomic<bool> m_stop; //по-хорошему это должна быть atomic-переменная
	static std::atomic<size_t> countTask;
	void task_thread_cv();
public:
	thread_pool();
	~thread_pool();
	void add_task(std::function<void()>&); //в общем случае принимает параметры для задания
	void add_task_cv(std::function<void()>&);
	void stopRun_cv();
	thread_pool(const thread_pool&) = delete; 
	thread_pool& operator=(const thread_pool&) = delete;
};

