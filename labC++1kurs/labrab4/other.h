
//Прототипы используемых в данном задании функций:
int IncByValue(int);
void IncByReference(int &r);
void IncByPointer(int *);
void Swap(int*,int*);
void Swap(int &,int &);
const int N = 2;
const int M = 5;
int Min (int *,int);
int Min2(int (*par)[M],int);
int Min3(int *,int);
int Min4(int **pn,int,int);
int MyStrCmp(const char*,const char*);
//3
int DayOfYear(int,int,int,int (&pm)[2][12]);
 //int DayOfYear(int,int,int,int*ar=&nDayTab[2][12]);
void DayOfMonth(int,int,int&,int&,int(&ar)[2][12]);
int RecSum(int n);
void VarArgs(int arg1,...);
void Args(int arg1,...);