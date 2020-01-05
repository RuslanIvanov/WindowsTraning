// exampleIndexOper.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>
using namespace std;

class MMassiveInt
{
private:
    class submasint;// �������� ����� ������� (����������)
    int row, col; // ���������� ����� � ������� �������
    submasint* arrint; // ��������� �� ������ ��������� ����� �������
    class submasint// �������� ����� ������� (����������)
    {
    public:
        int* sarrint;
        // ����������� �� ��������� ��������� ��� �������� ������� ���������� �� ����� �������� �������
        submasint() {}
        submasint(int size)
        {
            sarrint = new int[size]; // �������� ������� ������������� ������
            for (int i = 0; i < size; i++)//������������� ����� ������
            {
                sarrint[i] = 0;
            }
        }
        int& operator [] (int i) // �������� [] ���������� ������ �� int
        {
            return sarrint[i];
        }
        // ���������� �� �����, ���� ���� ��� ���������, �� ������ ������� ����� 
        // ��������� �� ����, ��� ���������� ��� �������
        //      ~submasint()   
        //{
        //  if (sarrint != nullptr) delete[] sarrint;
        //}
    };

public:
    MMassiveInt(const int rows, const int cols) //����� ������� ����� �����
    {
        rows < 1 ? row = 1 : row = rows; // ������ �� ����� ���������� ����� ��� �������� ����� 1
        cols < 1 ? col = 1 : col = cols;
        // �������� ������� ���������� � �������������� ������������ �� ��������� (��� ����������)
        arrint = new submasint[row];
        for (int i = 0; i < row; i++)
        {
            // �������� ����� �������. ���� � ��������� ����� ������� ����� ����������,
            // �� ������ ����� ��������� � ������ �������� �����
            arrint[i] = submasint(col);
        }
    }
    submasint& operator [] (int i)// �������� [] ���������� ������ �� �������� ����� �������
    {
        return arrint[i];
    }
    int GetCol() // ����� ��������� ���������� ������� �������
    {
        return col;
    }
    int GetRow()// ����� ��������� ���������� ����� �������
    {
        return row;
    }
    ~MMassiveInt()
    {
        for (int i = 0; i < row; i++)
        {// �������� ����� �������
            if (arrint[i].sarrint != nullptr)
                delete[](arrint[i].sarrint);
        }
        if (arrint != nullptr)
            delete[] arrint;// �������� ������� ���������� �� ������ �������
    }
};

int main()
{
    int mrow = 2, mcol = 3; // ������������� �������� ���������� ����� � �������� �������
    MMassiveInt mas(mrow, mcol); // �������� ���������� �������, � ������������� ��� ����� ������
    // ������ ������� � ������� 
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
