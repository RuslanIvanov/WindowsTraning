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
/*ќпределЄнное пользователем правило вывода типов имеет синтаксис объ€влени€ функции с завершающим возвращаемым типом (trailing return type), 
за исключением того, что в качестве имени функции используетс€ им€ шаблона класса:

explicit(необ€зательно) им€-шаблона ( объ€вление-параметра ) -> простой-идентификатор-шаблона ;		
*/
//////////////////////////////////////////////////////
 template<typename T,size_t size>
 struct S { T t; size_t s; };

 //My deduction guid
 template<typename T, size_t size>
 S(const T(&)[size], size_t)->S<T,size>;

 template<typename T, size_t size >
 S(const std::initializer_list<T>& t)->S<T, size>;
 ///////////////////////////////////////////////////////
 //***************************************************************/
//«адание 7.

    /*ѕользовательский deduction guide Ц дл€ вывода типов параметров шаблона
    «адан шаблон класса, который инкапсулирует внедренный ограниченный массив известной
    размерности с элементами любого типа. */
    /*
template<typename T, size_t size> class MyArray
    {
        T ar[size]; //как обеспечить инициализацию элементов базового типа по умолчанию нулем?
        Е
    };

//*/
 template<typename T, size_t size>
 class MyArray
 {
     T ar[size] = { T() }; //как обеспечить инициализацию элементов базового типа по умолчанию нулем?
 public:
     MyArray() = default;
     MyArray(const T(&)[size]) {}
    // MyArray(T*) {}
     MyArray(std::initializer_list<T>&) {}
 };

 //My deduction guid
 template<typename T,size_t size>
 MyArray(const T(&)[size], size_t)->MyArray<T, size>;

 //template<typename T, size_t size>
 //MyArray(const T& t, size_t)->MyArray<int, size>;

template<typename T, size_t size>
 MyArray(const std::initializer_list<T>& t, size_t)->MyArray<T, size>;

 //template<typename T, size_t size>
 //MyArray(const T& t, size_t)->MyArray<char, size>;

// template<class T> struct Ss { Ss(T); };
// Ss(char const*)->Ss<std::string>;
// Ss(const int&)->Ss<char>;

 //template<class T> struct A {
 //    A(T, int*);     // #1
 //    A(A<T>&, int*); // #2
 //    enum { value };
 //};
 //template<class T, int N = T::value> A(T&&, int*)->A<T>;
                