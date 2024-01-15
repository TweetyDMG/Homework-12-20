#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h> //��� ������� ������
#include <conio.h> //��� getch()
#include <windows.h> //��� system("cls")
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
		
	
	printf("\n��������� �� ������������ �21\n\n");
	printf("1. ��������� ������ ������� ���������� ����������\n");
	printf("2. ������� ���� �������\n");
	printf("3. ����� ������ �� ������\n");
	printf("4. ����� ������� �� ����� ����\n");
	printf("5. ������������� ������\n\n");

	selection = getch();
	system("cls");

	switch(selection)
	{
	case '1':
		printf("\n������ ����������� ���������� �������...\n");
		fillCornicesArray();
		printf("������ ������� ���������� ���������� ����������.\n");
		getch();
		system("cls");
		break;
	
	case '2':
		printf("\n������� ���������� ������� ��� ������(�� ����� 1000): ");
		scanf("%d", &size_arr);
		print_array (size_arr);
		break;
	
	case '3':
		printf("������� ����� ������, ������� ���������� �����: ");
		scanf("%d", &search);
		print_lader(search);
		break;

	case '4':
		printf("������� ���������� �������� � ��������� ����� �������� �� ���������� ��������: ");
		scanf("%lf", &stepAmount);
		lader search_lader = search_step(stepAmount);
		if(search_lader.stepAmount == 0.0)
		{
			printf("������� �� ������\n");
			getch();
			system("cls");
		}
		else
		{
		printf("������ �������:\n");
		printf("������ ����������: %0.2lf �.\n", search_lader.fenceLength);
        printf("������ ���������: %0.2lf �.\n", search_lader.stepHeight);
        printf("������ ���������: %0.2lf\n", search_lader.stepWidth);
        printf("���������� ��������: %0.2lf\n\n", search_lader.stepAmount);
		getch();
		}
		system("cls");
		break;
		
	case '5':
		qsort();




	case '0':
		break;
	
	default:
		printf("�������� �����.\n");
		
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
		printf("������� %d\n\n", i);
		printf("������ ����������: %0.2lf �.\n", write[i].fenceLength);
        printf("������ ���������: %0.2lf �.\n", write[i].stepHeight);
        printf("������ ���������: %0.2lf\n", write[i].stepWidth);
        printf("���������� ��������: %0.2lf\n\n", write[i].stepAmount);
		printf("----------------\n");
	}
	getch();
	system("cls");
}

void print_lader(int search)
{
	printf("������ ������� %d\n", search);
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