#include "Header.h"
#include "functions.h"
#include "templates.h"
#include "ClassA.h"

using namespace std;
using namespace chrono_literals;

int _tmain(int argc, _TCHAR* argv[])
{

#if  _WIN32 
	setlocale(LC_CTYPE, ".UTF8");
	cout << "������, ���2 parallel!";
#endif


	/*
	������������ ��������� std, thread_local, once_flag, call_once, mutex, async, future, conditional_variable
	������� 1. ������������ ��������� std
	����������� std::vector<int> - ������ ������ ���� ���������� �������!
	������������������ �������� ���� ��������� ���������������� for_each() ��� transform(). �������� ����� ������
	������������������ �������� ���� ��������� ������������ for_each()��� transform(). ���������� ������ �������� ����������. �������� ����� ������.
	�������� ����������
	������������������� � �������� �������

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
		//��������� �� ��, ��� �������� ����� ����������� �����������
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
		//��������� �� ��, ��� �������� ����� ����������� ����������� � ��������
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
		//������� � ���, ��� �������� ����� ����������� ���������������
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
			tf.push_back( async(std::launch::async,funcMakeA, name, i) );//????
		}

		cout<<"th: "<<ClassA::getCount();
		//for (unsigned int i = 0; i < tv.size(); i++){tv[i].join();}

		for (unsigned int i = 0; i < tf.size(); i++)
		{
			tf[i].wait();
			cout << "\nth stop id" << tf[i].get();		
		}

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
	std::cout << "\nPress any key for exit...\n";
	getchar();

	return 0;
}