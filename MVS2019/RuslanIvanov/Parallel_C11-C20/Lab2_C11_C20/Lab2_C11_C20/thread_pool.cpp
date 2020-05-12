#include "thread_pool.h"

thread_pool::thread_pool()
{// constructor
	size_t nThreads = std::thread::hardware_concurrency();//4;//<���������� ������� � ����>;
	std::cout << "\nkernels  = " << nThreads<<"\n";
	m_stop = false;
	//��������� ������:
	for (size_t i = 0; i < nThreads; i++)
	{
		try
		{
			threads.emplace_back(&thread_pool::task_thread_cv, this);
			//����� ���� ������������� ���������� => ��-�������� ����� ����������
		}
		catch (std::system_error) { std::cout << "\nError start thread number "<<i+1; }
	}
}

void thread_pool::task_thread_cv()
{
	thread_local size_t countTask = 0;

	while (!m_stop) // atomic
	{
		std::function<void()> task;
		
		std::cout << "\nwait...id  = "<<std::this_thread::get_id();

		/*����� �����, ������� ������� ����� �� std::condition_variable ������ ������� ���������� std::unique_lock. 
		�������� �������� �������� ����������� ������� � ���������������� ���������� ������. 
		����� ���������� ������� ������������, ����� ������������, � ������� ����� �������������.*/
		std::unique_lock <std::mutex > l(m);//m.lock()
		//cv.wait(lock,pred = false, ���� �������� ������ ���� ����������)
		cv.wait(l, [this]() { return !tasks.empty() || m_stop; });//gd��� ���� �� ������� ���� �� � ������� ��� �� ������ ����
		if (m_stop) break;

		task = tasks.front();
		tasks.pop();
		//m.unock();
		if (task)
		{
			task();//������ �� ������� => ������
			countTask++;//atom ??
		}
		
	}

	std::cout << "\nid thread =  " << std::this_thread::get_id() << ", number of completed tasks = " << countTask; 
}

void thread_pool::task_thread() 
{
	thread_local size_t countTask= 0;

	while (!m_stop) // atomic
	{
		std::function<void()> task;
		m.lock();
		if (tasks.empty())
		{
			m.unlock();
			std::this_thread::yield();
			std::cout << "\nwait with yield...";
		}
		else
		{
			task = tasks.front();
			tasks.pop();
			m.unlock();

			if (task)
			{
				task(); 
				countTask++;
			}
		}
	}

	std::cout << "\nid thread =  " << std::this_thread::get_id() << ", number of completed tasks = " << countTask;
}

void  thread_pool::stopRun()
{
	m_stop = true;//atomic
}

void  thread_pool::stopRun_cv()
{
	{
		std::lock_guard<std::mutex> lk{ m };//?? ����� ������ �� �� cv
		m_stop = true;//atomic

	}
	cv.notify_all();// ���� ��������� 1 �� � ������� � �� ����
	
}

bool thread_pool::isEmpty() //const ??
{/// �����
	bool b = false;
	
	if (m.try_lock())
	{
		b = tasks.empty();
		m.unlock();
	}
	return b;

}

void thread_pool::add_task_cv(std::function<void()>& pfunc)
{
	{
		std::lock_guard<std::mutex> lk{ m };
		tasks.push(pfunc);
		
	}
	cv.notify_all();
	std::cout << "\npush...";
}

void thread_pool::add_task(std::function<void()>& pfunc/*���������*/)
{
	m.lock();
	tasks.push(pfunc);
	m.unlock();
	std::cout << "\npush...";
}

thread_pool:: ~thread_pool() 
{
	m_stop = true;
	cv.notify_all();
	for (std::thread& t : threads)
	{
		if (t.joinable())
		{
			std::cout << "\ndelete th id = " << t.get_id()<<"\n";
			t.join();
			
		}
	}
}