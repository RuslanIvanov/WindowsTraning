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
	mutable std::mutex m; //��� ���������� ������������� ������ � ��������
	mutable std::mutex m_sinx_out; //��� ������
	std::condition_variable cv;

	std::queue<std::function<void()>> tasks; //������� �������
	std::vector<std::thread> threads; //������������ ������� �������
	std::atomic<bool> m_stop; //��-�������� ��� ������ ���� atomic-����������
	static std::atomic<size_t> countTask;
	void task_thread_cv();
public:
	thread_pool();
	~thread_pool();
	void add_task(std::function<void()>&); //� ����� ������ ��������� ��������� ��� �������
	void add_task_cv(std::function<void()>&);
	void stopRun_cv();
	thread_pool(const thread_pool&) = delete; 
	thread_pool& operator=(const thread_pool&) = delete;
};

