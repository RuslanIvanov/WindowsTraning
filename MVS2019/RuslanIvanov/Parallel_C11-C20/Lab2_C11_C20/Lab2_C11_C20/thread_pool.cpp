#include "thread_pool.h"

thread_pool::thread_pool()
{
	size_t nThreads = <���������� ������� � ����>;
	//��������� ������:
	for (size_t i = 0; i < nThreads; i++) {
		threads.emplace_back(&thread_pool::task_thread, this);
		//����� ���� ������������� ���������� => ��-�������� ����� ����������
	}
}

void thread_pool::task_thread() {
	while (!stop) {
		std::function<void()> task;
		m.lock();
		if (tasks.empty()) {
			m.unlock();
			std::this_thread::yield(); //��������
		}
		else {
			task = tasks.front();
			tasks.pop();
			m.unlock();
			task(); //��� �� ������ ������ if (task) task();
		}
	}
}
�

void thread_pool::add_task(���������)
{
	m.lock();
	tasks.push(<�������_�_�����������_�����������>);
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
