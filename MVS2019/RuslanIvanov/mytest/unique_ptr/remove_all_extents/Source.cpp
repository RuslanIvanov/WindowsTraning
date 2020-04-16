#include <type_traits>
#include <iostream>

int main()
{
    //remove_all_extents: ������� �� ���� ������� ���, �� ����������� � �������.
    //��������� remove_all_extents<T> �������� ���������������� ���, ������� �������� ����� �������� ���� T 
    //� ���������� ����������� �������, ��� t, ���� t �� �������� ����� �������.
    std::cout << "remove_all_extents<int> == "
        << typeid(std::remove_all_extents_t<int>).name()
        << std::endl;
    std::cout << "remove_all_extents_t<int[5]> == "
        << typeid(std::remove_all_extents_t<int[5]>).name()
        << std::endl;
    std::cout << "remove_all_extents_t<int[5][10]> == "
        << typeid(std::remove_all_extents_t<int[5][10]>).name()
        << std::endl;


    //remove_extent_t: ������� ��� �������� �� ���� �������.
    //��������� remove_extent<T> �������� ���������������� ���, ������� ����� T1 
    //��������, ���� t ����� ����� T1[N], � ��������� ������ t.
    std::cout << "remove_extent_t<int> == "
            << typeid(std::remove_extent_t<int>).name()
            << std::endl;
            std::cout << "remove_extent_t<int[5]> == "
            << typeid(std::remove_extent_t<int[5]>).name()
            << std::endl;
            std::cout << "remove_extent_t<int[5][10]> == "
            << typeid(std::remove_extent_t<int[5][10]>).name()
            << std::endl;
    

    return (0);
}