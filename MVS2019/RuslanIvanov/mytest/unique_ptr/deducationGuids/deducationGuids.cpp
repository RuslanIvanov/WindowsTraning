﻿// deducationGuids.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <memory>
#include <list>
#include <set>
#include<algorithm>
#include <string>
#include <iterator>
#include <type_traits>
#include"Header.h"

int main()
{
    std::cout << "Hello World!\n";

    std::pair p(2, 4.5);     // выводится как std::pair<int, double> p(2, 4.5);
    std::tuple t(4, 3, 2.5); // эквивалентно auto t = std::make_tuple(4, 3, 2.5);
    std::less l;             // эквивалентно std::less<void> l;

   
   //  auto y = new A{ 1,2 }; // allocated type is A<int>

   // SSS<int>::N x{ 2.0, 1 };
    // неявно сгенерированными правилами вывода типов будут (заметьте, что T уже выведено как int):
    // F1: template<class U> S<int>::N<U> F(int);
    // F2: template<class U> S<int>::N<U> F(int, U);
    // F3: template<class U, class V> S<int>::N<U> F(V, U);
    // F4: template<class U> S<int>::N<U> F(S<int>::N<U>); (копирующий кандидат при выводе)
    // Разрешение перегрузки для прямой инициализации списком выражением "{2.0, 1}"
    // выберет F3 и U = int, V = double.
    // Возвращаемый тип - S<int>::N<int>
    // Результат:
    // S<int>::N<int> x{2.0, 1};

    {
     
        //MyArray<int, 5> ar1;//MyArray<int,5>
        //MyArray ar2{ "ABC" }; //MyArray<char,4>
       // int ar[] = { 1,2,3 };
     //   MyArray ar3{ ar };

        S<int,8> ar11;
        S ar22{ "ABC" };

        Ss ss{ "hello" }; // выводится как S<std::string>
    }
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.