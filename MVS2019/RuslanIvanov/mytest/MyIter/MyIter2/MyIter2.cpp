// MyIter2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iterator>
#include <iostream>
#include <algorithm>
#include <cstddef>

template<class T>
class Iterator;

template<class T>
class array
{
public:
    typedef Iterator<T> iterator;
    typedef size_t size_type;
    typedef T* pointer;
    typedef const T* const_pointer;
    typedef T& reference;
    typedef const T& const_reference;
    typedef T value_type;

    array() : arr_(new T[0]), sz_(0)
    {
    }
    array(size_t sz) : sz_(sz), arr_(new T[sz])
    {
        std::fill(arr_, arr_ + sz_, T());
    }
    array(const array& arr)
    {
        delete arr_;
        sz_ = arr.sz;
        arr_ = new T[sz_];
        std::copy(arr.arr_, arr.arr_ + sz_, arr_);
    }
    array& operator =(const array& arr)
    {
        array tmp(arr);
        swap(tmp);
        return *this;
    }
    ~array()
    {
        delete[] arr_;
    }
    Iterator<T> begin()
    {
        return Iterator<T>(arr_);
    }
    Iterator<T> end()
    {
        return Iterator<T>(arr_ + sz_);
    }
    T& operator [](size_t idx)
    {
        return arr_[idx];
    }
    const T& operator [](size_t idx) const
    {
        return arr_[idx];
    }
    size_t size() const
    {
        return sz_;
    }
private:
    void swap(array& first, array& second)
    {
        std::swap(first.arr_, second.arr_);
        std::swap(first.sz_, second.sz_);
    }
    T* arr_;
    size_t sz_;
};

template<class T>
class Iterator
{
public:
    typedef T value_type;
    typedef T* pointer;
    typedef T& reference;
    typedef std::forward_iterator_tag iterator_category;
    typedef ptrdiff_t difference_type;

    Iterator(T* curr) :current(curr)
    {
        std::cout << "\nIterator(T* curr)";
    }
    Iterator& operator =(const Iterator& other)
    {
        if (this != &other)
        {
            current = other.current;
        }
        return *this;
    }
    Iterator& operator++()
    {
        ++current;
        return *this;
    }
    Iterator operator ++(int i)
    {
        Iterator tmp(current);
        ++current;
        return tmp;
    }
    T& operator*()
    {
        return *current;
    }
    T* operator->()
    {
        return current;
    }
    bool operator ==(const Iterator& other)
    {
        return current == other.current;
    }
    bool operator !=(const Iterator& other)
    {
        return !(*this == other);
    }
private:
    T* current;
};

int main()
{
    array<int> arr(5);
    for (array<int>::iterator iter = arr.begin(); iter != arr.end(); ++iter)
    {
        std::cout << *iter << std::endl;
    }
    int i = 0;
    for (array<int>::iterator iter = arr.begin(); iter != arr.end(); ++iter)
    {
        i++;
        *iter = i;//5;
    }
    for (array<int>::iterator iter = arr.begin(); iter != arr.end(); ++iter)
    {
        std::cout << *iter << std::endl;
    }
    std::copy(arr.begin(), arr.end(), std::ostream_iterator<int>(std::cout, "\n"));

    for (auto& el : arr) { std::cout << el << '_'; }

    array<int>::iterator iter2= arr.begin();
    std::cout<< *iter2.operator->();
    std::cout << *iter2;
    return 0;
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
