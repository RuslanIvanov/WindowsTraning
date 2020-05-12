#include "Header.h"
#include "functions.h"
#include "spinlock.h"
#include "threadsafe_stack.h"
#include "A.h"
#include "MyThQueue.h"

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
		//ref ?? future - отпр в 3 
		std::thread th1(thread_func1, ref(v),N,std::ref(m),std::ref(promise1));
		std::thread th2(thread_func2, ref(v),M,std::ref(m),std::ref(promise2));
		std::thread th3(thread_transform, ref(v), std::ref(promise1), std::ref(promise2));//future
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

		th1.join();
		th2.join();
		th3.join();
		
		{//тест spinlock
			
				threadsafe_stack st;
				vector<thread> readers;
				vector<thread> writers;

				int NR = 0; const int NPUSH = 10;

				cout << "\nEnter readers count: ";
				std::cin >> NR;
				auto begin = std::chrono::steady_clock::now();
				st.push(-1);
				//заполнить стек
				for (int i = 0; i < NPUSH; i++)
				{
					st.push(i);
				}

				threadsafe_stack st2 = st;
				st2.print();

				threadsafe_stack st3 = move(st2);
				st3.print();
				if (st2.empty()) { std::cout << "\nst2 is empty!"; }

				threadsafe_stack st4;
				st4.push(100);
				st4.push(200);
				st4.push(300);
				st3 = move(st4);
				st2 = st3;
				stop
					//читать стек		
					for (int i = 0; i < NR; i++)
					{
						readers.emplace_back(fReaders, ref(st));
					}

				writers.emplace_back(fWriters, ref(st), NPUSH);
				writers.emplace_back(fWriters, ref(st), NPUSH + 1);

				readers.emplace_back(fReaders, ref(st));

				writers.emplace_back(fWriters, ref(st), NPUSH + 2);

				readers.emplace_back(fReaders, ref(st));

				std::cout << "\nrun main";
				std::cout << "\nSLEEP MAIN";
				this_thread::sleep_for(3s);
				std::cout << "\nRESUME MAIN";

				for (size_t i = 0; i < writers.size(); i++)
				{
					writers[i].join();
				}

				size_t NV = readers.size();
				for (size_t i = 0; i < NV; i++)
				{
					readers[i].join();
				}

				auto end = std::chrono::steady_clock::now();
				std::cout << "\ntime run stack: ";
				printTime(begin, end);

		}//*/

		stop
	}
	//3)
	{
		//std::atomic<A<int>> t(A(1));

		auto begin = std::chrono::steady_clock::now();	

		A<int> a(0);
		std::thread th1(funcMakeA, 0);
		std::thread th2(funcMakeA, 0);
		std::thread th3(funcMakeA, 0);
		th1.join();
		th2.join();
		th3.join();
		auto end = std::chrono::steady_clock::now();
		std::cout << "\ntime run A0: ";
		printTime(begin, end);

		begin = std::chrono::steady_clock::now();
		A<int> a1(1);
		std::thread th11(funcMakeA, 1);
		std::thread th22(funcMakeA, 1);
		std::thread th33(funcMakeA, 1);
		th11.join();
		th22.join();
		th33.join();
		end = std::chrono::steady_clock::now();
		std::cout << "\ntime run A1: ";
		printTime(begin, end);

		begin = std::chrono::steady_clock::now();
		A<int> a2(2);
		std::thread th111(funcMakeA, 2);
		std::thread th222(funcMakeA, 2);
		std::thread th333(funcMakeA, 2);

		th111.join();
		th222.join();
		th333.join();

		end = std::chrono::steady_clock::now();
		std::cout << "\ntime run A2: ";
		printTime(begin, end);

		std::cout << "\n count A "<<A<int>::getCountObj();

		stop
	}
	
	//4)
	{
		vector<thread> w;
		vector<thread> r;
		MyQueue q;
		size_t countR = 0;
		size_t countW = 0;
		cout << "\nEnter readers count: ";
		std::cin >> countR;
		cout << "\nEnter writers count: ";
		std::cin >> countW;

		for(size_t i=0; i< countW;i++)
			w.emplace_back(fWritersQ ,ref(q), 'A'+i);
		
		for (size_t i = 0; i < countR; i++)
			r.emplace_back(fReadersQ, ref(q));
		

		size_t NR = r.size();
		size_t NW = w.size();

		for (size_t i = 0; i < NW; i++)
			w[i].join();

		for (size_t i = 0; i < NR; i++)
			r[i].join();

			stop

	}
	std::cout << "\nTHE END!\n";
	return 0;
}