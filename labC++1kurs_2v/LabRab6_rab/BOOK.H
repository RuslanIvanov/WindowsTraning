	#include <tchar.h>
	#include <cstdio>

	struct book
		{
			char Avtor[20]; 
			unsigned int Year; 
			unsigned int Price; 
			char Categorya[10]; 
			char Nazvanie[40];
		};
	
	int PrintBook(book *x);
	int FillBook(book *x);
					
	struct kartoteka 
		{
		int Vs; 
		int Ispol; 
		book** books;
		};

	void SozdKartot (kartoteka *x1);
	void PechKartot (kartoteka *x1);
	void AddBook (kartoteka *x1, book *x2);
	void SochrKartot (kartoteka *x1, FILE *f);
	void ChtenKartot (kartoteka *x1, FILE *f);
	void DeleteKartot (kartoteka *x1);
	void DeleteBook (kartoteka *x1, int Index);
	void SortKartot (kartoteka *x1, int(*sravn)(book*, book*));
	int SortYear (book *b1, book *b2);
	int SortAvtor (book *b1, book *b2);
	int SortNazvanie(book *b1, book *b2);
	int PoGodIzd (kartoteka *x1, int Year);
	bool AvtorLukyanenko(book*x2);