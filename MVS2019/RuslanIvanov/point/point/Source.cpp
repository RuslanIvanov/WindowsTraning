
#include <iostream>

class Point
{
private:
    double m_x, m_y, m_z;

public:
    Point(double x = 0.0, double y = 0.0, double z = 0.0) : m_x(x), m_y(y), m_z(z)
    {
    }

    friend std::ostream& operator<< (std::ostream& out, const Point& point);
    friend std::istream& operator>> (std::istream& in, Point& point);
};

std::ostream& operator<< (std::ostream& out, const Point& point)
{
    // ��������� operator<< �������� ������ ������ Point, �� �� ����� ������ ������ � ������ Point
    out << "Point(" << point.m_x << ", " << point.m_y << ", " << point.m_z << ")";

    return out;
}

std::istream& operator>> (std::istream& in, Point& point)
{
    // ��������� operator>> �������� ������ ������ Point, �� �� ����� ������ ������ � ������ Point
    // �������� ��������, �������� point (������ ������ Point) ������ ���� �� �����������, ����� �� ����� ����������� �������� ����� ������
    in >> point.m_x;
    in >> point.m_y;
    in >> point.m_z;

    return in;
}

int main()
{
    std::cout << "Enter a point: \n";

    Point point;
    std::cin >> point;

    std::cout << "You entered: " << point << '\n';

    return 0;
}