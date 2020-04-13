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

//////////////////////////////////////////////////////
 template<typename T,size_t>
 struct S { T t; size_t s; };

 //My deduction guid
 template<typename T, size_t>
 S(const T& t, size_t n)->S<T*,size_t>;

 template<typename T >
 S(const T& t)->S<std::initializer_list<T>>;
 ///////////////////////////////////////////////////////

 template<typename T, size_t size>
 class MyArray
 {
     T ar[size] = { T() }; //как обеспечить инициализацию элементов базового типа по умолчанию нулем?
 public:
     MyArray() = default;
    // MyArray(T, size_t n) {}
   //  MyArray(T, int) {}
   //  MyArray(T*) {}
  //   MyArray(std::initializer_list<T>) {}
 };

 //My deduction guid
 template<typename T,size_t n>
 MyArray(const T& t, size_t)->MyArray<T*, n>;

 template<typename T, size_t n>
 MyArray(const T& t, size_t)->MyArray<std::initializer_list<T>, n>;


 template<class T> struct Ss { Ss(T); };
 Ss(char const*)->Ss<std::string>;
 Ss(const int&)->Ss<char>;
                