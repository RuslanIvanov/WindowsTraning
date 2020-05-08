#include <functional>
#include <thread>
#include <iostream>


struct A {
    void foo1(int b, double c) {
        std::thread t(&A::bar, this, c, b);
        t.detach();
    }

    void foo2(int b, double c) {
        std::thread t([this, b, c]() {
            bar(c, b);
            });
        t.detach();
    }

    void foo3(int b, double c) {
        std::thread t(std::bind(&A::bar, this, c, b));
        t.detach();
    }

    void bar(double f, int g) {}
};



class C
{
public:
    void method(int a, float b)
    {
        std::cout << a << ' ' << b << std::endl;
    }
};

int main(int,char**)
{
    C c;
    std::thread t1(&C::method, c, 10, 3.14f);
    t1.join();
    return 0;
}