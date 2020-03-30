#pragma once

// a.h
template <class T> class B; // forward decl.

template <class T>
class A
{
    T t;
    const char* name = "class A";

public:
    void Test(const B<T>& b) { t = b.t; std::cout<<"name "<<b.name; }
};
