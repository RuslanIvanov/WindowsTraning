#include <algorithm>
#include <iterator>
#include <ios>
#include <iostream>
#include <set>
#include <string>
bool predicate(int lhs, int rhs)
{
    return rhs < lhs;
}

int main()
{
    auto const ss = std::set<std::string>{ "foo", "bar", "test" };
    auto const si = std::set<int,std::less<int>>{ 4, 0, -1 };
    std::set<int, decltype(&predicate)> sii(predicate);// { 4, 0, -1 };
    sii.insert(-1);
    sii.insert(2);
    sii.insert(3);
   // sort(si.begin(), si.end()); -  нельзя
    std::cout << std::boolalpha << std::is_sorted(begin(ss), end(ss)) << "\n";
    std::cout << std::boolalpha << (std::adjacent_find(begin(ss), end(ss)) == end(ss)) << "\n";
    std::copy(begin(ss), end(ss), std::ostream_iterator<std::string>(std::cout, "\n"));
}