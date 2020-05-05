#include "thread_pool.h"

thread_pool::thread_pool()
{// constructor
	size_t nThreads = 4;//<���������� ������� � ����>;
	//��������� ������:
	for (size_t i = 0; i < nThreads; i++)
	{
		try
		{
			threads.emplace_back(&thread_pool::task_thread, this);
			//����� ���� ������������� ���������� => ��-�������� ����� ����������
		}
		catch (...) { std::cout << "\nError start thread number "<<i+1; }
	}
}

void thread_pool::task_thread() 
{
	while (!stop) // ����������
	{
		std::function<void()> task;
		m.lock();
		if (tasks.empty())
		{
			m.unlock();
			std::this_thread::yield(); //��������
		}
		else
		{
			task = tasks.front();
			tasks.pop();
			m.unlock();
			task(); //��� �� ������ ������ if (task) task();
		}
	}
}

void thread_pool::add_task(std::function<void()> pfunc/*���������*/)
{
	m.lock();
	tasks.push(pfunc);
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