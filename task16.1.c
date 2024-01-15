#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h> 
#include <conio.h> 
#include <windows.h> 

double* full_elements(double *ptr_array, int size);
double* calc_elements(double* array, int size);
void put_elements(double* array, int size);
void delete_k(double* ptr_arr, int* size, int k);
double* insert_minus_999(double* ptr_arr, int* size, int k);

int main()
{
    setlocale(LC_CTYPE, "RUS");
    int size, k;
    double* ptr_array;

    printf("Введите размера динамического массива: ");
    scanf("%d", &size);

    ptr_array = (double*)malloc(size * sizeof(double));

    full_elements(ptr_array, size);

    printf("Массив до изменения:\n");
    put_elements(ptr_array, size);
    calc_elements(ptr_array, size);
    printf("\n------------\n");
    printf("\nМассив после изменения: \n");
    put_elements(ptr_array, size);
    printf("\n------------\n");
    printf("\nВведите k-ый элемент: ");
    scanf("%d", &k);
    printf("\n------------\n");
    delete_k(ptr_array, &size, k);
    printf("\nМассив после удаления каждого %d элемента:\n", k);
    put_elements(ptr_array, size);
    printf("\n------------\n");
    ptr_array = insert_minus_999(ptr_array, &size, k);
    printf("\nМассив после вставки -999 после каждого %d элемента:\n", k);
    put_elements(ptr_array, size);
    system("pause");
    free(ptr_array);
}


double* full_elements(double* ptr_array, int size)
{
    for (int i = 0; i < size; ++i)
    {
        ptr_array[i] = ((double)rand() / 10) - 9;
    }
    return ptr_array;
}

double* calc_elements(double* array, int size)
{
    for (int i = 1; i < size; i += 2) array[i] += 1;
    return array;
}

void put_elements(double* array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("array[%d] = %.2lf\n", i, array[i]);
    }
}

void delete_k(double* ptr_arr, int* size, int k) {
    int new_size = (*size) - ((*size) / k);
    int j = 0;
    for (int i = 0; i < (*size); ++i) {
        if ((i + 1) % k != 0) {
            ptr_arr[j] = ptr_arr[i];
            ++j;
        }
    }
    (*size) = new_size;
}



double* insert_minus_999(double* ptr_arr, int* size, int k)
{
    int new_size = (*size) + (*size) / k;
    double* new_ptr_arr = (double*)malloc(new_size * sizeof(double));

    int j = 0;

    for (int i = 0; i < (*size); ++i)
    {
        new_ptr_arr[j] = ptr_arr[i];
        ++j;

        if ((i + 1) % k == 0)
        {
            new_ptr_arr[j] = -999;
            ++j;
        }
    }

    free(ptr_arr);

    (*size) = new_size;

    return new_ptr_arr;
}