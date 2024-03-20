//Задача 
#define	  stop __asm nop
#include <cstdlib>
#include <cstdlib>
#include <ctime>
#include  <iostream>
char A[]={"123456789101жээжл\\э"};
char *p1=A;
char*p2 = p1+sizeof(A)-2;
void main()
{
 char *pA = A;
 printf("\n%s",pA);
 for(int i=0;i<(sizeof(A)-1)/2;i++)
  {char tmp;
   tmp=*(p1+i);
   *(p1+i)=*(p2-i);
   *(p2-i)=tmp;
  }
 printf("\n%s",pA);
 stop
}
