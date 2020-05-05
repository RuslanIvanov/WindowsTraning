#include <functional>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include <condition_variable>

struct Foo 
{
    Foo(int num) : num_(num) {}
    void print_add(int i) const { std::cout << num_ + i << '\n'; }
    int num_;
};

void print_num(int i)
{
    std::cout << i << '\n';
}

void func(std::function<void(int)>& f)
{
   // f(5);
    f(99);
}

std::vector<int> data;
std::condition_variable cv;
std::mutex m;
void thread_writer() 
{
    std::lock_guard<std::mutex> lock(m);
    data.push_back(1);
    cv.notify_one();
}
void thread_reader() 
{
    std::unique_lock<std::mutex> lock(m);
    cv.wait(lock, []() { return !data.empty(); });
    std::cout << data.back() << std::endl;
}

int main()
{
    // store a free function
    std::function<void(int)> f_display = print_num;
    f_display(-9);
    func(f_display);
    // store a lambda
    std::function<void()> f_display_42 = []() { print_num(42); };
    f_display_42();

    // store the result of a call to std::bind
    std::function<void()> f_display_31337 = std::bind(print_num, 31337);
    f_display_31337();

    // store a call to a member function
    std::function<void(const Foo&, int)> f_add_display = &Foo::print_add;
    Foo foo(314159);
    f_add_display(foo, 1);
}