// exampleIndexOper2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

////////////////////////////////////////////////////////////////////////
class TMatrix
{
private:
    int line, col;
    double** m;
public:
    TMatrix(const int l, const int c)
    {
        m = new double* [line];
        for (int i = 0; i < line; i++)
            m[i] = new double[c];
    }
    ~TMatrix()
    {
        for (int i = 0; i < line; i++)
            delete[] m[i];
        delete[] m;
    }
    //...................................................
    double* operator [](const int i)const { return m[i]; }
};
////////////////////////////////////////////////////////////
class matrix
{
public:
    int m, n;
    int** pMatrix;

    int* operator[](int elem)
    {
        return pMatrix[elem];
    }
    void coutput()
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                printf("%-5d", pMatrix[i][j]);
            std::cout << "\n";
        }
    }
} a;

int main()
{
    a.m = 10;
    a.n = 10;
    a.pMatrix = new int* [a.m];
    for (int i = 0; i < a.m; i++)
        a.pMatrix[i] = new int[a.n];

    for (int i = 0; i < a.m; i++)
        for (int j = 0; j < a.n; j++)
            a.pMatrix[i][j] = (i + 1) * (j + 1);
    a.coutput();

    getchar();
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
