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
    
int main() {
	setlocale(LC_CTYPE, "RUS");
	
    srand(time(NULL));
    int m = 1 + rand() % 10;
    int k;

    printf("�������� ����� �� 1 �� 10: ");
    scanf("%d", &k);

    if (k == m) {
        printf("�� ������� �����\n");
    } else {
        printf("�� �� �������. ���������� ����� ���� %d.\n", m);
    }

    return 0;
}