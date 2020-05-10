#include <condition_variable>
#include <mutex>
#include <thread>
#include <iostream>
#include <queue>
#include <chrono>
#include <future>
#include <atomic>

void fPtr(std::atomic<int*>& x) {x++; }



//class A1 { bool b; };
//class A2
//{
//	bool b;
//	int n;
//};
//class A3 { double d; };
//class A4 {
//	double d;
//	int n;
//};
//
//int main(int, char**)
//{
//
//	//bool b1 = std::atomic<A1>{}.is_lock_free(); //???
//	//bool b2 = std::atomic<A2>{}.is_lock_free(); //???
//	//bool b3 = std::atomic<A3>{}.is_lock_free(); //???
//	//bool b4 = std::atomic<A4>{}.is_lock_free(); //???
//
//	std::atomic<int> current(1);
//	int expected = 0;
//	bool b1 = atomic_compare_exchange_strong(&current,&expected, 3); //false, expected = 1, current не изм.
//	//или
//	//bool b1 = current.compare_exchange_strong( expected, 3);
//	expected = 1;
//	bool b2 = std::atomic_compare_exchange_strong(&current,&expected, 3);
//	//true, expected не изм., current =3
//	int a = 0;
//}
//////////////////////////////////////////////////////////////////////////////////////////

std::atomic<int>  ai;

int  tst_val = 4;
int  new_val = 5;
bool exchanged = false;

void valsout()
{
    std::cout << "ai= " << ai
        << "  tst_val= " << tst_val
        << "  new_val= " << new_val
        << "  exchanged= " << std::boolalpha << exchanged
        << "\n";
}

int main()
{
    ai = 3;
    valsout();

    // tst_val != ai   ==>  tst_val is modified
    exchanged = ai.compare_exchange_strong(tst_val, new_val);
    valsout();

    // tst_val == ai   ==>  ai is modified
    exchanged = ai.compare_exchange_strong(tst_val, new_val);
    valsout();

    int ar[] = { 1,2,3,4 };
    std::atomic<int*> data = ar;
    std::thread t1(fPtr, std::ref(data));
    std::thread t2(fPtr, std::ref(data));
    t1.join(); t2.join();

    int n = 1; //не атомарная переменная, но тип тривиальный!
    std::atomic<int> a1(n); //OK
    a1++; // n==??? a1 = ???
   // std::atomic_ref<int> a2(n);//c++20
   // a2++; // n==??? a2 = ???

  
    return 0;
}