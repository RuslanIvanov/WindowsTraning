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
//под параллельным выполнением алгоритма будем понимать выполнение на нескольких €драх CPU;
//под векторизацией будем понимать выполнение с задействованием векторных регистров процессора

/*
sequenced_policy (seq) говорит о том, что алгоритм может выполн€тьс€ последовательно [1].
parallel_policy (par) указывает на то, что алгоритм может выполн€тьс€ параллельно [1]. 
ѕользовательские функции, вызываемые во врем€ работы алгоритма, не должны порождать Ђгонку данныхї.

parallel_unsequenced_policy (par_unseq) указывает на то, что алгоритм может выполн€тьс€ параллельно и векторно [1].

unsequenced_policy (unseq) Ц класс, €вл€ющийс€ частью черновика Parallelism TS v2 [2] и показывающий, 
что алгоритм может выполн€тьс€ векторно. Ёта политика требует, чтобы все пользовательские функции, функторы, 
передаваемые в алгоритм в качестве параметров, не преп€тствовали векторизации (не содержали зависимостей по данным, 
не вызывали Ђгонки данныхї, и т.д.).

vector_policy (vec) (также из [2]) говорит о том, что алгоритм может выполнитьс€ векторно, но в отличие от unseq политика vec гарантирует обработку данных в том пор€дке, в каком они бы обрабатывались при последовательном выполнении (сохран€ет ассоциативность).

*/