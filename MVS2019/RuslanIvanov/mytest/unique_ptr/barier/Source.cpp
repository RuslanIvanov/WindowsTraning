#include <condition_variable>
#include <mutex>
#include <thread>
#include <iostream>
#include <queue>
#include <chrono>
#include <future>
#include <atomic>

//viljams
std::atomic<bool> x(false), y(false);
std::atomic<int> z = { 0 };
void write_x() { x.store(true, std::memory_order_seq_cst); }
void write_y() { y.store(true, std::memory_order_seq_cst); }
void read_x_then_y() {
	while (!x.load(std::memory_order_seq_cst)) { std::cout << 'x'; }
	if (y.load(std::memory_order_seq_cst)) { ++z; }
}
void read_y_then_x() {
	while (!y.load(std::memory_order_seq_cst)) { std::cout << 'y'; }
	if (x.load(std::memory_order_seq_cst)) { ++z; }
}

int main()
{
	//viljams
	std::thread a(write_x);
	std::thread b(write_y);
	std::thread c(read_x_then_y);
	std::thread d(read_y_then_x);
	a.join(); b.join(); c.join(); d.join();
	std::cout << "\n z = " << z;

	return 0;
}
