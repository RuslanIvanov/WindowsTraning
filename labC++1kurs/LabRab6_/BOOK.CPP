#include "book.h"
#include <math.h>
#include <tchar.h>
//#include <iostream.h>
//#include <stdio.h>
//#include <conio.h>
#include <iostream>
#include <STDLIB.H>

#define	  stop __asm nop
using namespace std; 

void PrintMENU(const char **pArMenu,int n)
{printf("\n");
 for(int i=0;i<n;i++)
  {printf("\n%s",pArMenu[i]);
  }
}// End Function PrintMenu*/
//int EnterBook(struct KART* k)
BOOK** EnterBook(struct KART* k,int &rn_record_mem)
{static int i;// Pзапоминаем сколько записей сделано
 char ch=0;
 do
 {if(i>k->n_record-1)
	{printf("videlenija");
	 BOOK**tmp=new struct BOOK*[k->n_record+k->rez]; // врем массив указ
	 //if(tmp==0) {printf("\nError mem");exit(0);}
	 //Перезапись массива указ
	 for (int t=0;t<k->n_record;t++)
		{tmp[t]=(k->pMasAdr[t]);// Получаем адрес сируктур
	     printf(" .");//??? 
		}
	 //Удаляем старый массив структур
	 delete [] k->pMasAdr;
	 (k->pMasAdr)=tmp; // New adr
	 /*for (int r =0;r<k->rez; r++ )
	 {
	  k->pMasAdr[k->n_record+r]=new struct BOOK [r+1];// выдление памяти для новой стаукт
	 }*/
	 k->pMasAdr[k->n_record]=new struct BOOK [k->rez];
	 k->n_record=k->n_record+k->rez;
	 printf("i=%d, n_rec=%d",i,k->n_record);
	 delete [] tmp;
	 tmp=0;
	 }
	  
	printf("\nPlease Enter BOOK number %d\n",i+1);
	printf("\nEnter Name Autor: ");
	scanf("%29s",&(*k).pMasAdr[i]->Name);
	printf("%s",k->pMasAdr[i]->Name);
	fflush(stdin);
	printf("\nEnter Name Book: ");
	scanf("%29s",&k->pMasAdr[i]->NameBook);
	printf("%s",k->pMasAdr[i]->NameBook);
	fflush(stdin);
	printf("\nYear: ");
	scanf("%d",&k->pMasAdr[i]->Year);
	while(!(k->pMasAdr[i]->Year>=1990&&k->pMasAdr[i]->Year<=2007))// Если ввел правильно ти цикл не испон
	 {printf("Eror Year, Enter Year(1990-2007):");
		scanf("%d",&k->pMasAdr[i]->Year);
	 }
 printf("\nCena: ");
 fflush(stdin);
 scanf("%d",&k->pMasAdr[i]->cena);
 while(!(k->pMasAdr[i]->cena>0))// Если ввел правильно ти цикл не испон
	{printf("Eror Cena>0, Enter Cena:");
	 scanf("%d",&k->pMasAdr[i]->cena);
	}
 printf("\nKategorija : ");
 fflush(stdin);
 scanf("%d",&k->pMasAdr[i]->kat);
 while(!(k->pMasAdr[i]->kat>=1&&k->pMasAdr[i]->kat<=9))// Если ввел правильно тo цикл не испон
	{printf("Eror Kat, Enter Kat 1-9:");
	 scanf("%d",&k->pMasAdr[i]->kat);
	}

 i+=1;// для сверки для выд пам
 rn_record_mem=i; // скаолько записали

printf("\nContinue enter book 'y' or 'n'  :");
fflush(stdin);
while(1)// perenesti v drugoe mesto
 {  scanf("%c",&ch);
	if(ch=='n'||ch=='N')
	 {//i+=1;          //??
	  //return(i);
	  return(k->pMasAdr);// возвращ адр дин структ
	  }// dlja sle vhogdenija
	else if(ch=='y'||ch=='Y')break;
		 else printf("Error, enter 'y' or 'n':");
	printf("_");
	fflush(stdin);
 }
} while(!(ch=='n'||ch=='N'));

 //return(i);
 return (k->pMasAdr);

 }

