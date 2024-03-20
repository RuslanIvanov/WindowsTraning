struct BOOK {
	char Name [30];
	char NameBook [30];
	int Year;
	int kat;
	//double cena;
	int cena;
};
struct KART{
	BOOK**pMasAdr;
	int n_record;
	int rez;
};
void PrintMENU(const char **,int);


int LibBookStr(struct BOOK **lb,int n);
//int EnterBook(struct KART* k);
//BOOK**
EnterBook(struct KART* k,int &rn_record_mem);
void PrintfStruct(BOOK **pb, int n);
//void PrintfStruct(struct KART *p, int);
//int SaveBook(struct KART *k, int);
int SaveBook(BOOK **ps, int ns);
int ReadBook();
//BOOK** NewStruct (int );
//void NewStruct(BOOK **&,int);
//void NewStruct(int);
