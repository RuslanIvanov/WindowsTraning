	#include <cstdio>
	#include <cstring>
	#include <tchar.h>
	#include <iostream>
	#include "book.h"

	int PrintBook(book *x)
{
	const char* names[]={"Detektiv", "Roman", "Fentasi", "Fiction"};
	printf("Avtor:  %s\n Nazvanie: %s\n Opublikovana: %i\n Price: %i\n Categorya: %s\n",(*x).Avtor,(*x).Nazvanie,(*x).Year,(*x).Price,(*x).Categorya);
	return 0;
}

int FillBook(book* x)
{
	printf("Vvedite avtora:");
	scanf("%s20",&((*x).Avtor));
	fflush(stdin);
	printf("\n");
	
	printf("Vvedite nazvanie:");
	scanf("%s40",&((*x).Nazvanie));
	fflush(stdin);
	printf("\n");
	
	printf("Vvedite god izdaniya:");
	unsigned int year;
	bool flagYear=false;
	while(!flagYear)
	{
		scanf("%i",&year);
		if((year<2008)&&(year>1000)) 
		{
			flagYear=true;
			(*x).Year=year;
			printf("\n");
		}
		else printf("Nepravilno vvedena data!"); printf("\n");
	}
	

	printf("Vvedite cenu:");
	int price=-1;
	bool FlagPrice=false;
	while(!FlagPrice)
	{
		scanf("%i",&price);
		if(price>0) 
		{
			FlagPrice=true; 
			(*x).Price=price; 
			printf("\n");
		}
		else printf("Nepravilno vvedena cena"); printf("\n");
	}
	printf("Vyberite kategoriyu knigi \n 1 - Detektiv,\n 2 - Roman,\n 3 - Fentasi,\n 4 - Fiction:");
	int categ;
	scanf("%i",&categ);
	switch (categ)
	{
		case 1: strcpy(x-> /*(*x).*/Categorya,"Detektiv"); break;
		case 2: strcpy((*x).Categorya,"Roman");   break;
		case 3: strcpy((*x).Categorya,"Fentasi");  break;
		case 4: strcpy((*x).Categorya,"Fiction");  break;
	}
	return 0;
}




//картотека 

void SozdKartot (kartoteka *x1)
{
	(*x1).Ispol=0;
	(*x1).Vs=5;
	(*x1).books=new book*[(*x1).Vs];
}

void PechKartot(kartoteka *x1)
{
	for(int i=0;i<(*x1).Ispol;i++)
	{			
		PrintBook((*x1).books[i]);
	}
}

void AddBook (kartoteka *x1, book *x2)
{
	if ( (*x1).Ispol>=(*x1).Vs)
	{	
		(*x1).Vs+= 5;
		book **newb=new book*[(*x1).Vs];
		for (int i=0;i<(*x1).Ispol;i++)
			newb[i]=(*x1).books[i];
		delete[](*x1).books;
		(*x1).books=newb;
	}
	(*x1).books[(*x1).Ispol]=x2;
	(*x1).Ispol++;
}

void SochrKartot (kartoteka *x1, FILE *f)
{
	fprintf(f, "%i \n", (*x1).Ispol);
	for(int i=0;i<(*x1).Ispol; i++)
	{
		fprintf(f, "\n Avtor - %20s\n Nazvanie - %40s\n Year - %i\n Price - %i\n Categorya - %i",
				(*x1).books[i]->Avtor, (*x1).books[i]->Nazvanie, (*x1).books[i]->Year, 
				(*x1).books[i]->Price, (*x1).books[i]->Categorya);
	}
}

void ChtenKartot (kartoteka *x1, FILE *f)
{
	fscanf(f,"%i \n", &(*x1).Vs);
	delete[] (*x1).books;
	(*x1).Ispol=0;
	(*x1).books=new book*[(*x1).Vs];
	for(int i=0;i<(*x1).Vs; i++)
	{
		book *x2=new book;
		fscanf(f, "\n Avtor - %20s\n Nazvanie - %40s\n Year - %i\n Price - %i\n Categorya - %i",
			&(*x2).Avtor, &(*x2).Nazvanie, &(*x2).Year, &(*x2).Price, &(*x2).Categorya);
		(*x1).books[i] = x2;
		(*x1).Ispol++;
	}
}

void DeleteKartot (kartoteka *x1)
{
	(*x1).Ispol=0;
	(*x1).Vs=0;
	delete[] (*x1).books;
}

bool AvtorLukyanenko(book*x2)
{
	return (strcmp((*x2).Avtor, "Lukyanenko")==0);
}

void DeleteBook(kartoteka *x1, int Index)
{
	if(Index<(*x1).Ispol-1)
	{
		for(int i=Index+1;i<(*x1).Ispol;i++)
		{
			(*x1).books[i-1]=(*x1).books[i];
		}
		(*x1).Ispol--;
	}
}

void SortKartot(kartoteka *x1,int(*sravn)(book*, book*))
{
	int i;
	for(i=1;i<(*x1).Ispol;i++)
		for(int j=(*x1).Ispol-1;j>=i;j--)
		{
			if(sravn((*x1).books[j-1], (*x1).books[j])>0)
			{
				book *vr1=(*x1).books[j];
				(*x1).books[j]=(*x1).books[j-1];
				(*x1).books[j-1]=vr1;
			}
		}
}

int SortYear(book *b1, book *b2)
{
	if((*b1).Year>(*b2).Year)
		return 1;
	if((*b1).Year<(*b2).Year)
		return -1;
	return 0;
}

int SortAvtor(book *b1, book *b2)
{
	return strcmp((*b1).Avtor, (*b2).Avtor);
}

int SortNazvanie(book *b1, book *b2)
{
	return strcmp((*b1).Nazvanie, (*b2).Nazvanie);
}

int PoGodIzd(kartoteka *x1, int YEAR)
{
	for(int i=0;i<(*x1).Ispol;i++)
		if((*x1).books[i]->Year==YEAR)
			return i;
	return -1;
}













	