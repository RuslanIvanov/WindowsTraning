#pragma once
#include <iostream>
#include <sstream>
#include <mutex>
#include <thread>
#include <queue>
#include <functional>
#include <condition_variable>

class thread_pool 
{
	mutable std::mutex m; //для безопасной многопоточной работы с очередью
	std::condition_variable cv;
	//std::unique_lock
	std::queue<std::function<void()>> tasks; //очередь заданий
	std::vector<std::thread> threads; //совокупность рабочих потоков
	bool m_stop; //по-хорошему это должна быть atomic-переменная
	void task_thread(); //потоковая функция (в общем случае с параметрами)
public:
	thread_pool();
	~thread_pool();
	void add_task(std::function<void()>&); //в общем случае принимает параметры для задания
	bool isEmpty();
	void stopRun();
	thread_pool(const thread_pool&) = delete; 
	thread_pool& operator=(const thread_pool&) = delete;
};

