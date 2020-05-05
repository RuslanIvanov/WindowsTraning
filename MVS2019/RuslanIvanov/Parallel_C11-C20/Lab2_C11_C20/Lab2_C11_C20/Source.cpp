#include "Header.h"
#include "functions.h"
#include "templates.h"
#include "ClassA.h"
#include "ClassicSingleton.h"
#include "thread_pool.h"

using namespace std;
using namespace chrono_literals;

int _tmain(int argc, _TCHAR* argv[])
{

#if  _WIN32 
	setlocale(LC_CTYPE, ".UTF8");
	cout << "Привет, лаб2 parallel!";
#endif


	/*
	Параллельные алгоритмы std, thread_local, once_flag, call_once, mutex, async, future, conditional_variable
	Задание 1. Параллельные алгоритмы std
	Сформируйте std::vector<int> - вектор должен быть достаточно большим!
	Проинкриментируйте значения всех элементов последовательным for_each() или transform(). Измерьте время работы
	Проинкриментируйте значения всех элементов параллельным for_each()или transform(). Попробуйте разные политики выполнения. Измерьте время работы.
	Сравните результаты
	Поэкспериментируйте с размером вектора

	*/
	{
		cout << "Enter vector size (0 is default = 500): ";
		unsigned short NV = 0;
		std::cin >> NV;

		if (NV == 0) {NV = 500;}

		vector <short> vi(NV, 100);
		std::cout << "\nno parallel: ";
		auto   start = std::chrono::steady_clock::now();
		for_each(vi.begin(), vi.end(), [](short& i) 
		{
				i++;
		});
		auto end = std::chrono::steady_clock::now();
		std::cout << "\ntime: " << std::chrono::duration <double, std::milli>(end - start).count() << " ms\n";

		start = std::chrono::steady_clock::now();
			transform(vi.begin(), vi.end(), vi.begin(),  [](short i) { return ++i; });
			//transform(vi.begin(), vi.end(), vi.begin(), incShort);
		end = std::chrono::steady_clock::now();

		printTime(start,end);
		stop
		////////////////////////////////////////////////////////////////////////////////////////
		//указывает на то, что алгоритм может выполняться параллельно
		std::cout << "\nparallel transform execution::par: ";
		start = std::chrono::steady_clock::now();
		transform(std::execution::par, vi.begin(), vi.begin(), vi.begin(), [](short i)
		{		
			return ++i;
		}
		);
		end = std::chrono::steady_clock::now();
		printTime(start, end);
		stop
		std::cout << "\nparallel for_each execution::par: ";
		start = std::chrono::steady_clock::now();
		for_each(std::execution::par,vi.begin(), vi.end(), [](short& i)
		{
				i++;
		});
		end = std::chrono::steady_clock::now();
		printTime(start, end);
		stop
		///////////////////////////////////////////////////////////////////////////////////////
		//указывает на то, что алгоритм может выполняться параллельно и векторно
		std::cout << "\nparallel transform execution::par_unseq: ";
		start = std::chrono::steady_clock::now();
		transform(std::execution::par_unseq, vi.begin(), vi.begin(), vi.begin(), [](short i)
			{
				return ++i;
			}
		);
		end = std::chrono::steady_clock::now();
		printTime(start, end);
		stop
			std::cout << "\nparallel for_each execution::par_unseq: ";
		start = std::chrono::steady_clock::now();
		for_each(std::execution::par_unseq, vi.begin(), vi.end(), [](short& i)
			{
				i++;
			});
		end = std::chrono::steady_clock::now();
		printTime(start, end);
		stop
		//////////////////////////////////////////////////////////////////////////////////////
		//говорит о том, что алгоритм может выполняться последовательно
		std::cout << "\nparallel transform execution::seq: ";
		start = std::chrono::steady_clock::now();
		transform(std::execution::seq, vi.begin(), vi.begin(), vi.begin(), [](short i)
			{
				return ++i;
			}
		);
		end = std::chrono::steady_clock::now();
		printTime(start, end);
		stop
			std::cout << "\nparallel for_each execution::seq: ";
		start = std::chrono::steady_clock::now();
		for_each(std::execution::seq, vi.begin(), vi.end(), [](short& i)
			{
				i++;
			});
		end = std::chrono::steady_clock::now();
		printTime(start, end);
		stop
		/////////////////////////////////////////////////////////////////////////////////////////////
		
	}

	//2)
	{

		vector<thread> tv;
		vector<future<size_t>> tf;
		const unsigned int N = 10;
		for (unsigned int i = 0; i < N; i++)
		{
			char buf[80] = "";
			sprintf_s(buf, 80, "thread name_%d", i);
			string name(buf);
			//tv.emplace_back(funcMakeA, name,i);
			tf.push_back( async(std::launch::async,funcMakeA, name, i) );//Создание и исполнение птока в произвольном порядке
			//tf.push_back(async(std::launch::deferred, funcMakeA, name, i));//в get(), при вызове начинасется последовательно ваполн функции потока
		}

		cout << "\nHEADER N threads :\n"<<N;
		
		/*
		пока запущенные потоки работают, делаем ПОЛЕЗНУЮ работу, например, выводим заголовок - что за заголовок ???
		*/
		for (unsigned int i = 0; i < tf.size(); i++)
		{
			//tf[i].wait();//лишний
			cout << "\nTHREAD STOP id = " << tf[i].get();//---> wait		
		}
		stop
	}
	//3)
	{
		unsigned int nKernel = std::thread::hardware_concurrency();
		std::cout << "\n\nKernels " << nKernel << " supported.\n";

		std::cout << "\nEnter threads ( 0 = count kernels) : "; 
		unsigned int nThread = 0;
		std::cin >> nThread;
		if (nThread == 0) { nThread = nKernel; }

		const unsigned short NV2 = 15000;
		
		vector <short> vs(NV2, 1);
		short vsum = 0;
		vector<future<short>> vf(nThread);

		auto begin = std::chrono::steady_clock::now();
		auto sum = accumulate(vs.begin(), vs.end(), 0);
		auto end = std::chrono::steady_clock::now();

		cout << "\nsum = " << sum;
		printTime(begin, end);
		
		stop
		unsigned int elementsForTask = NV2/nThread;
		unsigned int first = 0;
		unsigned int last= elementsForTask;
		unsigned int ost = NV2 % nThread;
		begin = std::chrono::steady_clock::now();
		for (size_t i = 0; i < nThread; i++)
		{
			first = (i * elementsForTask);

			if (i == (nThread - 1))
				last = (last + ost);

			vf[i] = async(std::launch::async,accumulate<vector<short>::iterator, short>, vs.begin()+first, vs.begin()+last,0);
			
			
		    last += elementsForTask;
		}
		end = std::chrono::steady_clock::now();

		for (size_t i = 0; i < nThread; i++)
		{
			vsum+=vf[i].get();
		}

		cout << "\nvsum = " << vsum;
		printTime(begin, end);
		
	}
	//4
	{
		std::cout << "\nEnter num : ";
		string strNum;
		std::cin >> strNum;

		future<int> f = async(std::launch::async, makeIntFormStr, strNum);

		try 
		{
			int rez = f.get();
			cout << "\nrez = " << rez;
		}
		catch (const char* e) 
		{
			cout << "\nEXCEPTION: " << e;
		}

	}

	//5
	{

		auto thFunc = []() 
		{
			std::cout << std::hex << "\nAddr of singleton object: " << ClassSingleton::getInstance() << std::endl;
		};

		std::thread arr[] =
		{
			std::thread(thFunc), std::thread(thFunc), std::thread(thFunc)
		};

		for (std::thread& thr : arr)
		{
			thr.join();
		}
		std::cout << "\nTest end singl\n";
		stop
		auto thFunc2 = []()
		{
			std::cout << std::hex << "\nAddr of singleton object: " << ClassSingletonThread::getInstance() << std::endl;
		};

		std::thread arr2[] =
		{
			std::thread(thFunc2), std::thread(thFunc2), std::thread(thFunc2)
		};

		for (std::thread& thr : arr2)
		{
			thr.join();
		}

		std::cout << "\nTest end singl thread\n";
		stop
	}

	//6
	{
		std::cout << "\nEnter count tasks : ";

		size_t nTask = 0;
		std::cin >> nTask;

		thread_pool tp;
		for (size_t i = 0; i < nTask; i++)
		{
			std::function<void()> f_display = mytask;
			tp.add_task(f_display);
			//tp.add_task(std::function<void()>{mytask});
		}

		if (!tp.isEmpty()) { std::this_thread::sleep_for(1s); }
		stop
		
	}
	return 0;
}