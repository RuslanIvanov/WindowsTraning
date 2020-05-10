#include <condition_variable>
#include <mutex>
#include <thread>
#include <iostream>
#include <queue>
#include <chrono>
#include <future>
#include <atomic>

std::atomic<bool> x(false), y(false);
std::atomic<int> z = { 0 };

void write_x_then_y()
{
	x.store(true, std::memory_order_relaxed);
	y.store(true, std::memory_order_relaxed);
}

void read_y_then_x()
{
	while (!y.load(std::memory_order_relaxed)) { std::cout << 'y'; }
	if (x.load(std::memory_order_relaxed)) { ++z; }
}

int main()
{
	std::thread a(write_x_then_y);
	std::thread b(read_y_then_x);
	a.join(); b.join();

	std::cout << "\nz = " << z;

	return 0;
}
