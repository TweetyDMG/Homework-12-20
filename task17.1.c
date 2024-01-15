#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h> 
#include <conio.h>
#include <windows.h>
#include <time.h>
#define MAX 100
#define MIN -100

void sort_buble(int*ptrarr, int n);
int* sort_shaker(int*ptrarr, int n);
int* sort_select(int*ptrarr, int n);
int* sort_insert(int*ptrarr, int n);
int* full_elements(int* ptrarr, int size);
void put_elements(int* array, int size);

int main() {
    setlocale(LC_CTYPE, "RUS");
    int size;

    printf("Введите размер динамического массива: ");
    scanf("%d", &size);

    int* ptrarr = (int*)malloc(size * sizeof(int));
    int* ptrarr1 = (int*)malloc(size * sizeof(int));

    full_elements(ptrarr, size);
    system("cls");
    printf("\nМассив до сортировки:\n");
    put_elements(ptrarr, size);
    printf("-----------------------------\n");
    printf("Массив после шейкерной сортировки:\n");
    ptrarr1 = sort_shaker(ptrarr, size);
    put_elements(ptrarr1, size);
    getch();
    system("cls");


    printf("Массив после сортировки простым выбором: \n");
    ptrarr1 = sort_select(ptrarr, size);
    put_elements(ptrarr1, size);
    getch();
    system("cls");


    printf("Массив после сортировки вставками: \n");
    ptrarr1 = sort_insert(ptrarr, size);
    put_elements(ptrarr1, size);
    getch();
    return 0;
}

void put_elements(int* ptrarr, int size)
{
    for (int i = 0; i <= size-1; i++)
    {
        printf("%d ", ptrarr[i]);   
    }
    printf("\n");
}

int* full_elements(int* ptrarr, int size) {
    srand((unsigned int)time(NULL));
    for (int i = 0; i <= size; ++i) {
        ptrarr[i] = rand() % (MAX - MIN + 1) + MIN;
    }
    return ptrarr;
}

/*void sort_buble(int*ptrarr, int n)
{
    
}*/

int* sort_shaker(int* ptrarr, int n) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        for (int i = left; i < right; i++) {
            if (ptrarr[i] > ptrarr[i + 1]) {
                int temp = ptrarr[i];
                ptrarr[i] = ptrarr[i + 1];
                ptrarr[i + 1] = temp;
            }
        }
        right--;

        for (int i = right; i > left; i--) {
            if (ptrarr[i] < ptrarr[i - 1]) {
                int temp = ptrarr[i];
                ptrarr[i] = ptrarr[i - 1];
                ptrarr[i - 1] = temp;
            }
        }
        left++;
    }

    return ptrarr;
}

/*int* sort_select(int*ptrarr, int n) //Сортировка от большего к меньшему
{
    for(int i = 0; i < n ; i++)
    {
        int imax = i;
        for (int j = i + 1; j < n; j++)
        {
            if (ptrarr[i] >= ptrarr[imax])
            {
                imax = j;
            }
            int temp = ptrarr[i];
            ptrarr[i] = ptrarr[imax];
            ptrarr[imax] = temp;
        }
    }
    return ptrarr;
}*/

int* sort_insert(int* ptrarr, int n) {
    for (int i = 1; i < n; i++) {
        int temp = ptrarr[i];
        int j = i;
        
        while (ptrarr[j - 1] > temp && j > 0) {
            ptrarr[j] = ptrarr[j - 1];
            j--;
        }

        ptrarr[j] = temp;
    }
    
    return ptrarr;
}

int* sort_select(int* ptrarr, int n)  //Сортировка простым выбором от меньшего к большему
{
    for (int i = 0; i < n; i++) {
        int imin = i;
        for (int j = i + 1; j < n; j++) {
            if (ptrarr[j] < ptrarr[imin]) { 
                imin = j; 
            }
        }
        int temp = ptrarr[i];
        ptrarr[i] = ptrarr[imin]; 
        ptrarr[imin] = temp; 
    }
    return ptrarr;
}