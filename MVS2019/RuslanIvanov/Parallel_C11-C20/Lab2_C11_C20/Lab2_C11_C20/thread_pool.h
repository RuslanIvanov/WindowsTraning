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
	mutable std::mutex m; //��� ���������� ������������� ������ � ��������
	std::condition_variable cv;
	//std::unique_lock
	std::queue<std::function<void()>> tasks; //������� �������
	std::vector<std::thread> threads; //������������ ������� �������
	bool m_stop; //��-�������� ��� ������ ���� atomic-����������
	void task_thread(); //��������� ������� (� ����� ������ � �����������)
	void task_thread_cv();
public:
	thread_pool();
	~thread_pool();
	void add_task(std::function<void()>&); //� ����� ������ ��������� ��������� ��� �������
	void add_task_cv(std::function<void()>&);
	bool isEmpty();
	void stopRun();
	void stopRun_cv();
	thread_pool(const thread_pool&) = delete; 
	thread_pool& operator=(const thread_pool&) = delete;
};

