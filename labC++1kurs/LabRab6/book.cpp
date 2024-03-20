#include "book.h"
#include <cmath>
#include <tchar.h>
#include <iostream>
#include <stdio.h>
#include <conio.h>

#define	  stop __asm nop
using namespace std; 

void PrintMENU(const char **pArMenu,int n)
{printf("\n");
 for(int i=0;i<n;i++)
  {
   printf("\n%s",pArMenu[i]);
  }
}// End Function PrintMenu*/

int LibBookStr(struct BOOK **lb,int n)
 {int i=0;
  char ch=0;
  	do
	{
	 printf("\nPlease Enter BOOK number %d\n",i+1);
	 printf("\nEnter Name Autor: ");
     scanf("%29s",&lb[i]->Name);
	 fflush(stdin);
	 printf("\nEnter Name Book: ");
     scanf("%29s",&lb[i]->NameBook);
	 fflush(stdin);
	 printf("\nYear: ");
     scanf("%d",&lb[i]->Year);
	 while(!(lb[i]->Year>=1990&&lb[i]->Year<=2007))// Если ввел правильно ти цикл не испон
      {printf("Eror Year, Enter Year(1990-2007):");
	   scanf("%d",&lb[i]->Year);
	  }
	 printf("\nCena: ");
     scanf("%lf",&lb[i]->cena);
	 while(!(lb[i]->cena>0.0))// Если ввел правильно ти цикл не испон
      {printf("Eror Cena>0, Enter Cena:");
	   scanf("%lf",&lb[i]->cena);
	  }
	 printf("\nKategorija : ");
     scanf("%d",&lb[i]->kat); 
	 while(!(lb[i]->kat>=1&&lb[i]->kat<=9))// Если ввел правильно тo цикл не испон
      {printf("Eror Kat, Enter Kat 1-9:");
	   scanf("%d",&lb[i]->kat);
	  }
	printf("\nContinue enter book 'y' or 'n'  :");
	fflush(stdin);
	while(true)
	{ scanf("%c",&ch);
	 if(ch=='n'||ch=='N') return(i);
	 else if(ch=='y'||ch=='Y')printf("\nError, enter  'y' or 'n' :");
	}
	 i++;// для сверки для выд пам 
	 //lb+i;//&lb->cena
	 if(i>n){
	  BOOK * tmp = new struct BOOK [n+n];

	 }
    } while(!(ch=='n'||ch=='N'));

 return(i);
   //while(i<n);
  
 }

void PrintfStruct(struct BOOK **pb,int n_mas)
{printf("\nYour enter book(s):");
 for(int i=0;i<n_mas;i++)
  {printf("\nBOOK %d:\nAutor %s\nNameBook %s\nYear %d\nCena %4.2lf\nKat %d",i+1,
    pb[i]->Name,pb[i]->NameBook,pb[i]->Year,pb[i]->cena,pb[i]->kat);
  }	
 printf("\nPress any key...");
 getch();
}
/*void PrintfStruct(struct KART *k)
{printf("\nYour enter book(s):");
 for(int i=0;i<k->n_record;i++)
  {printf("\nBOOK %d:\nAutor %s\nNameBook %s\nYear %d\nCena %4.2lf\nKat %d",i+1,
    k->pMasAdr[i]->Name,k->pMasAdr[i]->NameBook,k->pMasAdr[i]->Year,k->pMasAdr[i]->cena,k->pMasAdr[i]->kat);
  }	
 printf("\nPress any key...");
 getch();
}*/

int EnterBook(struct KART* k)
{static int i;// Pзапоминаем сколько записей сделано
 char ch=0;
 do
 {printf("\nPlease Enter BOOK number %d\n",i+1);
  printf("\nEnter Name Autor: ");
  scanf("%29s",&k->pMasAdr[i]->Name);
  fflush(stdin);
  printf("\nEnter Name Book: ");
  scanf("%29s",&k->pMasAdr[i]->NameBook);
  fflush(stdin);
  printf("\nYear: ");
  scanf("%d",&k->pMasAdr[i]->Year);
  while(!(k->pMasAdr[i]->Year>=1990&&k->pMasAdr[i]->Year<=2007))// Если ввел правильно ти цикл не испон
   {printf("Eror Year, Enter Year(1990-2007):");
    scanf("%d",&k->pMasAdr[i]->Year);
   }
 printf("\nCena: ");
 scanf("%lf",&k->pMasAdr[i]->cena);
 while(!(k->pMasAdr[i]->cena>0.0))// Если ввел правильно ти цикл не испон
  {printf("Eror Cena>0, Enter Cena:");
   scanf("%lf",&k->pMasAdr[i]->cena);
  }
 printf("\nKategorija : ");
 scanf("%d",&k->pMasAdr[i]->kat); 
 while(!(k->pMasAdr[i]->kat>=1&&k->pMasAdr[i]->kat<=9))// Если ввел правильно тo цикл не испон
  {printf("Eror Kat, Enter Kat 1-9:");
   scanf("%d",&k->pMasAdr[i]->kat);
  }
printf("\nContinue enter book 'y' or 'n'  :");
fflush(stdin);
while(true)
 {scanf("%c",&ch);
  if(ch=='n'||ch=='N') return(i);
  else if(ch=='y'||ch=='Y')break;
       else printf("Error, enter 'y' or 'n':");
  fflush(stdin);
 }
 i++;// для сверки для выд пам 
 
	 //lb+i;//&lb->cena
 if(i>k->n_record)
  {BOOK * pb_tmp = new struct BOOK [k->n_record+k->rez];
   
   //Перезапись
   for (int i=0;i<k->n_record;i++)
    pb_tmp[i]=k->pMasAdr[i];
   // Удаляем старый массив структур
   delete [] k->pMasAdr;
   //
   BOOK **pMA_tmp = new BOOK*[k->n_record+k->rez];
   for(int i=0;i<(k->n_record+k->rez); i++)
    {pMA_tmp[i]= pb_tmp+i*(k->n_record+k->rez);
     k->pMasAdr[i]=pMA_tmp[i];///???
	} 
   k->n_record+=k->rez;
   delete [] pMA_tmp;
  pMA_tmp=0;
   }
} while(!(ch=='n'||ch=='N'));

 return(i);
  
 }