#include <tchar.h>
#include <iostream>
#include <cstdio>
#include "din_str.h"
using namespace std; 
#define	  stop __asm nop	
void LibBookStr(struct BOOK *lb,int);
void PrintfStruct(const struct BOOK *pb,int);
void main()
{int n_mas_struct=0;
 char ch=0; 
 char ch_sw=0;
 int i=0;
 struct BOOK * pbook =new struct BOOK [1];
 while(ch!='9')
 {ch=cin.get();
   switch(ch)
   {
    case'1':
    //n_mas_struct=1;
    do{
	n_mas_struct+=1;// Запись доб будем
	printf("\nEnter n_mas = %d mas",n_mas_struct);
	//scanf("%10d",&n_mas_struct);
	struct BOOK * ptmp =new struct BOOK [n_mas_struct];
    
	for(int j = 0;j<n_mas_struct-1;j++)
     ptmp[j]=pbook[j];// Перекинули в нов область, хвост свободен
    LibBookStr(ptmp,n_mas_struct);
    pbook=ptmp;//Перенапр
	delete [] ptmp;
	ptmp=0;
	printf("\nContinue 'y' or 'n'  :");
	while(ch_sw=cin.get())
	 {if(ch_sw=='n'||ch_sw=='N'||ch_sw=='y'||ch_sw=='Y') break;
	 }
	//n_mas_struct+=1;// Запись доб будем
 	}while (!(ch_sw=='n'||ch_sw=='N'));//while'
	break;
	case'2':
	printf("\nYour struct BOOKs:\n");
	PrintfStruct(pbook,n_mas_struct);
	break;
	case '9':
	printf("Exit");
	break;
   }

 }

stop
}

void LibBookStr(struct BOOK *lb,int i)
 {//int i=0;
	//do
	{printf("\nPlease Enter BOOK number %d\n",i);
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
   //while(i<n);

 }
void PrintfStruct(const struct BOOK *pb,int n_mas)
{for(int i=0;i<n_mas;i++)
  {printf("\nBOOK %d:\nAutor %s\nNameBook %s\nYear %d\nCena %4.2lf\nKat %d",i+1,
   (pb+i)->Name,(pb+i)->NameBook,(pb+i)->Year,(pb+i)->cena,(pb+i)->kat);
  }	
}