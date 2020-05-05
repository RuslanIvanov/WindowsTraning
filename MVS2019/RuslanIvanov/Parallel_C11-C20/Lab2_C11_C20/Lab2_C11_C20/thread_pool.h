#pragma once
#include <iostream>
#include <sstream>
#include <mutex>
#include <thread>
#include <queue>
#include <functional>

class thread_pool 
{
	mutable std::mutex m; //для безопасной многопоточной работы с очередью
	std::queue<std::function<void()>> tasks; //очередь заданий
	std::vector<std::thread> threads; //совокупность рабочих потоков
	bool stop = false; //по-хорошему это должна быть atomic-переменная
	void task_thread(); //потоковая функция (в общем случае с параметрами)
public:
	thread_pool();
	~thread_pool();
	void add_task(std::function<void()>); //в общем случае принимает параметры для задания
	thread_pool(const thread_pool&) = delete; 
	thread_pool& operator=(const thread_pool&) = delete;
};

