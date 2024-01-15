#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

int rand10(int mmax);
double rand_double(double dmin, double dmax);
int* rand10_array(int n, int mmax);
double* rand_double_array(int n, double dm);

#define MAX 100

int main(void) 
{
    setlocale(LC_CTYPE, "RUS");
	srand(time(NULL));

    int mmax, n;
    double dmin, dmax, dm;

    printf("������� mmax (����� �����): ");
    scanf("%d", &mmax);

    printf("������� dmin (������������ �����): ");
    scanf("%lf", &dmin);

    printf("������� dmax (������������ �����): ");
    scanf("%lf", &dmax);

    printf("������� n (����� �����): ");
    scanf("%d", &n);

    printf("������� dm (������������ �����): ");
    scanf("%lf", &dm);

    int randomInt = rand10(mmax);
	
	double randomDouble = rand_double(dmin, dmax);
	
	int* intArray = rand10_array(n, mmax);
		
	double* doubleArray = rand_double_array(n, dm);
    
    printf("\n\n��������� ����� ����� �� 1 �� %d: %d\n", mmax, randomInt);
    printf("��������� ������������ ����� �� %.2lf �� %.2lf: %.2lf\n", dmin, dmax, randomDouble);
    printf("������ ��������� ����� ����� �� 1 �� %d\n", mmax);
	for (int i = 0; i < n; ++i) {
		printf("%d ", intArray[i]);
    }
    printf("\n");
    free(intArray);
	
    printf("������ ��������� ������������ ����� �� -%.2lf �� %.2lf\n", dm, dm);
    for (int i = 0; i < n; ++i) {
        printf("%.2lf ", doubleArray[i]);
    }
    printf("\n");
    free(doubleArray);

    return 0;
}

int rand10(int mmax) {
    return rand() % mmax + 1;
}

double rand_double(double dmin, double dmax) {
    double scale = rand() / (double) RAND_MAX;
    return dmin + scale * (dmax - dmin);
}

int* rand10_array(int n, int mmax) {
    int* result = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i) {
        result[i] = rand10(mmax);
    }
    return result;
}

double* rand_double_array(int n, double dm) {
    double* result = (double*)malloc(n * sizeof(double));
    for (int i = 0; i < n; ++i) {
        result[i] = rand_double(-dm, dm);
    }
    return result;
}