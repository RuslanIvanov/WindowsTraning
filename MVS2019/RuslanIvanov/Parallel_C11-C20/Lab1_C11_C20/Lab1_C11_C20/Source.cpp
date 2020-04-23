
#include <iostream>
#include <iterator>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <string.h>
#include <typeinfo>
#include <thread>
#include <chrono>
#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;
using namespace chrono_literals;
#include "Header.h"
#if  _WIN32 

#define	  stop __asm nop
#include <tchar.h>

#else

#define _tmain main
#define _TCHAR char 

void mystop()
{//Linux
	std::cout << "\nPause\n";
	getchar();
}

#define  stop  {mystop();}
#endif

void test() { cout << " test "; }

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

		cout << "\ntime run: " << diff.count() << " s\n";

		chrono::seconds _s(diff.count());
		chrono::milliseconds _ms(diff.count());
		chrono::microseconds _mss(diff.count());

		cout << "\ntime run: " << diff.count() << " _s: " << _s.count() << ": _ms " << _ms.count() << " _mss: " << _mss.count();

		double mks = std::chrono::duration_cast<std::chrono::microseconds>(diff).count();
		double ms = std::chrono::duration_cast<std::chrono::milliseconds>(diff).count();
		double s = diff.count();

		cout << "\ntime run: " << diff.count() << " s: " << s << " ms: " << ms << " mks: " << mks;
		stop
	}

	/*transform(begin(s_rez),std::end(s_rez),begin(s_rez), predUpperStr());// ����� ���� � �����

	std::chrono::time_point<std::chrono::steady_clock> start2, end2;
	
	for (int i = 0; i < sizeof(_filespec) / sizeof(_filespec[0]); i++)
	{
		start2 = std::chrono::steady_clock::now();
		thread th(writeToFile, _filespec[i], ref(s_rez[i]));
		stop
		th.join();// ����
		end2 = std::chrono::steady_clock::now();
		auto diff = (end2 - start2);
				
		chrono::seconds _s (diff.count());
		chrono::milliseconds _ms(diff.count());
		chrono::microseconds _mss(diff.count());
		
		cout << "\ntime run: " << diff.count()<< " _s: " << _s.count()  <<": _ms "<< _ms.count() << " _mss: "<< _mss.count();

		double mks = std::chrono::duration_cast<std::chrono::microseconds>(diff).count();
		double ms = std::chrono::duration_cast<std::chrono::milliseconds>(diff).count();
		double s = diff.count();

		cout << "\ntime run: " << diff.count() << " s: " << s << " ms: " << ms << " mks: " << mks;
	}//*/

	

	{// ������ �� ��� ��������
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
				//tv[(i* nKernel) +ii].join();//����
			}

			end = chrono::system_clock::now();
			chrono::duration<double> diff = end - start;
			cout << "\ntime run: " << diff.count() << " s\n";
			
			stop
		}

		for (unsigned int i = 0; i < (sizeof(_filespec) / sizeof(_filespec[0])); i++)
		{//��� ������������ ������� ������� �� ������ �����
			tv[i].join();//����
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

		for (char o = 'A'; o < 'Z'; o++)
		{
		//	this_thread::sleep_for<char, int>(1s); / +o);
			cout << "\n" << o;
		}
		
	}
	return  0;
}