//1
double Sum (double,double);
double Sub (double,double);
double Mul (double,double);
double Div (double,double);
double MyPow (double,double);


//Прототипы используемых в данном задании функций:

void Sort(char* pcFirst, int nNumber, int size,
	 void (*Swap)(void*, void*), int (*Compare)(void*, void*) );
void SwapInt(void* p1, void* p2);
int CmpInt(void* p1, void* p2);
void SwapDouble(void* p1, void* p2);
int CmpDouble(void* p1, void* p2);
void SwapStr (void *p1, void *p2); 
int CmpStr(void *p1, void *p2);
const char* GetString1();
const char* GetString3();
const char* GetString2();
//автор, заглавие, год издания, цена, категория…
struct BOOK {// введен польз тип BOOK
	char Name [15];//(1*15)
	char NameBook [15];//(1*15)+2=32
	int Year;//4
	int cena;//4
	int kat;//4
};//15+15+2+4+4+4=44
  /*struct A {
	char a;//1
	char mas[2];//1+1+(1)
	int b;//4
};*/

 void PrintfStruct(const struct BOOK *);//функ прин указ на тип BOOK

 struct LIB_BOOK {
	char Name [30];
	char NameBook [30];
	int Year;
	int kat;
	double cena;
};
  void LibBookStr(struct LIB_BOOK *,int);
