#include "thread_pool.h"

thread_pool::thread_pool()
{// constructor
	size_t nThreads = std::thread::hardware_concurrency();//4;//<���������� ������� � ����>;
	m_stop = false;
	//��������� ������:
	for (size_t i = 0; i < nThreads; i++)
	{
		try
		{
			threads.emplace_back(&thread_pool::task_thread, this);
			//����� ���� ������������� ���������� => ��-�������� ����� ����������
		}
		catch (std::system_error) { std::cout << "\nError start thread number "<<i+1; }
	}
}

void thread_pool::task_thread() 
{
	while (!m_stop) // ����������
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

			if(task)
			task(); //��� �� ������ ������ if (task) task();
		}
	}
}

bool thread_pool::isEmpty() 
{
	bool b = false;
	
	if (m.try_lock())
	{
		b = tasks.empty();
		m.unlock();
	}
	return b;

}

void thread_pool::add_task(std::function<void()>& pfunc/*���������*/)
{
	m.lock();
	tasks.push(pfunc);
	m.unlock();
}

thread_pool:: ~thread_pool() 
{
	m_stop = true;
	for (std::thread& t : threads)
	{
		if (t.joinable())
		{
			std::cout << "\ndelete th id = " << t.get_id();
			t.join();
			
		}
	}
}