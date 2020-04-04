#include <memory>
#include <iterator>
#include <vector>
#include <iostream>
#include <algorithm>

struct trans2
{ 
    double operator()
        (const std::unique_ptr<int>& m) const 
        { return (*m) * 2; }; 
};

inline void delTest()
{
    std::cout << " del test ";
}

int main(int,char**)
{
    auto transFunc = [](const std::unique_ptr<int>& m) -> std::unique_ptr<int>
    { 
        std::unique_ptr<int> p(new int ((*m)*2));
   
       // m.release();//возвращает указатель на управляемый объект и освобождает собственность
        return std::move(p);
    };

    std::vector<std::unique_ptr<int>> v;
    v.push_back(std::make_unique<int>(0));
    v.push_back(std::make_unique<int>(1));
    v.push_back(std::make_unique<int>(2));
    v.push_back(std::make_unique<int>(3));
    v.push_back(std::make_unique<int>(4));

    std::transform(v.begin(), v.end(), v.begin(), transFunc);

    for (size_t i = 0; i < v.size(); i++)
    {
        std::cout << "v: " << *v[i];
    }

    int a[3] = { 0 };
    {
        std::unique_ptr<int[]> p2 = std::make_unique<int[]>(3);// (a, delTest);
    }
    
    {
       // std::unique_ptr<int[], std::default_delete< int[]>> p1(&a[0]);
        std::unique_ptr<int[], decltype(&delTest)> p1(a, delTest);
        p1[1] = 3;
        unsigned int size = 16000;
        std::unique_ptr<unsigned char[], std::default_delete<unsigned char[]>> pData(new unsigned char[size]);
    }

    return 0;
}

/*
Alternatively:
Create a copyable calleable instead:

struct { double operator()(const std::unique_ptr<int>& m) const { return (*m) * 2; }; } transFunc;
*/