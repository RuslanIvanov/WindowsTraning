#include <type_traits>
#include <iostream>

int main()
{
    //remove_all_extents: —оздает из типа массива тип, не относ€щийс€ к массиву.
    //Ёкземпл€р remove_all_extents<T> содержит модифицированный тип, который €вл€етс€ типом элемента типа T 
    //с удаленными измерени€ми массива, или t, если t не €вл€етс€ типом массива.
    std::cout << "remove_all_extents<int> == "
        << typeid(std::remove_all_extents_t<int>).name()
        << std::endl;
    std::cout << "remove_all_extents_t<int[5]> == "
        << typeid(std::remove_all_extents_t<int[5]>).name()
        << std::endl;
    std::cout << "remove_all_extents_t<int[5][10]> == "
        << typeid(std::remove_all_extents_t<int[5][10]>).name()
        << std::endl;


    //remove_extent_t: —оздает тип элемента из типа массива.
    //Ёкземпл€р remove_extent<T> содержит модифицированный тип, который имеет T1 
    //значение, если t имеет форму T1[N], в противном случае t.
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