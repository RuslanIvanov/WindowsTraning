#pragma once

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
#include <execution>
#include <random>
#include <functional>

#if  _WIN32 

#define	  stop __asm nop
#include <tchar.h>
#include <Windows.h>
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


//commets:
//��� ������������ ����������� ��������� ����� �������� ���������� �� ���������� ����� CPU;
//��� ������������� ����� �������� ���������� � ��������������� ��������� ��������� ����������

/*
sequenced_policy (seq) ������� � ���, ��� �������� ����� ����������� ��������������� [1].
parallel_policy (par) ��������� �� ��, ��� �������� ����� ����������� ����������� [1]. 
���������������� �������, ���������� �� ����� ������ ���������, �� ������ ��������� ������ �������.

parallel_unsequenced_policy (par_unseq) ��������� �� ��, ��� �������� ����� ����������� ����������� � �������� [1].

unsequenced_policy (unseq) � �����, ���������� ������ ��������� Parallelism TS v2 [2] � ������������, 
��� �������� ����� ����������� ��������. ��� �������� �������, ����� ��� ���������������� �������, ��������, 
������������ � �������� � �������� ����������, �� �������������� ������������ (�� ��������� ������������ �� ������, 
�� �������� ������ �������, � �.�.).

vector_policy (vec) (����� �� [2]) ������� � ���, ��� �������� ����� ����������� ��������, �� � ������� �� unseq �������� vec ����������� ��������� ������ � ��� �������, � ����� ��� �� �������������� ��� ���������������� ���������� (��������� ���������������).

*/