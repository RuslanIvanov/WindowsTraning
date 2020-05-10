
#include "Header.h"
#include "functions.h"
#include "templates.h"
#include "threadsafe_stack.h"
using namespace std;
using namespace chrono_literals;

const char* filespec[] = { "1.txt", "2.txt", "3.txt","4.txt" };
const char* _filespec[] = { "_1.txt", "_2.txt", "_3.txt","_4.txt" };

int _tmain(int argc, _TCHAR* argv[])
{

#if  _WIN32 
	setlocale(LC_CTYPE, ".UTF8");
	cout << "������, ���1 parallel!";
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
		tv[i].join();//����

		end = chrono::system_clock::now();
		auto diff = end - start;

		double mks = std::chrono::duration_cast<std::chrono::microseconds>(diff).count();
		double ms = std::chrono::duration_cast<std::chrono::milliseconds>(diff).count();
		double s = diff.count();
		cout << "\ntime: " << diff.count() << " ms: " << ms;
	//	cout << "\ntime: " << diff.count() << " s: " << s << " ms: " << ms << " mks: " << mks;
		stop
	}

	{// ������ �� ��� ��������
		unsigned int nKernel = std::thread::hardware_concurrency();
		std::cout << "\n\nKernels " << nKernel << " supported.\n";

		vector<thread> tv;
		string s_rez[sizeof(_filespec) / sizeof(_filespec[0])] = { "" };
		tv.reserve(sizeof(_filespec) / sizeof(_filespec[0]));
		chrono::time_point<chrono::system_clock> start, end;

		size_t N =  (sizeof(_filespec) / sizeof(_filespec[0])) - nKernel;//4 ?
		//if (N == 0) { N = nKernel/2; };

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
		{//��� ������������ ������� ������� �� ������ �����
			try
			{
				tv.at(i).join();//����
			}
			catch (std::out_of_range) 
			{
				cout << "\nerror: out_of_range";
			}
		}

		size_t N2 = sizeof(_filespec) / sizeof(_filespec[0]);
		for (unsigned int i = 0; i < N2; i = i + 1)
		{
			cout << "\n' " << s_rez[i] << " '";
		}

	}


	//2)
	{//Beep(261, <��������_�_��>);
		
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
			tv[i].detach();//����������� - ��� ������� 

		}

	
		std::cout << "\nSLEEP MAIN";
		this_thread::sleep_for(3s);
		std::cout << "\nRESUME MAIN";

		for (int i = 7; i < 7+7; i++)
		{
			tv.emplace_back(MyBeep, gamma[i-7].first, gamma[i-7].second);
			tv[i].join();// join - �����

		}


		std::cout << "\nSLEEP MAIN";
		this_thread::sleep_for(3s);
		std::cout << "\nRESUME MAIN";


		//3)
		//duration...
		using milliseconds = std::chrono::duration<long long, milli>;
		milliseconds ms = static_cast<milliseconds>('Z');
		for (char o = 'A'; o <= 'Z'; o++)
		{
			//this_thread::sleep_for(75ms*('Z' - o )); 
			this_thread::sleep_for(ms);
			ms = ms - 3ms;
			cout << "\n" << o<<" "<<static_cast<int>(o);
		}//*/
		stop
		//4)
		{
			//vector<int> values(1250000);
			//generate(begin(values), end(values), mt19937(42));

			unsigned short nThreads = 1;
			const unsigned short ELEMENTS = 100;
			unsigned short ELEMENS_FOR_TASK = 0;// ���� 0, �� ������ ����� �����������
			unsigned short ELEMENS_FOR_MAIN = 0;
			vector<int> vi(ELEMENTS);
			vector<int> vrez(vi.size());

			for (size_t i = 0; i < ELEMENTS; i++)
			{
				vi[i] = (i + 1) * (-1);
			}

			unsigned int nKernel = std::thread::hardware_concurrency();
			std::cout << "\n\nKernels " << nKernel << " supported.\n";

			cout << "Enter thread count: ";
			std::cin >> nThreads;

			if (nThreads > ELEMENTS || nThreads == 0)
			{ nThreads = 1; }
			else if (nThreads > 1 ) 
			{
				nThreads = nThreads - 1;
			}
			
			ELEMENS_FOR_TASK = ELEMENTS/nThreads;//100/3 = 33 => ELEMENTS - (33*nThreads) =  ost
			//int _ELEMENS_FOR_MAIN = ELEMENTS % nThreads;
			ELEMENS_FOR_MAIN = ELEMENTS - (ELEMENS_FOR_TASK * nThreads);
		
			//transform( vi.begin(), vi.end(), back_inserter(vrez), std::negate<int>());
			
			int last = ELEMENS_FOR_TASK;
			int first = 0;
			//������� 1
			////////////////////////////////////////////////////////////////////////////////////
			for (size_t i = 0; i < nThreads; i++)
			{
				first = (i * ELEMENS_FOR_TASK);
				auto start = std::chrono::steady_clock::now();
				//transform(std::execution::par, vi.begin() + first, vi.begin()+last, vrez.begin() + first, std::negate<int>());
				transform(std::execution::par, vi.begin() + first, vi.begin() + last, vrez.begin() + first, [first](int n)
					{
						std::cout << "i" << first;
						return abs(n);
					}
				);
				auto end = std::chrono::steady_clock::now();
				std::cout << "\n time: " << std::chrono::duration <double, std::milli>(end - start).count() << " ms\n";
				last+= ELEMENS_FOR_TASK;
			}

			if (ELEMENS_FOR_MAIN)
			{
				last = (ELEMENTS - ELEMENS_FOR_MAIN);
				
				auto start = std::chrono::steady_clock::now();
				transform(std::execution::par, vi.begin() + last, vi.end(), vrez.begin() + last, [last](int n)
					{
						std::cout << "i" << last;
						return abs(n);
					}
				);
				auto end = std::chrono::steady_clock::now();
				std::cout <<"\n time: "<< std::chrono::duration <double, std::milli>(end - start).count() << " ms\n";
			}
			std::cout << "\n\n";
			printCont(vrez);

			//�������2
			///////////////////////////////////////////////////////////////////////////////////////////////////
			last = ELEMENS_FOR_TASK;
			first = 0;
			vector<thread> tv;
			vector<int> vrez2(vi.size());
			auto start_th = std::chrono::steady_clock::now();
			for (int i = 0; i < nThreads; i++)
			{
				first = (i * ELEMENS_FOR_TASK);
				tv.emplace_back(tr, cref(vi), ref(vrez2), first, last);
				last += ELEMENS_FOR_TASK;
			}

			if (ELEMENS_FOR_MAIN)
			{
				last = (ELEMENTS - ELEMENS_FOR_MAIN);
				tr(vi, vrez2, last, ELEMENTS);
			}
			stop			

			for (int i = 0; i < tv.size(); i++)
			{
				tv[i].join();
			}
			auto end_th = std::chrono::steady_clock::now();

			double t = std::chrono::duration <double, std::milli>(end_th - start_th).count();
			std::cout << "\ntime run transform in threads: " << t <<" ms";
			std::cout << "\n\n";
			printCont(vrez);
			stop
		}
	}
	//5
	{
		threadsafe_stack st;
		vector<thread> readers;
		vector<thread> writers;

		int NR=0; const int NPUSH = 10;

		cout << "\nEnter readers count: ";
		std::cin >> NR;

		auto begin = std::chrono::steady_clock::now();
	
		st.push(-1);
		//��������� ����
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
		//������ ����		
		for (int i = 0; i < NR; i++)
		{
			readers.emplace_back(fReaders, ref(st));
		}
			
		writers.emplace_back(fWriters, ref(st), NPUSH);
		writers.emplace_back(fWriters, ref(st), NPUSH+1);
		
		readers.emplace_back(fReaders, ref(st));
		
		writers.emplace_back(fWriters, ref(st), NPUSH+2);

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

		std::cout << "\nTHE END";
    }

	
	return  0;
}