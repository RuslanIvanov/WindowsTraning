#pragma once

// a.h
template <class T> class B; // forward decl.

template <class T>
class A
{
    T t;
    int n = 0;
    friend class B<T>;
public:
    void Test(const B<T>& b) { t = b.t; }
};
