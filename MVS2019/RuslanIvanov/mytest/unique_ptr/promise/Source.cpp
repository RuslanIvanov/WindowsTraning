#include <condition_variable>
#include <mutex>
#include <thread>
#include <iostream>
#include <queue>
#include <chrono>
#include <future>

std::promise<int> promise;
std::future<int> fur;
void thread_func1() 
{ 
	promise.set_value(33); 

}

void thread_func3()
{
	promise.set_value(33+1);
}

void thread_func2()
{ 
	int ii = 0;
	while (ii!=34) 
	{
		std::cout << "_(";
		ii = promise.get_future().share;//.get_future().get();
		std::cout << ii;
		std::cout << "}";
	}
}
int main()
{
	std::thread th1(thread_func1);
	std::thread th2(thread_func2);

	auto a = fur.get(); 
	//std::thread th3(thread_func3); th3.join();

	th1.join(); th2.join(); 
}