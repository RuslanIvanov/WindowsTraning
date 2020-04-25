
#include "Header.h"
#include "functions.h"

using namespace std;
using namespace chrono_literals;

const char* filespec[] = { "1.txt", "2.txt", "3.txt","4.txt" };
const char* _filespec[] = { "_1.txt", "_2.txt", "_3.txt","_4.txt" };

int _tmain(int argc, _TCHAR* argv[])
{

#if  _WIN32 
	setlocale(LC_CTYPE, ".UTF8");
	cout << "ѕривет, лаб1 parallel!";
#endif

	//1)
	vector<thread> tv;
	string s_rez[sizeof(filespec) / sizeof(filespec[0])] = { "" };
	tv.reserve(sizeof(filespec) / sizeof(filespec[0]));
	chrono::time_point<chrono::system_clock> start , end;
	for (int i = 0; i < sizeof(filespec) / sizeof(filespec[0]); i++)
	{
		start = chrono::system_clock::now();

		//tv.emplace_back(readFromFile,filespec[i], ref(s_rez[i]));
		tv.emplace_back(readWriteAndChangeFromFile, filespec[i]);
		tv[i].join();//ждем

		end = chrono::system_clock::now();
		auto diff = end - start;

		double mks = std::chrono::duration_cast<std::chrono::microseconds>(diff).count();
		double ms = std::chrono::duration_cast<std::chrono::milliseconds>(diff).count();
		double s = diff.count();
		cout << "\ntime: " << diff.count() << " ms: " << ms;
	//	cout << "\ntime: " << diff.count() << " s: " << s << " ms: " << ms << " mks: " << mks;
		stop
	}

	{// читаем то что записали
		unsigned int nKernel = std::thread::hardware_concurrency();
		std::cout << "\n\nKernels " << nKernel << " supported.\n";

		vector<thread> tv;
		string s_rez[sizeof(_filespec) / sizeof(_filespec[0])] = { "" };
		tv.reserve(sizeof(_filespec) / sizeof(_filespec[0]));
		chrono::time_point<chrono::system_clock> start, end;

		size_t N =  (sizeof(_filespec) / sizeof(_filespec[0])) - nKernel;
		for (unsigned int i = 0; i < N; i++)
		{
			start = chrono::system_clock::now();
			for (size_t ii = 0; ii < nKernel; ii++)
			{ 
				tv.emplace_back(readFromFile, _filespec[(i* nKernel) +ii], ref(s_rez[(i* nKernel) +ii]));
			}

			end = chrono::system_clock::now();
			chrono::duration<double> diff = end - start;
			//cout << "\ntime run: " << diff.count() << " s\n";

			double mks = std::chrono::duration_cast<std::chrono::microseconds>(diff).count();
			double ms = std::chrono::duration_cast<std::chrono::milliseconds>(diff).count();
			double s = diff.count();
			cout << "\ntime: " << diff.count() << " ms: " << ms;
			//cout << "\ntime: " << diff.count() << " s: " << s << " ms: " << ms << " mks: " << mks;
			stop
		}

		for (unsigned int i = 0; i < (sizeof(_filespec) / sizeof(_filespec[0])); i++)
		{//при параллельном запуске потоков на разных €драх
			tv[i].join();//ждем
		}

		size_t N2 = sizeof(_filespec) / sizeof(_filespec[0]);
		for (unsigned int i = 0; i < N2; i = i + 1)
		{
			cout << "\n' " << s_rez[i] << " '";
		}

	}


	//2)
	{//Beep(261, <интервал_в_мс>);
		/*
		vector<thread> tv;
		pair<unsigned int, unsigned int> gamma[] = 
		{ 
			make_pair(261,180),
			make_pair(293,180),
			make_pair(329,180),
			make_pair(349,180),
			make_pair(392,180),
		    make_pair(440,180),
			make_pair(493,180)
		};
		
		tv.reserve(7);

		for (int i = 0; i < 7; i++)
		{
			tv.emplace_back(MyBeep, gamma[i].first, gamma[i].second);
			tv[i].detach();//отсоединили - дл€ аккорда 

		}

	
		std::cout << "\nSLEEP MAIN";
		this_thread::sleep_for(3s);
		std::cout << "\nRESUME MAIN";

		for (int i = 7; i < 7+7; i++)
		{
			tv.emplace_back(MyBeep, gamma[i-7].first, gamma[i-7].second);
			tv[i].join();// join - гамма

		}


		std::cout << "\nSLEEP MAIN";
		this_thread::sleep_for(3s);
		std::cout << "\nRESUME MAIN";


		//3)

		for (char o = 'A'; o <= 'Z'; o++)
		{
			this_thread::sleep_for(75ms*('Z' - o )); 
			cout << "\n" << o<<" "<<static_cast<int>(o);
		}//*/

		//4)
		{
			//vector<int> values(1250000);
			//generate(begin(values), end(values), mt19937(42));
			
			unsigned short nThreads = 1;
			const unsigned short ELEMENTS = 100;
			unsigned short ELEMENS_FOR_TASK = 0;// если 0, то попток сразу завершитьс€
			unsigned short ELEMENS_FOR_MAIN = 0;
			vector<int> vi(ELEMENTS);
			vector<int> vrez(vi.size());
			for (size_t i = 0; i < ELEMENTS; i++)
			{
				vi[i] = (i+1)*(-1);
			}
			//vrez.reserve(vi.size());

			unsigned int nKernel = std::thread::hardware_concurrency();
			std::cout << "\n\nKernels " << nKernel << " supported.\n";

			cout << "Enter thread count: ";
			std::cin >> nThreads;

			if (nThreads > ELEMENTS) { nThreads = ELEMENTS; }
			nThreads = nThreads - 1;
			
			ELEMENS_FOR_TASK = ELEMENTS/nThreads;//100/3 = 33 => ELEMENTS - (33*nThreads) =  ost
			//int _ELEMENS_FOR_MAIN = ELEMENTS % nThreads;
			ELEMENS_FOR_MAIN = ELEMENTS - (ELEMENS_FOR_TASK * nThreads);
		
			//transform( vi.begin(), vi.end(), back_inserter(vrez), std::negate<int>());
			
			int last = ELEMENS_FOR_TASK;
			int first = 0;
			for (size_t i = 0; i < nThreads; i++)
			{
				first = (i * ELEMENS_FOR_TASK);
				
				//transform(std::execution::par, vi.begin() + first, vi.begin()+last, vrez.begin() + first, std::negate<int>());
				transform(std::execution::par, vi.begin() + first, vi.begin() + last, vrez.begin() + first, [](int n)
					{
						return abs(n);
					}
				);
				last+= ELEMENS_FOR_TASK;
			}

			if (ELEMENS_FOR_MAIN)
			{
				last = (ELEMENTS - ELEMENS_FOR_MAIN);
				//
				//transform(vi.begin() + first, vi.begin() + last, vrez.begin() + first, std::negate<int>());
				transform(std::execution::par, vi.begin() + last, vi.end(), vrez.begin() + last, [](int n)
					{
						return abs(n);
					}
				);
			}
			stop
		}
	}
	return  0;
}