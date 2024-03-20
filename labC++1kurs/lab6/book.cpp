#include "book.h"
#include <cmath>
#include <iostream>
#define	  stop __asm nop
//BOOK book;
//struct BOOK*pbook=new struct BOOK[n_record];

BOOK* EnterBook(struct BOOK *pb,int i)
 {//Ввод в сооответствующий эл масс стр i+1,
  //гди i - текущий
  BOOK *tmp;
  struct BOOK*pb=new struct BOOK[i];
	//i=i+1;
	printf("\nPlease Enter BOOK number %d\n",i+1);
	printf("\nEnter Name Autor: ");
     scanf("%29s",&pb[i].Name);
	 fflush(stdin);
	 printf("\nEnter Name Book: ");
     scanf("%29s",&pb[i].NameBook);
	 fflush(stdin);
	 printf("\nYear: ");
     scanf("%d",&pb[i].Year);
	 while(!(pb[i].Year>=1990&&pb[i].Year<=2007))// Если ввел правильно ти цикл не испон
      {printf("Eror Year, Enter Year(1990-2007):");
	   scanf("%d",&pb[i].Year);
	  }
	 printf("\nCena: ");
     scanf("%lf",&pb[i].cena);
	 while(!(&pb[i].cena>0.0))// Если ввел правильно ти цикл не испон
      {printf("Eror Cena>0, Enter Cena:");
	   scanf("%lf",&pb[i].cena);
	  }
	 printf("\nKategorija : ");
     scanf("%d",&pb[i].kat); 
	 while(!(pb[i].kat>=1&&pb[i].kat<=9))// Если ввел правильно тo цикл не испон
      {printf("Eror Kat, Enter Kat 1-9:");
	   scanf("%d",&pb[i].kat);
	  }
	 return(i);
 }//End Function EnterBook

//void PrintfStruct(const struct BOOK *pb)
//{printf("\nOutStrFunc:\n%s\n%s\n%d\n%d\n%d",pb->Name,pb->NameBook,pb->Year,pb->cena,pb->kat);
	
}