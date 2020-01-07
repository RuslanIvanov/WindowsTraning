// enum_oper.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

enum class Mode //C++11
{
    UP,
    DOWN
};

// Префиксный инкремент.
Mode& operator++(Mode& m) {
    m = static_cast<Mode>(static_cast<int>(m) + 1);
    return m;
}

// Постфиксный инкремент.
Mode operator++(Mode& m, int) {
    Mode old = m;
    m = static_cast<Mode>(static_cast<int>(m) + 1);
    return old;
}

// Сложение.
Mode operator+(const Mode m, const int i) {
    return static_cast<Mode>(static_cast<int>(m) + i);
}
Mode operator+(const int i, const Mode m) {
    return operator+(m, i);
}

// Вычитание.
Mode operator-(const Mode m, const int i) {
    return static_cast<Mode>(static_cast<int>(m) - i);
}
Mode operator-(const int i, const Mode m) {
    return operator-(m, i);
}

// Сложение с присваиванием.
Mode& operator+=(Mode& m, int i) {
    m = operator+(m, i);
    return m;
}

// Вычитание с присваиванием.
Mode& operator-=(Mode& m, int i) {
    m = operator-(m, i);
    return m;
}
//////////////////////////////////////////////////////////////////////////
enum WEEK_DAY {MONDAY,TUESDAY,WEDNESDAY,THURSDAY,FRIDAY,SATURDAY,SUNDAY};
WEEK_DAY operator+=( WEEK_DAY& r, const int i )
{
    int k = (r + i);
    if (k > SUNDAY) 
    {
        r = static_cast<WEEK_DAY>(MONDAY + (k-1-SUNDAY)); 
    }
    else
    {
        r = static_cast<WEEK_DAY>(r + i);
    }

    return r;

}

int main()
{
    std::cout << "Hello enum!\n";

    WEEK_DAY w = FRIDAY;
    w += 5;

    WEEK_DAY ww = MONDAY;
    ww += 5;

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
