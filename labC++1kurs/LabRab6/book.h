struct BOOK {
	char Name [30];
	char NameBook [30];
	int Year;
	int kat;
	double cena;
};
struct KART{
	BOOK**pMasAdr;
	int n_record;
	int rez;
};
void PrintMENU(const char **,const int);


int LibBookStr(struct BOOK **lb,int n);
int EnterBook(struct KART* k);
void PrintfStruct(struct BOOK **pb, int n);
//void PrintfStruct(struct KART *k);
//int SaveData();
//int ReadData();