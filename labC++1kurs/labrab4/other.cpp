#include "other.h"
#include <iostream>
#include <cstdarg>

///////////////////////////////////////////////////
int IncByValue(int a)
{return(a+1);}
void IncByReference(int &r)
{
 r++;//r +=1;//(&r+1);
}// �� ������ �������� � ��������
void IncByPointer (int * count)
{
 (*count)++;
}
void Swap(int * x,int * y)
{int temp;
  temp = *x;
  *x=*y;
  *y=temp;
}

//void Swap(int &x,int &y)// �����  ���- ����� ������������ �
void Swap(int &x,int &y)
{int temp;
 temp = x;
 x=y;
 y=temp;
}

//int Min (int (*par)[M],int n)//int par[][M]
int Min (int *par,int n)//int par[][M]
{int min =(*par);
 for(int i = 0;i<n;i++)
 {if(min>(*par)) min=(*par);
  par++;
 }
 return(min);
}

int Min2 (int (*par)[M],int ni)// �������� ����� � ���� ��������
{int min =par[0][0];
 for(int i = 0;i<ni;i++)
  for(int j= 0;j<M;j++)
   if(min>par[i][j]) min=par[i][j];
 return(min);
}
//���1
int Min3(int *p,int n)
{int min =(*p);
 for(int i = 0;i<n;i++)
  {if(min>(*p)) min=(*p);
   p++;
  }
 return(min);
}// End Min3
int Min4(int **pn,int iN,int jM)
{int min =pn[0][0];
 for(int i = 0;i<iN;i++)
  for(int j= 0;j<jM;j++)
   if(min>pn[i][j]) min=pn[i][j];
  return(min);
}
int MyStrCmp(const char* p1,const char*p2)
{ while(*p1==*p2)
   {	
	   if((*p1)==0) return(0);
		p1++;
		p2++;
   }
 return(*p1-*p2);
}
//3
int DayOfYear(int fDay,int fMonth,int fYear,int (&ar)[2][12])
{bool isLeapYear = (!fYear%400) ||(fYear%100&&!fYear%4);//==1 �����
 int n=sizeof(ar[0])/sizeof(ar[0][0]);// ����� �� � ������  
 int Sum=0;
 for(int i=1; i<fMonth;i++)
  {Sum=Sum+ar[isLeapYear][i-1];
  }
  Sum=Sum+fDay;
  return(Sum);
 }
 void DayOfMonth(int fYear,int fnDayYear,int &rDay,int &rMonth,int (&ar)[2][12])
 {bool isLeapYear = (!fYear%400) ||(fYear%100&&!fYear%4);//==1 �����
  int n=sizeof(ar[0])/sizeof(ar[0][0]);// ����� �� � ������  
  int Sum=0;//ar[isLeapYear][0];
  int i=0;
  for(;Sum<fnDayYear;i++)
    {
		Sum=Sum+ar[isLeapYear][i];
    }
  rMonth=i;
  rDay=ar[isLeapYear][i-1]-(Sum-fnDayYear);

 }
//��������
 int RecSum(int n)
 {
  if(!n) return(0); 
  else
   {
	int s=RecSum(n-1);
    return(n+s);
		

   }
   
 }
//���������-��������� ��� ������� 5�
//��� ������������� ��������

void VarArgs(int arg1,...)
{
	int number = 0;	//������� ���������
	//�������� ��������� �� int � ��������������� ��� �������
	//������� ���������
	int * p=&arg1;
	//���� �� ��������� ����� ������:
	while(*p!=0)
	{  
 	// �) ������ �������� ���������� ���������
    printf("\nelement(%d)=%d",number,*p);
	// �) ����������� ��������� (�� ������ ��������� ��
	//��������� �������� ������)
	// �) ��������� ������� ���������
	p++;
    number++;
	}



	//������ ����� ���������
   printf("\nkol_el=%d",number);
}

void Args(int arg1,...)
 {int number = 0;	//������� ���������
  int i = arg1;
  va_list marker;//������������� ��������� �� arg;
  va_start (marker,arg1);// ��� ���� � 1 ��������� ���_�
  while(i!=0)
   {
	printf("\nelementM(%d)=%d",number,i);
    number++;
    i=va_arg(marker,int);
   }
  va_end(marker);
  printf("\nkol_elM=%d",number);
 }



