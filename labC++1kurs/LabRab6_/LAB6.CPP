/*************************************************************
	Практическое занятие №5. Структуры
//динамический массив структур
//поиск
//сортировка
//сохранение в файле
//чтение из файла
*************************************************************/
//#include <tchar.h>
#include <iostream.h>
#include <stdio.h>
#include <conio.h>
#include "book.h"
//using namespace std; 
#define	  stop __asm nop	

void main()
{
	//Используйте структуру BOOK, созданную в предыдущей работе.
	//Для этого достаточно переписать и подключить к проекту файлы
	//book.h и book.cpp

	//Задание 1. Создаем «картотеку».
	//«Картотека» - это массив структур => нужно такой массив создать.
	//Замечание: размер массива придется увеличиватьпо мере добавления книг =>
	//кКаким должен быть такой массив???
   const char *ArMenu[] =  {"MENU:",
                       "[1]Print kartoteka",
					   "[2]Enter new book",
					   "[3]Delete book(s)",
					   "[4]Save kartoteka to file",
					   "[5]Read kartoteka from file",
					   "[9]Exit",
					   "Please enter number: "
                      };
    const int Nstr = sizeof(ArMenu)/sizeof(const char*);
	char ch=0;
	char ch_sw=0;
	KART kart;
	kart.n_record=2;
	kart.rez=1;//2;
	int n_record_mem=0;
	//Созд динам структуру BOOK
	BOOK * pb = new struct BOOK [kart.n_record];
	kart.pMasAdr = new BOOK*[kart.n_record];
	for(int i=0;i<kart.n_record; i++)
	 {
		kart.pMasAdr[i]= pb+i*(kart.n_record);
	 }
	printf("\n***Kartoteka knig***\n");
	//PrintMENU(&ArMenu[0],Nstr);
	while(ch!='9')
	{//while
	 PrintMENU(ArMenu,Nstr);
	 fflush(stdin);
	 scanf("%c",&ch);
	 switch(ch)
	 {//sw
	  case'1':
	   printf("\nPrint BOOKs n_r%d:",n_record_mem);
	   PrintfStruct(kart.pMasAdr, n_record_mem);
	   //PrintfStruct(&kart,n_record_mem);
	  break;
	  case'2'://созд дин стр с пом ф_ии
		 printf("\nEnter new book:");
		 //n_record_mem=LibBookStr(kart.pMasAdr,kart.n_record+kart.rez);
		 kart.pMasAdr=EnterBook(&kart,n_record_mem);

	  break;
	  case'3':
		  printf("\nDELETE...");

	  break;
	  case'4':
		  printf("\nSAVE...");
		  if(!SaveBook(&kart,n_record_mem))
		   printf("\n No save...");
	  break;
	  case'5':
		  printf("\nREAD...");
		  if(!ReadBook())
		   printf("\n No book(s)...");

		  //n_record=0,1,2,1...
		  //чтение с пом ф_ии кот исп дин стр
	  break;
	  case'9':
	  printf("\n***Exit***");
	  break;
	  default:printf("\nError number"); break;
	 }//sw,

   }//while'
	 delete [] pb;
	 pb=0;
	 delete [] kart.pMasAdr;
	 kart.pMasAdr=0;
	stop
	//Пользователь должен иметь возможность по своему желанию выполнять
	//разные действия с картотекой => нужно такую возможность ему
	//предоставить: это может выглядеть как вывод "меню" (перечень
	//возможных действий и соответствующих реакций пользователя), например:
	//Распечатать содержимое картотеки (1)
	//Ввести новую книгу (2)
	//Удалить существующую(ие) (3)
	//Записать текущее содержимое картотеки в файл (4)
	//Считать из файла содержимое в картотеку (5)
	//...
	//Выход из программы (...)


	//Реализуйте посредством функций разные возможности работы с картотекой




	//Подсказка1: для файлового ввода/вывода используйте функции fprintf и fscanf
	//(заголовочный файл <cstdio>



	// Подсказка2: удобно в качестве первого данного в файле хранить количество
	// книг в картотеке
	//Если файл существует и его удалось открыть
	//if()
	//{
	//Чтение данных из файла
	//а) считали количество элементов
	//б) создали массив требуемой размерности
	//в) считали данные из файла в массив
	//}




	//****************************************************************
	//Задание 2. Предоставьте пользователю возможность выводить перечень книг
	//в определенном порядке => напишите функцию (функции) сортировки массива
	//по любому из полей структуры.
	//Замечание: признак - "по какому полю сортируем" можно ввести с помощью
	//перечисления.



}