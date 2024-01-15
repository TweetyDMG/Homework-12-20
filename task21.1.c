#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h> //для расчёта формул
#include <conio.h> //для getch()
#include <windows.h> //для system("cls")
#include <time.h>
#include <stddef.h>

#define SIZE 100
	typedef struct
	{
		double fenceLength;
		double stepHeight;  
		double stepWidth;
		double stepAmount;
	} lader;
	
	lader empty_lader = {0.0, 0.0, 0.0, 0};
	lader write[SIZE];

void fillCornicesArray();
void print_array(int size_arr);
void print_lader(int search);
lader search_step(double stepAmount);


int main(void)
{
	setlocale(LC_CTYPE, "RUS");
	
	char selection, name_file;
	int size_arr, search;
	double stepAmount;
	
	srand(time(NULL));

	do{
		
	
	printf("\nПрограмма из лабораторной №21\n\n");
	printf("1. Заполнить массив записей рандомными значениями\n");
	printf("2. Вывести поля массива\n");
	printf("3. Найти запись по номеру\n");
	printf("4. Найти элемент по имени поля\n");
	printf("5. Отсортировать массив\n\n");

	selection = getch();
	system("cls");

	switch(selection)
	{
	case '1':
		printf("\nМассив заполняется рандомными числами...\n");
		fillCornicesArray();
		printf("Массив успешно заполнился рандомными значениями.\n");
		getch();
		system("cls");
		break;
	
	case '2':
		printf("\nВведите количество записей для печати(не более 1000): ");
		scanf("%d", &size_arr);
		print_array (size_arr);
		break;
	
	case '3':
		printf("Введите номер записи, которую необходимо найти: ");
		scanf("%d", &search);
		print_lader(search);
		break;

	case '4':
		printf("Введите количество ступенек и программа найдёт элементы по количеству ступенек: ");
		scanf("%lf", &stepAmount);
		lader search_lader = search_step(stepAmount);
		if(search_lader.stepAmount == 0.0)
		{
			printf("Элемент не найден\n");
			getch();
			system("cls");
		}
		else
		{
		printf("Найден элемент:\n");
		printf("Высота ограждения: %0.2lf м.\n", search_lader.fenceLength);
        printf("Высота ступеньки: %0.2lf м.\n", search_lader.stepHeight);
        printf("Ширина ступеньки: %0.2lf\n", search_lader.stepWidth);
        printf("Количество ступенек: %0.2lf\n\n", search_lader.stepAmount);
		getch();
		}
		system("cls");
		break;
		
	case '5':
		qsort();




	case '0':
		break;
	
	default:
		printf("Неверная цифра.\n");
		
	}	
	} while(selection != '0');
}



 void fillCornicesArray() {

    srand(time(NULL));

    for (int i = 0; i < SIZE; i++) {

        write[i].fenceLength = rand() % 10 + 1;
        write[i].stepHeight = rand() % 10 + 1;
        write[i].stepWidth = rand() % 10 + 1;
        write[i].stepAmount = rand() % 10 + 1;
    }
}

/*void fill_array(cornice_t *, int size)
{
	
}*/

void print_array(int size_arr)
{
	int i = 0;
	for(; i <= size_arr; i++)
	{
		printf("Элемент %d\n\n", i);
		printf("Высота ограждения: %0.2lf м.\n", write[i].fenceLength);
        printf("Высота ступеньки: %0.2lf м.\n", write[i].stepHeight);
        printf("Ширина ступеньки: %0.2lf\n", write[i].stepWidth);
        printf("Количество ступенек: %0.2lf\n\n", write[i].stepAmount);
		printf("----------------\n");
	}
	getch();
	system("cls");
}

void print_lader(int search)
{
	printf("Найден элемент %d\n", search);
	printf("| %.2lf || %.2lf || %.2lf || %d |\n", write[search].fenceLength, write[search].stepHeight, write[search].stepWidth, write[search].stepAmount);
	getch();
	system("cls");
}

lader search_step(double stepAmount) {

    for (int i = 0; i < SIZE; i++) {
        if (write[i].stepAmount == stepAmount)
        	return write[i];
        }
    return empty_lader;

}

int compare(const void *a, const void *b) {

    const lader *corniceA = (const lader *)a;

    const lader *corniceB = (const lader *)b;

    
    int areaA = corniceA->length * corniceA->ceilingWidth;

    int areaB = corniceB->length * corniceB->ceilingWidth;

    
    if (areaA < areaB) {

        return -1;

    } else if (areaA > areaB) {

        return 1;

    }

    

    return 0;

}