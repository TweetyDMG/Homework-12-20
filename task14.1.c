#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>
#define M_PI 3.14159265358979323846
#define N 1000
double* full_elements(double* array, int size);
int put_elements(double* array, int size);
double* calc_elements(double* array, int size, int A);
double calculateFunction(double x);
double* fillArray(double* array, double size, double step);
double* calculateAverage(double* array, double* array2);
void output_array(double* array2);

int main()
{
    setlocale(LC_CTYPE, "RUS");
    int size;
    double array[N];
    double array2[10];
    float step;
    int A;
    printf("Введите размер массива: ");
    scanf("%d", &size);
    
    puts("Вывод массива");
    full_elements(array, size);
    
    printf("Введите число A: ");
    scanf("%d", &A);


    calc_elements(array, size, A);
    fillArray(array, size, step);
    calculateAverage(array, array2);
    output_array(array2);
    return 0;
}

double* full_elements(double* array, int size)
{
    for (int i = 0; i <= size; i++)
    {
        array[i] = randint();
    }
    return array;
}

int put_elements(double* array, int size)
{
    for (int i = 0; i <= size; i++)
    {
        printf("array[%d] = %.2lf\n", i, array[i]);
    }
}

double* calc_elements(double* array, int size, int A)
{
    int sum = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] == A) {
            sum += i;
        }
    }
    return sum;
}

double calculateFunction(double x) {
    return x * x - cos(M_PI * x) * cos(M_PI * x);
}

double* fillArray(double* array, double size, double step) {
    for (int i = 0; i < 100; i++) {
        double x = 1.0 + i * step;
        array[i] = calculateFunction(x);
    }
    return array;
}

double* calculateAverage(double* array, double* array2) 
{
    double sumPositive = 0.;
    double sumNegative = 0.;
    int positiveCount = 0;
    int negativeCount = 0;

    for (int i = 0; i < 100; i++) {
        if (array[i] > 0) {
            sumPositive += array[i];
            positiveCount++;
        }
        else if (array[i] < 0) {
            sumNegative += array[i];
            negativeCount++;
        }
    }
    double averagePositive = sumPositive / positiveCount;
    double averageNegative = sumNegative / negativeCount;

    array2[0] = sumPositive;
    array2[1] = positiveCount;
    array2[2] = averagePositive;
    array2[3] = sumNegative;
    array2[4] = negativeCount;
    array2[5] = averageNegative;
    return array2;
}

void output_array(double* array2)
{
    printf("Имя массива: array\n");
    printf("Накопленное значение положительных элементов: %0.2lf\n", array2[0]);
    printf("Число положительных элементов: %0.2lf\n", array2[1]);
    printf("Среднее значение положительных элементов: %0.2f\n", array2[2]);
    printf("Накопленное значение отрицательных элементов: %0.2f\n", array2[3]);
    printf("Число отрицательных элементов: %0.2lf\n", array2[4]);
    printf("Среднее значение отрицательных элементов: %0.2f\n", array2[5]);
}
