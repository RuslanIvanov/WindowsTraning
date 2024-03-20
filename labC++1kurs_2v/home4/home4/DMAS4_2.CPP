#define	  stop __asm nop
#include <cstdlib>
#include <cstdlib>
#include <ctime>
#include  <iostream>
#include "func4_2.h"
using namespace std;
int main()
 {int N,i;
	srand(time(0));
	N=rand()%8 + 2;
	int *p = new int [N];
	printf("MassIn:\n");
	for(i=0;i<N;i++)
	 {
		 p[i]=rand()%20;
		 printf("%d[%d] ",p[i],i);
	 }
 i=0;
 while(i<N)
 {printf("\nEnter number [i](0 - %d):",N-1);
  cin>>i;
  if(i>N) {printf("n\Error!\n"); break;}
  Minus_i(p,N,i);
  printf("N= %d",N);
  printf("\nNewMass:");
  for(int j=0;j<N;j++)
   printf("%d[%d] ",p[j],j);
 }
	delete [] p;
	p=0;
	stop
	return(0);
 }