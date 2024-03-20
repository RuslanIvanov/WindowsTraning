//Задача 3.3
#define	  stop __asm nop
#include <cstdlib>
#include <cstdlib>
#include <ctime>
#include  <iostream>
void main()
{
 int N;
 int M;
 srand( time( 0 ) );
 N=rand()%8+2;
 printf("\nN=%d\n",N);
 int **p= new int*[N];
 for(int i=0;i<N;i++)
  {
   M=i+1;  
   p[i] = new int[M];
   for(int j=0;j<M;j++)
    {p[i][j]=M;
	 printf("%d",p[i][j]);
	}
    printf("\n");
  }
  delete [] p;
  p=0;
  stop
}