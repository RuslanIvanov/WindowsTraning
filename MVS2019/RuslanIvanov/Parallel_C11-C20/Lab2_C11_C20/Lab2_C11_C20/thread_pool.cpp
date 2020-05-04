#include "thread_pool.h"

thread_pool::thread_pool()
{
	size_t nThreads = <количество потоков в пуле>;
	//Запускаем потоки:
	for (size_t i = 0; i < nThreads; i++) {
		threads.emplace_back(&thread_pool::task_thread, this);
		//может быть сгенерировано исключение => по-хорошему нужно обработать
	}
}

void thread_pool::task_thread() {
	while (!stop) {
		std::function<void()> task;
		m.lock();
		if (tasks.empty()) {
			m.unlock();
			std::this_thread::yield(); //отдыхаем
		}
		else {
			task = tasks.front();
			tasks.pop();
			m.unlock();
			task(); //или на всякий случай if (task) task();
		}
	}
}
М

void thread_pool::add_task(параметры)
{
	m.lock();
	tasks.push(<задание_с_полученными_параметрами>);
	m.unlock();
}

thread_pool:: ~thread_pool() 
{
	stop = true;
	for (std::thread& t : threads)
	{
		if (t.joinable()) t.join();
	}
}
М