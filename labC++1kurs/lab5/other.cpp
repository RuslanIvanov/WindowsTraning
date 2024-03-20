#include "other.h"
#include <cmath>
#include <iostream>
#define	  stop __asm nop

///////////////////////////////////////////////////
//1
double Sum (double a,double b)
{return (a+b);
}
double Sub (double a,double b)
{return (a-b);
}
double Mul (double a,double b)
{return (a*b);
}
double Div (double a,double b)
{return (a/b);
}
double MyPow (double a,double b)
{return(pow(a,b));
}
//1'


void Sort(char* pcFirst, int nNumber, int size,
	 void (*Swap)(void*, void*), int (*Compare)(void*, void*) )
{
	int i;
	for(i=1; i<nNumber; i++)
		for(int j=nNumber-1; j>=i; j--)
		{
			char* pCurrent = pcFirst+j*size;
			char* pPrevious = pcFirst+(j-1)*size;
			if((*Compare)( pPrevious, pCurrent ) > 0)//требуется
												//переставить
				(*Swap)( pPrevious, pCurrent );
		}
}

void SwapInt(void* p1, void* p2)
{int temp;
  temp = *(static_cast<int*>(p1));
  *(static_cast<int*>(p1))=*(static_cast<int*>(p2));
  *(static_cast<int*>(p2))=temp;
}

int CmpInt(void* p1, void* p2)
{
	int nResult;
if(*(static_cast<int*>(p1))<*(static_cast<int*>(p2)))
 nResult = -1;
else if(*(static_cast<int*>(p1))>*(static_cast<int*>(p2)))
 nResult = 1;
     else nResult = 0;



	return nResult;
}

void SwapDouble(void* p1, void* p2)
{double temp;
  temp = *(static_cast<double*>(p1));
  *(static_cast<double*>(p1))=*(static_cast<double*>(p2));
  *(static_cast<double*>(p2))=temp;
}

int CmpDouble(void* p1, void* p2)
{int nResult;
 if(*(static_cast<double*>(p1))<*(static_cast<double*>(p2)))
  nResult = -1;
 else if(*(static_cast<double*>(p1))>*(static_cast<double*>(p2)))
 nResult = 1;
      else nResult = 0;
return nResult;
}
void SwapStr (void* p1, void* p2)
{char i;
/* char *temp=&i;
 *temp = *(static_cast<char*>(p1));
 *(static_cast<char*>(p1))=*(static_cast<char*>(p2));
 *(static_cast<char*>(p2))=*temp;*/
stop
}
int CmpStr(void* p1, void* p2)
{int nResult;
 /*if(*(static_cast<char*>(p1))<*(static_cast<char*>(p2)))
  nResult = -1;
 else if(*(static_cast<char*>(p1))>*(static_cast<char*>(p2)))
 nResult = 1;
      else nResult = 0;*/
nResult = strcmp(static_cast<const char*>(p1), static_cast<const char*>(p2));
return nResult;
}
//3
const char* GetString1()
{return ("AAAAA");
}
const char* GetString2()
{
	return ("BBBBBBB");
}
const char* GetString3()
{return ("CCCCCCC c");
}
//void PrintfStruct(BOOK b)
void PrintfStruct(const struct BOOK *pb)
{printf("\nOutStrFunc:\n%s\n%s\n%d\n%d\n%d",pb->Name,pb->NameBook,pb->Year,pb->cena,pb->kat);
	
}

void LibBookStr(struct LIB_BOOK *lb,int n)
 {int i=0;
	do
	{printf("\nPlease Enter BOOK number %d\n",i+1);
	printf("\nEnter Name Autor: ");
     scanf("%29s",&lb[i].Name);
	 fflush(stdin);
	 printf("\nEnter Name Book: ");
     scanf("%29s",&lb[i].NameBook);
	 fflush(stdin);
	 printf("\nYear: ");
     scanf("%d",&lb[i].Year);
	 while(!(lb[i].Year>=1990&&lb[i].Year<=2007))// Если ввел правильно ти цикл не испон
      {printf("Eror Year, Enter Year(1990-2007):");
	   scanf("%d",&lb[i].Year);
	  }
	 printf("\nCena: ");
     scanf("%lf",&lb[i].cena);
	 while(!(lb[i].cena>0.0))// Если ввел правильно ти цикл не испон
      {printf("Eror Cena>0, Enter Cena:");
	   scanf("%lf",&lb[i].cena);
	  }
	 printf("\nKategorija : ");
     scanf("%d",&lb[i].kat); 
	 while(!(lb[i].kat>=1&&lb[i].kat<=9))// Если ввел правильно тo цикл не испон
      {printf("Eror Kat, Enter Kat 1-9:");
	   scanf("%d",&lb[i].kat);
	  }
	 i++;
	 //lb+i;//&lb->cena
    }
   while(i<n);

 }