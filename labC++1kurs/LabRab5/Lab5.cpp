
/*************************************************************
	������������ ������� �5. 
	"������" ��������� ������� ����������� ����������
	��������� �� �������
	���������
*************************************************************/
#include <tchar.h>
#include <iostream>
//#include <cstdio>
#include "other.h"
using namespace std; 

#define	  stop __asm nop

int _tmain()
{
	//���� "������" ��������� ������� ����������� ����������
	//������� 1. � ������� ������� scanf ����������� ��� ������������: A,B,C
	
#if 1
	{int A,B,C;
	 printf("\nEnter A,B,C:");
	 scanf("%5d %5d %5d",&A,&B,&C);
	 printf("\nOut A=%d,B=%d,C=%d",A,B,C);
	
	//������� 2. �������� (�� �������!) ������� �������� y=A*x*x + B*x + C
	//��� ��������� x � ��������� -2 �� +2 � ����� 0.5
	 printf("\n|%4cx%5c|%4cy%5c|\n",' ',' ',' ',' ');
	 for(double x=-2;x<=2;)
	 {double y;
	  y=A*x*x + B*x + C;
	  printf("-----------------------\n");
      printf("|%10g|%10g|\n",x,y);
	  x=x+0.5;
	 }
	}    
    stop
///////////////////////////////////////////////////////////////////
	//���� ��������� �� �������

	//������� 1. ��������� �� �������. "�����������".
	//�������� �������:
	//1)Sum - ��������� ��� �������� double � ���������� �����
	//���� ��������
	//2)Sub- ��������� ��� �������� double � ���������� ��������
	//���� ��������
	//3)Mul - *
	//4)Div - /
	//5)MyPow -  ���������� � �������

	//������������ ������������	��������� �����������:
	//���� ������������ ����� ������������ �������� ������ ������������,
	//�� ����� ������� ��� �������� � ���� ��������
	//� �� �������� ���������. ��������� ��������� ����������� ������
	//��������������� ����� ������� �� ���������.
	//������������� ����������� ������������������ ����� ��������
    //cin.clrscr();
	{double x,y,otv;
	 char znak=0;
	 char ch=0;
	 double (*f)(double,double);
	// while (ch!='n')//||ch!='N')
	 do
	 {//while
     printf("Enter x (+,-,/,*,^) y:");
     scanf("%lf %c %lf",&x,&znak,&y);
	 
	 switch(znak)
	  {//sw
	   case '+':
		   f=&Sum;
       break;
       case '-':
		   f=&Sub;
       break;
	   case '*':
		   f=&Mul;
       break;
	    case '/':
			f=&Div;
       break;
	    case '^':
			f=&MyPow;
       break;
	   default:
		  printf("\nError znak!!!\n"); 
	   continue;
       
	  }//sw'
	 otv=(*f)(x,y);// ����� ������� �� ���������� ����
    printf("\n%4.4lf %c %4.4lf = %g",x,znak,y,otv);
	printf("\nContinue 'y' or 'n'  :");
	while(ch=cin.get())
	 {if(ch=='n'||ch=='N'||ch=='y'||ch=='Y') break;
	 }
	//scanf("%c",&ch);
 	}while (!(ch=='n'||ch=='N'));//while'
	printf("\nExit");
	}
	stop
#endif
	//������� 2. ��������� �� ������� � �������� ���������.
	//���� ��������� ������� ���������� ����� �������� - Sort.
	//������� ��������� ��������� ���������:
	//1) ��������� �� ������ ����������� �������
	//2) ���������� ����������� ���������
	//3) ������ �������� � ������
	//4) ��������� �� ������� ������������ ���������
	//5) ��������� �� ������� ��������� ���������
	{//2
	//2a. �������� ������� ������������ ���� ����� �������� -
	// SwapInt, ������� ��������� ��� void ��������� � 
	//������ �������� �������
    int x,y;    
	printf("\nEnter int x,int y :");
	scanf ("%d %d",&x,&y);
	SwapInt(&x,&y);
    printf("x=%d, y=%d",x,y);
stop
	//�������� ������� ��������� ���� ����� �������� -
	// CmpInt, ������� ��������� ��� void ��������� �
	//���������� int ��������� ���������: 
	//<0 - ������ ������� ������, ��� ������
	//=0 - �����
	//>0 - ������ ������� ������, ��� ������
	int a,b,comp;    
	printf("\nEnter int a,int b :");
	scanf ("%d %d",&a,&b);
    comp=CmpInt(&a,&b);
	printf("\ncomp = %d",comp);
	stop

	int nAr[]={1,6,10,-9,0,99,15,0,88,-88,96,3};
	//������ ��� ����������

	//������ ��������� �������
	printf("\nInMass:\n");
    for(int i=0;i<sizeof(nAr)/sizeof(nAr[0]);i++)
	 {printf("%d ",nAr[i]);
	 }

	//����� ����������
	int nTotal=sizeof(nAr)/sizeof(nAr[0]);			//���������� ��������� � ������� 
	Sort((char*)&nAr[0], nTotal, sizeof(int), SwapInt, CmpInt);
	
	//������ ����������� ����������
	printf("\nOutMassSort:\n");
     for(int i=0;i<sizeof(nAr)/sizeof(nAr[0]);i++)
	 {printf("%d ",nAr[i]);
	 }
	stop


	//������� 2�. �� �������� � 2� �������� ���������������
	//������� - SwapDouble � CmpDouble � �������� ������� Sort
	//��� ���������� ������� ������������ ��������.
	double ndAr[]={1.0,6.6,10.45,-9.43,0.11,99.32,1.5,10.097,8.8,-8.8,96.445,3.0};

    printf("\nInMassD:\n");
    for(int i=0;i<sizeof(nAr)/sizeof(nAr[0]);i++)
	 {printf("%g ",ndAr[i]);
	 }
   nTotal=sizeof(nAr)/sizeof(nAr[0]);
   Sort((char*)&ndAr[0], nTotal, sizeof(double), SwapDouble, CmpDouble);
   printf("\nOutMassSortD:\n");
   for(int i=0;i<sizeof(nAr)/sizeof(nAr[0]);i++)
    {printf("%g ",ndAr[i]);
    }
	stop

	//������� 2�*. �� �������� � 2� �������� ���������������
	//������� - SwapStr � CmpStr � �������� ������� Sort 
	//��� ���������� ������� ���������� �� ������.
	char* arStr[] = {"QQQ", "SDF", "ABC","ssr","d","gh","dfgda"};
	printf("\nInMassStr:\n");
    for(int i=0;i<sizeof(arStr)/sizeof(arStr[0]);i++)
	 {printf("%s ",arStr[i]);
	 }
   nTotal=sizeof(arStr)/sizeof(arStr[0]);
   Sort(reinterpret_cast<char*>(&arStr[0]), nTotal, sizeof(char*), SwapStr, CmpStr);//���� ������� ���
   printf("\nOutMassSortStr:\n");
   for(int i=0;i<sizeof(arStr)/sizeof(arStr[0]);i++)
    {printf("%s ",arStr[i]);
    }

    stop
	}//2'	

	//������� 3. ������� ���������� �� �������.
	//�������� ��������� ������� ����
	//const char* GetString1();
	//const char* GetString2();
	//		...., ������ �� ������� ���������� ��������� �� ���� ������
	//(��������� - ����� ����� �� ������ ����� ���������� �� �������)
	{//3
	 //*** ���� ���������� �� ��������� ��� � ��������� ���� ���� ����� ���***
	const char*(*f[])()={GetString1,GetString2,GetString3};

	//�������� � ������������������ ������ ���������� �� �������
	//GetString1,GetString2...



	//������� ����� �������, ������� �� ������ �������:
	int n;
	const char *str;
	printf("\nEnter num (0-2) string:"); 
	scanf("%d",&n);
	//�������� ������� 
    if(n>=0&&n<=2)
	 { str=(*f[n])();
	   printf("\nOutString %s",str);
	 }
	else printf("\nError number!!!");
	//������������ ���������
    
    stop
}//3'
//////////////////////////////////////////////////////////////////////////////////////

	//����. ��������� �.	
	//������� 1. �������� ��������� BOOK, ����������� �����
	//(�����, ��������, ��� �������, ����, ����������).
	//���������: ������ ���� ����� ���� ���� ���������.
	//���������: ���������� ��������� ������������� ��������
	//� ������������ ����.

    //��  #other.h


	//������� 2. �������� ������� ��������� (����������, ���������, �����������,
	//������������) ���������� (�������) ���� BOOK (��� �������������).
	//���������� - ������� ������ ������� ���������� ��� ������
	//����� ������. ��� ���������������� (��� �� ����������������) ����
	//���������. ���������: �� ���� ������� ����� ���������� ������?
    BOOK book;// ������� 0
	printf("\nsize struct%d",sizeof(BOOK));
	 {BOOK lokbook;//�� ������� 
	  printf("\nsize struct%d",sizeof(BOOK));
	  stop
	 }
	 static BOOK stbook;// ������� 0
	 printf("\nsize struct%d",sizeof(BOOK));
     BOOK *pbook = new BOOK;// �� ������� 
	 printf("\nsize struct%d",sizeof(BOOK));
     delete pbook;
	 pbook=0;
	 //����� ����� ������ ������ �� ���� ���� �������� � ������ ���������� ���� ����� 
stop
	//������� 3. ��������� ���� ��������� ��������.
	//���������: ���� ��� �������� ������ ������������ ������, ����������
   //������������� "������" �� ������ �� ������� �������.
#if 1
     printf("\nNameAutor: ");
     scanf("%14s",&book.Name);
	 fflush(stdin);
	 printf("\nNameBook: ");
     scanf("%14s",&book.NameBook);
	 fflush(stdin);
	 printf("\nYear: ");
     scanf("%d",&book.Year);
	 printf("\nCena: ");
     scanf("%d",&book.cena);
	 printf("\nkat: ");
     scanf("%d",&book.kat);

	 printf("\nOutStr:\n%s\n%s\n%d\n%d\n%d",book.Name,book.NameBook,book.Year,book.cena,book.kat);

    stop
#endif
	//������� 4. �������� �������, ��������� �� ����� ��������� �����.
	//���������: ��� ����������� ���������� ��������� BOOK � �������.
	//��� ������ �� ������� ����������� ������� ����������� ����������
	//printf

     PrintfStruct(&book);
stop
	//������� 5. �������� ������� ��� ������������ ����� ���������.
	//��� ����� ����������� ������� ����������� ���������� scanf
	//���������: ������� �������� � ����� ������� ����������� ��������
	//������������ ���������� ��������, ��������, ��� ������� �� ����� ����
	//�����, ���... (��� ��������� ������������), ��������� �����������
	//������ �������� �� ������������, ���� �� ����� ���� �������������...
    { LIB_BOOK lib_book[2];
     int n_mas_struct=sizeof(lib_book)/sizeof(LIB_BOOK);
     //printf("\nsize struct%d",sizeof(lib_book)/sizeof(LIB_BOOK));//���� �� ������� ���
     LibBookStr(&lib_book[0], n_mas_struct);
	 
	 printf("\nYour struct BOOKs:\n");
	 for(int i=0;i<n_mas_struct;i++)
	  {printf("\nBOOK %d:\nAutor %s\nNameBook %s\nYear %d\nCena %4.2lf\nKat %d",i+1,
	   lib_book[i].Name,lib_book[i].NameBook,lib_book[i].Year,lib_book[i].cena,lib_book[i].kat);
	  }	

    }
    
     stop
	return 0;
}//main

