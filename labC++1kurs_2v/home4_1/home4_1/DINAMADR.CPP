#define	  stop __asm nop
#include <cstdlib>
#include <cstdlib>
#include <ctime>
#include  <iostream>
int Ar1[3][3][3]={{{1,1,1},{4,4,4},{1,1,1}},
                  {{5,5,5},{2,2,2},{2,2,2}},
                  {{3,3,3},{3,3,3},{6,6,6}}};
int Ar2[3][3][3]={{{4,4,4},{1,1,1},{4,4,4}},
                  {{2,2,2},{5,5,5},{5,5,5}},
                  {{6,6,6},{6,6,6},{3,3,3}}};
int ArOut[3][3][3];
#include "func.h"
void main()
{//Задача 4.1а - для встроенного массива
 int *pAr1=&Ar1[0][0][0];
 int *pAr2=&Ar2[0][0][0];
 int *pArOut=&ArOut[0][0][0];
 int N=(sizeof(Ar1)/sizeof(Ar1[0][0][0]));
// max(pAr1,pAr2,pArOut,N);
 max(Ar1,Ar2,ArOut,N);
 //Вывод
 for(int i=0;i<N;i++)
	{printf("%d.",(*pAr1));
	 pAr1++;
	}
 printf("\n");
 for(int j=0;j<N;j++)
	{printf("%d,",(*pAr2));
	 pAr2++;
	}
 printf("\n");
 for(int k=0;k<N;k++)
	{printf("%d'",(*pArOut));
	 pArOut++;
	}
 printf("\n");
//---------------------------------------
{//*/Задача 4.1б - для динамического массива 
 srand( time( 0 ) );
 int N,M,K,t;
 N=rand()%2 + 2;
 M=rand()%2 + 2;
 K=rand()%2 + 2;
 printf("\n[%d][%d][%d]\n",N,M,K);
 int* pn1=new int[N*M*K];
 int* pn2=new int[N*M*K];
 int* pnOut=new int[N*M*K];
 for (int i =0;i<(N*M*K);i++)
	{
	 pn1[i]=rand()%10;
	 printf("%d.",pn1[i]);
	}
 printf("\n");
 for (int i =0;i<(N*M*K);i++)
 {pn2[i]=rand()%10;
	printf("%d,",pn2[i]);
 }
 max(pn1,pn2,pnOut,(M*N*K));
 printf("\nOutDinMas:\n");
 for (int i =0;i<(N*M*K);i++)
	{printf("%d'",pnOut[i]);
	}
 delete [] pn1;
 delete [] pn2;
 delete [] pnOut;
 pn1=0;
 pn2=0;
 pnOut=0;
}//*
stop
}//End main