int ReadBook()
 {FILE* fin;
  int n_read =0;
  BOOK**p;
  char filename [50] = "c:\\base.txt";
   if((fin=fopen(filename,"r"))==0)
	{printf("\nError file open %s",filename);fclose(fin);return(0);}
	while(!feof(fin))
	{fscanf(fin,"%d",&n_read);
	 //p=NewStruct(n_read);
	 NewStruct(p,n_read);
	 if(!n_read) {printf("\nNo zap in bd");fclose(fin);return(1);}
	 for(int i=0;i<n_read;i++)
	 {
	 fscanf(fin,"%29s",&p[i]->Name);

	 fscanf(fin,"%29s",&p[i]->NameBook);
	 fscanf(fin,"%d",&p[i]->Year);
	 fscanf(fin,"%d",&p[i]->cena);
	 fscanf(fin,"%d",&p[i]->kat);
	 }
	 PrintfStruct(p,n_read);
	}
   fclose(fin) ;
   delete [] p;
   p=0;
   return(1);
 }

//BOOK** NewStruct (int nr) //Ssilku
void NewStruct (BOOK *&rp,int nr)
 { BOOK * p = new struct BOOK [nr];
   BOOK** pMA= new BOOK*[nr];
   for(int i=0;i<nr; i++)
	{pMA[i]= p+i*(nr);
	}
   //delete [] p;???
   //p=0;
   rp=pMA;
   delete [] pMA;// Temp
   pMA=0;
   //return (pMA);
 }

void PrintfStruct(BOOK **pb,int n_mas)
{if(n_mas>0)
 {
 printf("\nYour enter book(s):");
 for(int i=0;i<n_mas;i++)
  {printf("\nBOOK %d:\nAutor %s\nNameBook %s\nYear %d\nCena %d\nKat %d",i+1,
	(*pb[i]).Name,(*pb[i]).NameBook,(*pb[i]).Year,pb[i]->cena,pb[i]->kat);
   if(i%2&&i!=n_mas-1)
   {printf("\nPress any key to continue...");
	getch();}
  }
 }else printf("\nNo BOOKs in KART!!!");
 printf("\nPress any key...");
 cin.getch();
}//*/

int SaveBook(BOOK **ps, int ns)
 {FILE* fin;
  char filename [50] = "c:\\base.txt";
  char * pch[2]={"a","w"};
  int menu=0;
  int ind=0;
  printf("\n[1] INSERT,[2] UPDETE: ");
  fflush(stdin);
  scanf("%d",&menu);
  switch(menu)
  {
   case 1://obnobit    'w'
   ind=0;
   break;
   case 2://dobavit   'a'
   ind=1;
   break;
   default: return(0);
  }
   if((fin=fopen(filename,pch[ind]))==0)
	{printf("\nError file open from SAVE %s",filename);fclose(fin);return(0);}
	while(!feof(fin))
	{fprintf(fin,"%d",&ns);// тут ли
	 for(int i=0;i<ns;i++)
	 {
	  fscanf(fin,"%29s",&ps[i]->Name);
   	  fscanf(fin,"%29s",&ps[i]->NameBook);
	  fscanf(fin,"%d",&ps[i]->Year);
	  fscanf(fin,"%d",&ps[i]->cena);
	  fscanf(fin,"%d",&ps[i]->kat);
	 }
	}
   fclose(fin);
   delete [] ps;
   ps=0;
   return(1);
 }


/*void PrintfStruct(struct KART *p, int n)
{if(n>0)
 {
 printf("\nYour enter book(s):");
 for(int i=0;i<n;i++)
  {printf("\nBOOK %d:\nAutor %s\nNameBook %s\nYear %d\nCena %d\nKat %d",i+1,
   p->pMasAdr[i]->Name,p->pMasAdr[i]->NameBook,p->pMasAdr[i]->Year,p->pMasAdr[i]->cena,p->pMasAdr[i]->kat);
   if(i%2&&i!=n-1)
	{printf("\nPress any key to continue...");
	 getch();
	}
  }
  }else printf("\nNo BOOKs in KART!!!");
 printf("\nPress any key...");
 getch();
}//*/

