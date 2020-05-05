#pragma once
#include <iostream>
#include <sstream>
#include <mutex>
#include <thread>
#include <queue>
#include <functional>

class thread_pool 
{
	mutable std::mutex m; //��� ���������� ������������� ������ � ��������
	std::queue<std::function<void()>> tasks; //������� �������
	std::vector<std::thread> threads; //������������ ������� �������
	bool m_stop; //��-�������� ��� ������ ���� atomic-����������
	void task_thread(); //��������� ������� (� ����� ������ � �����������)
public:
	thread_pool();
	~thread_pool();
	void add_task(std::function<void()>&); //� ����� ������ ��������� ��������� ��� �������
	bool isEmpty();
	thread_pool(const thread_pool&) = delete; 
	thread_pool& operator=(const thread_pool&) = delete;
};

