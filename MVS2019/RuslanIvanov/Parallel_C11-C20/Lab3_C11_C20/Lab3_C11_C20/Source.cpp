#include "Header.h"


using namespace std;
using namespace chrono_literals;

int _tmain(int argc, _TCHAR* argv[])
{

#if  _WIN32 
	setlocale(LC_CTYPE, ".UTF8");
	cout << "Привет, лаб3 parallel!";
#endif

	return 0;
}