/*
int EnterBook(struct KART* k)
{static int i;// Pзапоминаем сколько записей сделано
 char ch=0;
 static int pri_m;
 do
 {if(i>k->n_record-1)
	{pri_m=1;
	 printf("videlenija");
	 BOOK * pb_tmp = new struct BOOK [k->n_record+k->rez];
	 //Перезапись
	 for (int t=0;t<k->n_record;t++)
	  pb_tmp[t]=*(k->pMasAdr[t]);// Получаем адрес сируктур для указ
	  //pb_tmp=*(k->pMasAdr);
	  //Удаляем старый массив структур
	 delete [] *k->pMasAdr;
	 //for (t=0;t<k->n_record;t++)
	 // *(k->pMasAdr[t])=pb_tmp[t]; // Переписываем данные
	  *(k->pMasAdr)=pb_tmp;     // New adr
	  delete [] k->pMasAdr;
	 //BOOK **pMA_tmp=new BOOK*[k->n_record+k->rez];
	 k->pMasAdr=new BOOK*[k->n_record+k->rez];
	 for(int j=0;j<(k->n_record+k->rez); j++)
		{k->pMasAdr[j]= *(k->pMasAdr)+j*(k->n_record+k->rez);
		 //k->pMasAdr[j]=pMA_tmp[j];///???
		 //k->pMasAdr[j]=pMA_tmp[j];// Adr perepis
		}
		//k->pMasAdr=pMA_tmp;
		//*(k->pMasAdr[0])=*pMA_tmp[0];
	 k->n_record=k->n_record+k->rez;
	 //delete [] pMA_tmp;
	 //pMA_tmp=0;
	 }
	printf("\nPlease Enter BOOK number %d\n",i+1);
	printf("\nEnter Name Autor: ");
	scanf("%29s",&(*k).pMasAdr[i]->Name);
	printf("%s",k->pMasAdr[i]->Name);
	fflush(stdin);
	printf("\nEnter Name Book: ");
	scanf("%29s",&k->pMasAdr[i]->NameBook);
	printf("%s",k->pMasAdr[i]->NameBook);
	fflush(stdin);
	printf("\nYear: ");
	scanf("%d",&k->pMasAdr[i]->Year);
	while(!(k->pMasAdr[i]->Year>=1990&&k->pMasAdr[i]->Year<=2007))// Если ввел правильно ти цикл не испон
	 {printf("Eror Year, Enter Year(1990-2007):");
		scanf("%d",&k->pMasAdr[i]->Year);
	 }
 printf("\nCena: ");
 fflush(stdin);
 scanf("%d",&k->pMasAdr[i]->cena);
 while(!(k->pMasAdr[i]->cena>0))// Если ввел правильно ти цикл не испон
	{printf("Eror Cena>0, Enter Cena:");
	 scanf("%d",&k->pMasAdr[i]->cena);
	}
 printf("\nKategorija : ");
 fflush(stdin);
 scanf("%d",&k->pMasAdr[i]->kat);
 while(!(k->pMasAdr[i]->kat>=1&&k->pMasAdr[i]->kat<=9))// Если ввел правильно тo цикл не испон
	{printf("Eror Kat, Enter Kat 1-9:");
	 scanf("%d",&k->pMasAdr[i]->kat);
	}

 i+=1;// для сверки для выд пам

	 //lb+i;//&lb->cena
 printf("i=%d, n_rec=%d",i,k->n_record);

printf("\nContinue enter book 'y' or 'n'  :");
fflush(stdin);
while(1)// perenesti v drugoe mesto
 {  scanf("%c",&ch);
	if(ch=='n'||ch=='N')
	 {//i+=1;          //??
	  return(i);}// dlja sle vhogdenija
	else if(ch=='y'||ch=='Y')break;
		 else printf("Error, enter 'y' or 'n':");
	printf("-");
	fflush(stdin);
 }
} while(!(ch=='n'||ch=='N'));

 return(i);

 }*/

