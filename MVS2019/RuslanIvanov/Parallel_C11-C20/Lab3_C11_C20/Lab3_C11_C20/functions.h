#pragma once
#include<string>
#include <random>
#include <chrono>
#include <ratio>
#include <thread>
#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <future>
#include "spinlock.h"

template <typename T>
void printCont(const T& t)
{
	for ( auto i = t.begin(); i != t.end(); ++i )
	{
		std::cout << *i << " ";
	}
}

void thread_func1(std::vector<int>& v, int N, std::mutex& m, std::promise<int>&);
void thread_func2(std::vector<int>& v, int M, std::mutex& m, std::promise<int>&);
void thread_transform(std::vector<int>& v, std::promise<int>&, std::promise<int>&);

void myThread(spinlock& m, std::string& s);
void myThreadLockGuard(spinlock& m, std::string& s);
void myThreadUniqGuard(spinlock& m, std::string& s);
