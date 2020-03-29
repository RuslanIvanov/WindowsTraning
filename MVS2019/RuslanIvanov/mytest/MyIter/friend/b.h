#pragma once
// b.h
template <class T> class A; // forward decl.

template <class T>
class B
{
    friend class A<T>;
    T t;
    public:
 
};
