/*************************************************************
	Практическое занятие №5. Структуры
//динамический массив структур
//поиск
//сортировка
//сохранение в файле
//чтение из файла
*************************************************************/
#include <tchar.h>
#define	  stop __asm nop
/*book y1;
*/
#include "book.h"

#include <iostream>
#include <cstdio>
using namespace std;
//#define	  stop 
//{ 
 //   __asm nop 
//}
//while(false)
const char* filename="Book.txt";
void main()
{
	//Используйте структуру BOOK, созданную в предыдущей работе.
	//Для этого достаточно переписать и подключить к проекту файлы
	//book.h и book.cpp

	//Задание 1. Создаем «картотеку».
	//«Картотека» - это массив структур => нужно такой массив создать.
	//Замечание: размер массива придется увеличиватьпо мере добавления книг =>
	//кКаким должен быть такой массив???
	
	 kartoteka kart;
	/*{
		int Vs; int Ispol; book** books;
	}; */
	SozdKartot (&kart);
	stop
	// структура расположена в "book.h"

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
	
	while(true==1)
    {
		printf("Vozmojnye deistviya:\n");
        printf("0 - Vyhod iz menu\n");
		printf("1 - Sortirovka i pechat' kartoteki\n");
        printf("2 - Vvesty dannye o novoyi knige\n");
        printf("3 - Udalit' knigu\n");
        printf("4 - Sochranit' v fail\n");
        printf("5 - Otkryt' i schitat' iz faila\n");
	int menu; //int n;
       // do
        {
            printf("Vash vybor punkta menu: ");
			scanf("%i",&menu);
			if(menu==0) break;
			switch(menu)
			{
				
				case 0: // выход из меню
				{
					break;//return;
				}		
				case 1: 
				{
					int (*am[])(book*, book*) = {SortAvtor, SortYear, SortNazvanie};
					int sort;
					printf("Variant sortirovki \n 0 - Avtor,\n 1 - Year,\n 2 - Nazvanie):");
					scanf("%i",&sort);//std::cin>>sort;
				////////switch (sort)
				////////{
				////////	case 1: strcpy(x-> /*(*x).*/Categorya,"Detektiv"); break;
				////////	case 2: strcpy((*x).Categorya,"Roman");   break;
				////////	case 3: strcpy((*x).Categorya,"Fentasi");  break;
				////////	case 4: strcpy((*x).Categorya,"Fiction");  break;
				////////}
					if(sort>=0&&sort<=2) 
					SortKartot(&kart,am[sort]);
					PechKartot(&kart);
					break;
				}
				case 2: 
				{
					book* Booknew=new book;
					FillBook(Booknew);
					AddBook(&kart,Booknew);
					//delete Booknew;
				}
				break;
				case 3:
				{
					unsigned int year;
					printf("Vvedite god izdaniya:");
					scanf("%i",&year);
					int index=PoGodIzd(&kart,year);
					if(index!=-1)
						DeleteBook(&kart,index);
				}
				break;
				case 4:
				{
					FILE* am1=fopen("Book.txt","w+");
					if(am1)
					{
						SochrKartot(&kart,am1);
						fclose (am1);
					}
				}
				break;
				case 5:
				{
					FILE* am1=fopen("Book.txt","r");
					if(am1)
					{
						ChtenKartot(&kart, am1);// считать в файл
						fclose(am1);
					}
				}
				break;
			}
		
				
	
		}//while(false);	
	/////////*default:
				/////*	{
				////		printf("Nekorrektno vvedeny dannye.\n", menu);
				////		continue;
				////	}*/
		//DeleteKartot(&kart);
	} //?

	
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