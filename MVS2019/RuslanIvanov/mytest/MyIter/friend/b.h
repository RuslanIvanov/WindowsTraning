#pragma once
// b.h
template <class T> class A; // forward decl.

template <class T>
class B
{
    friend class A<T>;
 	const char* nameB = "class B";
    T t;
    public:
  
       void f() { std::cout << nameB; }
};
