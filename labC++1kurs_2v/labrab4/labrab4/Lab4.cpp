
/*************************************************************
	������������ ������� �3. �������.
	����������, �����������, �����.
	�������� ����������. ����������� ��������.
	��������� �� �������
*************************************************************/
#include <iostream>
#include <tchar.h>
#include <cstdio>
#include <cstdarg>
#include <cstdlib>
#include <cstdlib>
#include <ctime> 
#include "other.h"

#define	  stop __asm nop

int _tmain()
{
	

	//������� 1. ������� ��� �������� ���������� �) �� ��������,
	// �) �� ������, �) �� ���������
	//�������� � ���������� ��� ������� , ������� ����������� ��������
	//� ������� ��������� �������� �� 1 ( �) - IncByValue(),
	// �) - IncByPointer(), �) - IncByReference() ). 
	//��������� ������������ � ������� ���������.
	//
	//���������: ���������� ������� ������� �������� � ������������ ����
	int val =1;//�������� ���� ���������� ������ ���� ��������� � �������
				//������ �� ������� �� �������
	val=IncByValue(val);
	printf("val1 = %d",val);
    IncByReference(val);
    printf("val2 = %d",val);
    IncByPointer(&val);
    printf("val3 = %d",val); 
	stop

/*
	//������� 1�. �������� ���������� c ������� ��������� � �� ������. 
	//������������� ����� �������.
	//�������� ������� (�������) Swap(), ������� ������ ��������
	//���������� nX � nY �������. 
	// �)������� ������ ��������� ��� ��������� �� int, �������� � 
	//�������� ������ �������� ���������� � ���������� ���������
	// �)������� ������ ��������� ��� ������ �� int 
	//��������� ������������ � ������� ������������ ���� ���������.

	int	nX = 1;
	int nY = -1;
	Swap(...  ,  ...);	//�������� ������� �������� nX � nY �
						//������� ���������� �� nX � nY
	Swap(...  ,  ...);	//� ������ ������� � ������� ������ �� nX � nY
	stop
*/
    int	nX = 1;
	int nY = -1;
	printf("\n%d,%d",nX,nY);
	Swap(&nX,&nY);
	printf("\n%d,%d",nX,nY);
    Swap(nX,nY);
    printf("\n%d,%d",nX,nY);

    stop 
/*
	//������� 2. ��������� �� ������� � �������� ����������.
	//2a.�������� ��� �������� ������� ������ ������������ ��������
	//1. �� ���������� ���������� �������
	//2. � ������������ ���������� ������� (��� ����������� �����������)
	
	//1.��������:
	int ar[N][M] = {������ ���������������};//��������� - ��� � ��� ������ ���� ������ N � M
	int res = Min(ar, ... ����� ����, ����������� �������� ��� �����-������ ������); 
*/
    int res;
	int ar[N][M] = {{11,2,3,4,5},{6,4,50,11,33}};
	//������ 1
	res = Min(ar[0],sizeof(ar)/sizeof(ar[0][0]));//���_�� �� ���
	printf("\nres = %d",res);
    //������ 2            
	res = Min2(ar,sizeof(ar)/sizeof(ar[0])); //����� �����
	printf("\nres = %d",res);

	srand( time( 0 ) );
	int ni =  rand()%10+2;
	int nj =  rand()%10+2;
	int *p = new int [ni*nj];
	printf("\nInMass:");
	for(int i=0;i<(ni*nj);i++)
	 {*(p+i)=rand()%20;// ���������� �������
	  printf("%d ",*(p+i));
	 }
    //
	res = Min3(p,(nj*ni));
    printf("\nres_din1 = %d",res); //1 ������
    //������ 2
	int **pp = new int *[ni]; 
    for(int i = 0;i<ni;i++)
     pp[i]=p+i*nj; // ����� ����
	res =  Min4(pp,ni,nj);
    printf("\nres_din2 = %d",res);
	delete [] p;
	p=0;
	delete [] pp;
	pp=0;//*/
 	stop

	//2b. �������� ������� ��������� ���� ����� - MyStrCmp():
	//������� ������ ��������� ��� ��������� �� ������������
	//������ (�������� �� ������ ������� �����������, ��� �������
	//�� ����� ����� �������������� ���������� �����)
	//������� ������ ���������� ������������� ��������, ����
	//������ ������ ��������������� ������ ������, 0 - ����
	//��� ����� � ������������� ��������, ���� ������ ������
	//������ ������.
	//���������, ��� ��������� ����� ������ �������� ������� ����.
	//{int res;
	//�������� ��� ������ ��� ���������: 
	{
    char cAr1 [] = "aaa";
	char cAr2 [] = "aaa��";
	char *pstr1 = cAr1;
	char *pstr2 = cAr2;
	printf("\nstr1 = %s",cAr1);
	printf("\nstr2 = %s",cAr2);
	//�������� ������� ���������
	 res = MyStrCmp(pstr1,pstr2);//-22 ???
	//res = static_cast<int>(MyStrCmp(pstr1,pstr2));
	//�������� ��������� ��������� � ������� cout:
     printf("\nres_str = %d",res);
	 if(res<0) printf("\n1 string > 2 string");
	 else if(res>0)printf("\n1 string < 2 string");
	      else printf("\n1 string = 2 string");
	} 
	stop


	//������� 3.������ � �������� ����������. �������� ��������� �� ����������
	//������ � �������� ��������� �������.
	//�������� ��� ����������������� ���� ����� �������:
	//1.  ... DayOfYear(...)
	//- ����������� ���� ������ (�����,����� � ��� �������� � �������� ����������)
	//� ���������� ���� ����(������������ ��������)
	//2. ... DayOfMonth(...) - ������� ����������� ���������� ���� ���� � ���� ������
	// (��������� ��� � ���������� ���� ���� � �������� ���������� � ������ ������������
	// ���� ������ � ����� ������ � �����-�� ������� �������� ��� �������� ���������� ���������)
	{
		int Day,month,Year,nDayYear;
		printf("\nEnter Day,Month,Year: ");
		scanf("%d %5d %5d",&Day,&month,&Year);
		bool isLeapYear = (!Year%400) ||(Year%100&&!Year%4);//==1 �����
		if(isLeapYear==1) printf("IsLeapYear"); 
		else printf("NoLeapYear");   
	//-
	//��������� ����������������� ����� ������� � ������� ���������� ���������:
	

	//� �������� ���������� ��� �������� ��������� "���������� - ������������" ���.
	//��� ����� ������������ � ������ ������� � �������� ������ �� ���������� ����������
	//������ ������������ ���� ����������� ������� nDayTab

	int nDayTab[2][12]={
		{31,28,31,30,31,30,31,31,30,31,30,31}, //������������ ���
		{31,29,31,30,31,30,31,31,30,31,30,31}	};	//���������� ���nDayTab
	
	//����� ������� DayOfYear
	 nDayYear=DayOfYear(Day,month,Year,nDayTab);
	 printf("\nnDayYear=%d",nDayYear);

	//�������� ���������� �������� �������� DayOfMonth
	DayOfMonth(Year,nDayYear,Day,month,nDayTab);
    printf("\nDay=%d,month=%d",Day,month);
	}
	stop



	//������� 4. ����������� �������. �������� ����������� ������� ����������
	//����� ������ N ����������� �����.
	{int N,Sum;
	  N=10;
	  Sum=RecSum(N);
	  printf("\nSumRec=%d",Sum);
	}
    stop



	//������� 5�. ������� � ���������� ������ ����������.
	//�������� ������� (���� ��������� VarArgs, �� ������������
	// �������), ������� ��������� ���������� ����� ����������
	// ���� int � ������� �� ������ ����� �������� ���������� �
	// �� ��������.
	// ��������� ����� ������ �������� ������� ��������.
	
	int nN1=5, nN2=11, nN3=4, nN4=7, nN5=-1;
	//VarArgs(nN1,0);	
	//VarArgs(nN1,nN2,0);	
	VarArgs(nN1,nN2,nN3,nN4,nN5,0);	
	stop


	//������� 5�. ������������� ������� 5� � ������� ��������
	// va_start, va_arg, va_end

    Args(nN1,nN2,nN3,nN4,nN5,0);
    stop
	return 0;
}//main

