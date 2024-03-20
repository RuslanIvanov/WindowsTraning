#define	  stop __asm nop
#include <cstdlib>
#include <cstdlib>
#include <ctime>
#include  <iostream>
#include "work.h"
using namespace std;
int main()
{int Ar[10]={1,2,3,-5,-9,20,15,11,5,0};
 int res=0;
 int i;
 const int N = sizeof(Ar)/sizeof(Ar[0]);
 int (*f[])(int*,int)={Max,Min,Sred};
 printf("\nEnter func: 0)Max,1)Min,2)Sred:");
  cin>>i;
 if(i>=0&&i<3)
  {res=(*f[i])(Ar,N);
   printf("\nres = %d",res);
  }
 else printf("\nError i!!!");
 stop
}