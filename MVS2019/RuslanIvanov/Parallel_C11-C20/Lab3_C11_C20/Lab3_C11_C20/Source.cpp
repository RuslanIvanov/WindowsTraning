#include "Header.h"
#include "functions.h"
#include "spinlock.h"
using namespace std;
using namespace chrono_literals;

int _tmain(int argc, _TCHAR* argv[])
{

#if  _WIN32 
	setlocale(LC_CTYPE, ".UTF8");
	cout << "Привет, лаб3 parallel!";
#endif

	//1)
	{
		vector<int> v;
		const int N = 10;
		const int M = 5;

		std::promise<int> promise1;
		std::promise<int> promise2;
		std::mutex m;

		std::thread th1(thread_func1, ref(v),N,std::ref(m),std::ref(promise1));
		std::thread th2(thread_func2, ref(v),M,std::ref(m),std::ref(promise2));
		std::thread th3(thread_transform, ref(v), std::ref(promise1), std::ref(promise2));
		th1.detach();
		th2.detach();
		std::cout<< "main [ " <<std::this_thread::get_id()<< "]";

		std::cout << "\nSLEEP MAIN";
		this_thread::sleep_for(3s);
		std::cout << "\nRESUME MAIN";
		th3.join();
		std::cout << "\nres v: ";
		printCont(v);
	}

	//2)
	{
		spinlock sp;
	
		string s = "spinlock";
		std::thread th1(myThread, ref(sp),ref(s));
		std::thread th2(myThreadLockGuard, ref(sp), ref(s));
		std::thread th3(myThreadUniqGuard, ref(sp), ref(s));



		stop
	}
	return 0;
}