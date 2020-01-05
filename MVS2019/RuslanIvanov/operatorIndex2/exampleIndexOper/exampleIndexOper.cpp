// exampleIndexOper.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
using namespace std;

class MMassiveInt
{
private:
    class submasint;// подкласс строк матрицы (объявление)
    int row, col; // количества строк и колонок матрицы
    submasint* arrint; // указатель на массив подкласса строк матрицы
    class submasint// подкласс строк матрицы (реализация)
    {
    public:
        int* sarrint;
        // конструктор по умолчанию необходим для создания массива указателей на класс подстрок матрицы
        submasint() {}
        submasint(int size)
        {
            sarrint = new int[size]; // создание массива целочисленных данных
            for (int i = 0; i < size; i++)//инициализация полей нулями
            {
                sarrint[i] = 0;
            }
        }
        int& operator [] (int i) // оператор [] возвращает ссылку на int
        {
            return sarrint[i];
        }
        // деструктор не нужен, если если его поставить, то строки матрицы будут 
        // удаляться до того, как заполнится вся матрица
        //      ~submasint()   
        //{
        //  if (sarrint != nullptr) delete[] sarrint;
        //}
    };

public:
    MMassiveInt(const int rows, const int cols) //класс матрица целых чисел
    {
        rows < 1 ? row = 1 : row = rows; // защита от ввода количества строк или столбцов менее 1
        cols < 1 ? col = 1 : col = cols;
        // создание массива указателей с использованием конструктора по умолчанию (без параметров)
        arrint = new submasint[row];
        for (int i = 0; i < row; i++)
        {
            // создания строк матрицы. если у подкласса строк матрицы будет деструктор,
            // то строки будут удаляться в каждей итерации цикла
            arrint[i] = submasint(col);
        }
    }
    submasint& operator [] (int i)// оператор [] возвращает ссылку на подкласс строк матрицы
    {
        return arrint[i];
    }
    int GetCol() // метод получения количества колонок матрицы
    {
        return col;
    }
    int GetRow()// метод получения количества строк матрицы
    {
        return row;
    }
    ~MMassiveInt()
    {
        for (int i = 0; i < row; i++)
        {// удаление строк матрицы
            if (arrint[i].sarrint != nullptr)
                delete[](arrint[i].sarrint);
        }
        if (arrint != nullptr)
            delete[] arrint;// удаление массива указателей на строки матрицы
    }
};

int main()
{
    int mrow = 2, mcol = 3; // инициализация значения количество строк и столбцов матрицы
    MMassiveInt mas(mrow, mcol); // создание двумерного массива, и инициализация его полей нулями
    // вывода матрицы в консоль 
    for (int i = 0; i < mas.GetRow(); i++)
    {
        for (int k = 0; k < mas.GetCol(); k++)
        {
            cout << mas[i][k] << "\t";
        }
        cout << endl;
    }
    system("Pause");
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
