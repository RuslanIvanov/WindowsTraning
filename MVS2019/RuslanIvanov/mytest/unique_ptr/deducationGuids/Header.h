#pragma once

//template<class T> struct A { A(T, T); };
// template<class T> struct SSS 
// {
//     template<class U> struct N 
//     {
//            N(T);
//            N(T, U);
//            template<class V> N(V, U);
//      };
// };

 template<typename T, typename U>
 struct S { T m_t; U m_u; S(const T& t, U u) {};  S(const T& t, int) {} S() = default; };

 //My deduction guid
 template<typename T, typename U>
 S(const T& t, const U& u)->S<T, U>;

 template<typename T, typename U>
 S(const T& t, U u)->S<T, int>;

 template<typename T, typename U>
 S(const T& t, U u)->S<int, int>;

 //template<typename T,typename U>
 //S(const T& t, U u)->S<T, size_t>;

 //template<typename T, typename U>
 //S(const T& t, U u)->S<char , size_t>;

 //template<typename T, typename U>
 //S(const T& t, U u)->S<int, size_t>;

template<typename T, typename U>
 S(const T&,U)->S<std::initializer_list<T>,size_t>;
 
 template<typename T, size_t size>
 S(T*,size_t)->S<char, size_t>;

 template<typename T, size_t size>
 class MyArray
 {
     T ar[size] = { T() }; //как обеспечить инициализацию элементов базового типа по умолчанию нулем?
 public:
     MyArray() = default;
     MyArray(T, size_t n) {}
     MyArray(T*) {}
     MyArray(std::initializer_list<T>) {}
 };


 template<class T> struct Ss { Ss(T); };
 Ss(char const*)->Ss<std::string>;
                