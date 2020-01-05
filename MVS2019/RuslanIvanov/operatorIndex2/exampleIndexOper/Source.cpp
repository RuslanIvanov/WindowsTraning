#include <iostream>
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

    system("pause");
    return 0;
}
////////////////////////////////////////////////////////////////////////
class TMatrix
{
private:
    int line, col;
    double** m;
public:
    TMatrix(const int l, const int c) 
    {         
         m = new double*[line]; 
         for (int i = 0; i < line; i++)
             m[i] = new double[c];
    }
    ~TMatrix()
    {
        for (int i = 0; i < line; i++)
            delete [] m[i];
        delete [] m; 
    }
   //...................................................
        double* operator [](const int i)const { return m[i]; }
};