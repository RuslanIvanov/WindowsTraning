// stack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <stack>
#include <deque>
#include <iostream>

int main()
{
    std::stack<int> c1;
    c1.push(5);
    std::cout << c1.size() << '\n';

    std::stack<int> c2(c1);
    std::cout << c2.size() << '\n';

    std::deque<int> deq{ 3, 1, 4, 1, 5 };
    std::stack<int> c3(deq);
    std::cout << c3.size() << '\n';

    std::stack<int> c4;
  
    c4.push(4444);

    std::stack<int> c5 = std::move(c4);
    std::cout << c5.size() << '\n';
    std::cout << c4.size() << '\n';
    std::cout << c4.top() << '\n';
    int a = 0;
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
