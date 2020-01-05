// operatorIndex2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "A.h""
#include "B.h"
#define	  stop __asm nop
int main()
{
    std::cout << "Hello World!\n";

    A a(11);
    for (int i = 0; i < 9; i++)
    {
        //a[i] = (i * i);
        a.operator[](i) = (i*i);
        std::cout << "\na[" << i << "] = " << a[i];
    }
    stop

    B b(1,11,11);

    std::cout << "\nb [0][0] = " << b[0][0];

    for (int i = 0; i < 11; i++)
        for (int j = 0; j < 11; j++)
        {     std::cout << "\nb ["<<i<<"]["<<j<<"] = "<< b[i][j];
              std::cout << "\nfunc form: b [" << i << "][" << j << "] = " << b.operator[](i)[j];
        }
    stop
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
