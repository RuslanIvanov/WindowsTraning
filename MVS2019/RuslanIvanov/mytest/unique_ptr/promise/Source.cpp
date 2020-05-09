#include <condition_variable>
#include <mutex>
#include <thread>
#include <iostream>
#include <queue>
#include <chrono>
#include <future>

std::promise<int> promise;
void thread_func1() 
{ 
	promise.set_value(33); 
}
void thread_func2()
{ 
	std::cout << "_(";
	std::cout << promise.get_future().get(); 
	std::cout << "}";
}
int main()
{
	std::thread th1(thread_func1);
	std::thread th2(thread_func2);

	th1.join(); th2.join();
}