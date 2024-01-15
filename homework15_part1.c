#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h> 
char a[26][26];
int i, j;
double find_max_value(double a[][5], int sets, int values);
double calc_total_average(double a[][5], int sets, int values);
double calc_set_average(double a[], int values);
void input_values(double a[][5], int sets, int values);


int main() {
    setlocale(LC_ALL, "Russian");
    const int sets = 3;
    const int values = 5;

    double data[3][5];


    input_values(data, sets, values);


    printf("\nСредние значения каждого набора:\n");
    for (int i = 0; i < sets; i++) {
        printf("Набор %d: %.2lf\n", i + 1, calc_set_average(data[i], values));
    }


    double totalAverage = calc_total_average(data, sets, values);
    printf("\nСреднее значение всех значений: %.2lf\n", totalAverage);


    double maxValue = find_max_value(data, sets, values);
    printf("Наибольшее значение из 15 значений: %.2lf\n", maxValue);

    return 0;
}

double find_max_value(double a[][5], int sets, int values) {
    double max = a[0][0];

    for (int i = 0; i < sets; i++) {
        for (int j = 0; j < values; j++) {
            if (a[i][j] > max) {
                max = a[i][j];
            }
        }
    }

    return max;
}

double calc_total_average(double a[][5], int sets, int values) {
    double sum = 0;

    for (int i = 0; i < sets; i++) {
        for (int j = 0; j < values; j++) {
            sum += a[i][j];
        }
    }

    return sum / (sets * values);
}

double calc_set_average(double a[], int values) 
{
    double sum = 0;

    for (int i = 0; i < values; i++) {
        sum += a[i];
    }

    return sum / values;
}

void input_values(double a[][5], int sets, int values) 
{
    for (int i = 0; i < sets; i++) {
        printf("Введите 5 двойных чисел для набора %d: ", i + 1);
        for (int j = 0; j < values; j++) {
            scanf("%lf", &a[i][j]);
        }
    }
}