/*

make_move_iterator-это шаблон функции удобства, который создает std:: move_iterator для данного итератора i с типом, 
выведенным из типа аргумента.
Шаблон класса move_iterator является программой-оболочкой для итератора. 
Move_iterator предоставляет то же поведение, 
что и инкапсулируемый в него (хранящийся в нем) итератор, за исключением того, 
что оператор разыменования хранящегося
итератора превращается в ссылку rvalue, что превращает копирование в перемещение.

*/

#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <iterator>

int main()
{
    std::list<std::string> s{ "one", "two", "three" };

    std::vector<std::string> v1(s.begin(), s.end()); // copy

    std::vector<std::string> v2(std::make_move_iterator(s.begin()),
        std::make_move_iterator(s.end())); // move

    std::cout << "v1 now holds: ";
    for (auto str : v1)
        std::cout << "\"" << str << "\" ";
    std::cout << "\nv2 now holds: ";
    for (auto str : v2)
        std::cout << "\"" << str << "\" ";
    std::cout << "\noriginal list now holds: ";
    for (auto str : s)
        std::cout << "\"" << str << "\" ";
    std::cout << '\n';
}