#include <stddef.h>
#include <type_traits>
template <typename T, size_t N> struct MyArray {
    T m_array[N];
};
template <typename First, typename... Rest> struct EnforceSame {
    static_assert(std::conjunction_v<std::is_same<First, Rest>...>);
    using type = First;
};
template <typename First, typename... Rest> MyArray(First, Rest...)
->MyArray<typename EnforceSame<First, Rest...>::type, 1 + sizeof...(Rest)>;
int main() {
    MyArray a = { 11, 22, 33 };
    static_assert(std::is_same_v<decltype(a), MyArray<int, 3>>);

    MyArray<int, 5> ar1;//MyArray<int,5>
    MyArray ar2{ "ABC" }; //MyArray<char,4>
    int ar[] = { 1,2,3 };
    MyArray ar3{ ar,ar,ar };
    int y = 0;
}