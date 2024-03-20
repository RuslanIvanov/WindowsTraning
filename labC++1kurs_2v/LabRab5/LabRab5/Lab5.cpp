
/*************************************************************
	Практическое занятие №5. 
	"Старые" потоковые функции стандартной библиотеки
	Указатели на функции
	Структуры
*************************************************************/
#include <tchar.h>
#include <iostream>
//#include <cstdio>
#include "other.h"
using namespace std; 

#define	  stop __asm nop

int _tmain()
{
	//Тема "Старые" потоковые функции стандартной библиотеки
	//Задание 1. С помощью функции scanf сформирйуте три коэффициента: A,B,C
	
#if 1
	{int A,B,C;
	 printf("\nEnter A,B,C:");
	 scanf("%5d %5d %5d",&A,&B,&C);
	 printf("\nOut A=%d,B=%d,C=%d",A,B,C);
	
	//Задание 2. Выведите (не красиво!) таблицу значений y=A*x*x + B*x + C
	//при изменении x в диапазоне -2 до +2 с шагом 0.5
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
	//Тема Указатели на функции

	//Задание 1. Указатель на функцию. "Калькулятор".
	//Напишите функции:
	//1)Sum - принимает два значения double и возвращает сумму
	//этих значений
	//2)Sub- принимает два значения double и возвращает разность
	//этих значений
	//3)Mul - *
	//4)Div - /
	//5)MyPow -  возведение в степень

	//Предоставьте пользователю	следующую возможность:
	//пока пользователь хочет пользоваться услугами Вашего калькулятора,
	//он может вводить два значения и знак операции
	//а Вы выводите результат. Результат получаете посредством вызова
	//соответствующей Вашей функции по указателю.
	//Предусмотрите возможность непредусмотренного знака операции
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
	 otv=(*f)(x,y);// Вызов функции по выбранному указ
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
	//Задание 2. Указатель на функцию в качестве аргумента.
	//Дана заготовка функции сортировки любых объектов - Sort.
	//Функция принимает следующие параметры:
	//1) указатель на первый сортируемый элемент
	//2) количество сортируемых элементов
	//3) размер элемента в байтах
	//4) указатель на функцию перестановки элементов
	//5) указатель на функцию сравнения элементов
	{//2
	//2a. Напишите функцию перестановки двух целых значений -
	// SwapInt, которая принимает два void указателя и 
	//меняет значения местами
    int x,y;    
	printf("\nEnter int x,int y :");
	scanf ("%d %d",&x,&y);
	SwapInt(&x,&y);
    printf("x=%d, y=%d",x,y);
stop
	//Напишите функцию сравнения двух целых значений -
	// CmpInt, которая принимает два void указателя и
	//возвращает int результат сравнения: 
	//<0 - первый элемент меньше, чем второй
	//=0 - равны
	//>0 - первый элемент больше, чем второй
	int a,b,comp;    
	printf("\nEnter int a,int b :");
	scanf ("%d %d",&a,&b);
    comp=CmpInt(&a,&b);
	printf("\ncomp = %d",comp);
	stop

	int nAr[]={1,6,10,-9,0,99,15,0,88,-88,96,3};
	//массив для сортировки

	//Печать исходного массива
	printf("\nInMass:\n");
    for(int i=0;i<sizeof(nAr)/sizeof(nAr[0]);i++)
	 {printf("%d ",nAr[i]);
	 }

	//Вызов сортировки
	int nTotal=sizeof(nAr)/sizeof(nAr[0]);			//количество элементов в массиве 
	Sort((char*)&nAr[0], nTotal, sizeof(int), SwapInt, CmpInt);
	
	//Печать результатов сортировки
	printf("\nOutMassSort:\n");
     for(int i=0;i<sizeof(nAr)/sizeof(nAr[0]);i++)
	 {printf("%d ",nAr[i]);
	 }
	stop


	//Задание 2б. По аналогии с 2а создайте вспомогательные
	//функции - SwapDouble и CmpDouble и вызовите функцию Sort
	//для сортировки массива вещественных значений.
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

	//Задание 2в*. По аналогии с 2а создайте вспомогательные
	//функции - SwapStr и CmpStr и вызовите функцию Sort 
	//для сортировки массива указателей на строки.
	char* arStr[] = {"QQQ", "SDF", "ABC","ssr","d","gh","dfgda"};
	printf("\nInMassStr:\n");
    for(int i=0;i<sizeof(arStr)/sizeof(arStr[0]);i++)
	 {printf("%s ",arStr[i]);
	 }
   nTotal=sizeof(arStr)/sizeof(arStr[0]);
   Sort(reinterpret_cast<char*>(&arStr[0]), nTotal, sizeof(char*), SwapStr, CmpStr);//Надо перекид адр
   printf("\nOutMassSortStr:\n");
   for(int i=0;i<sizeof(arStr)/sizeof(arStr[0]);i++)
    {printf("%s ",arStr[i]);
    }

    stop
	}//2'	

	//Задание 3. Массивы указателей на функцию.
	//Напишите несколько функций вида
	//const char* GetString1();
	//const char* GetString2();
	//		...., каждая из функций возвращает указатель на свою строку
	//(подумайте - какой адрес Вы имеете право возвращать из функции)
	{//3
	 //*** Надо возвращать не локальный адр с продолжит хран пока прогр раб***
	const char*(*f[])()={GetString1,GetString2,GetString3};

	//Объявите и проинициализируйте массив указателей на функции
	//GetString1,GetString2...



	//Введите номер функции, которую Вы хотите вызвать:
	int n;
	const char *str;
	printf("\nEnter num (0-2) string:"); 
	scanf("%d",&n);
	//Вызовите функцию 
    if(n>=0&&n<=2)
	 { str=(*f[n])();
	   printf("\nOutString %s",str);
	 }
	else printf("\nError number!!!");
	//Распечатайте результат
    
    stop
}//3'
//////////////////////////////////////////////////////////////////////////////////////

	//Тема. Структуры С.	
	//Задание 1. Объявите структуру BOOK, описывающую книгу
	//(автор, заглавие, год издания, цена, категория…).
	//Подумайте: какого типа могут быть поля структуры.
	//Подсказка: объявление структуры рекомендуется выносить
	//в заголовочный файл.

    //см  #other.h


	//Задание 2. Создайте разными способами (глобальный, локальный, статический,
	//динамический) экземпляры (объекты) типа BOOK (без инициализации).
	//Определите - сколько памяти отводит компилятор под каждый
	//такой объект. Как инициализируются (или не инициализируются) поля
	//структуры. Подумайте: от чего зависит объем выделяемой памяти?
    BOOK book;// инициал 0
	printf("\nsize struct%d",sizeof(BOOK));
	 {BOOK lokbook;//не инициал 
	  printf("\nsize struct%d",sizeof(BOOK));
	  stop
	 }
	 static BOOK stbook;// инициал 0
	 printf("\nsize struct%d",sizeof(BOOK));
     BOOK *pbook = new BOOK;// не инициал 
	 printf("\nsize struct%d",sizeof(BOOK));
     delete pbook;
	 pbook=0;
	 //Объем выдел памяти завист от типа поля структры и пордка объявления этих типов 
stop
	//Задание 3. Заполните поля созданных объектов.
	//Замечание: если для хранения строки используется массив, необходимо
   //предусмотреть "защиту" от выхода за границы массива.
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
	//Задание 4. Напишите функцию, выводящую на экран реквизиты книги.
	//Подумайте: как эффективнее передавать экземпляр BOOK в функцию.
	//Для вывода на консоль используйте функцию стандартной библиотеки
	//printf

     PrintfStruct(&book);
stop
	//Задание 5. Напишите функцию для формирования полей структуры.
	//Для ввода используйте функцию стандартной библиотеки scanf
	//Замечание: неплохо заложить в такую функцию возможность проверки
	//корректности введенного значения, например, год издания не может быть
	//меьше, чем... (год появления письменности), категорию ползователь
	//должен выбирать из существующих, цена не может быть отрицательной...
    { LIB_BOOK lib_book[2];
     int n_mas_struct=sizeof(lib_book)/sizeof(LIB_BOOK);
     //printf("\nsize struct%d",sizeof(lib_book)/sizeof(LIB_BOOK));//Колл эл массива стр
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

