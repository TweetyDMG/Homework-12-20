#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

#define N 100    
#define K 10     

void printHistogram(int counter[], int nmax);

int main(void) {
    setlocale(LC_CTYPE, "RUS");

   int counter[K + 1] = {0};
    int array[N]; 

    srand(time(NULL)); 

    for (int i = 0; i < N; ++i) {
        array[i] = 1 + rand() % K; 
        counter[array[i]]++; 
    }

    int nmax = 1;
    for (int i = 1; i <= K; ++i) {
        if (counter[i] > counter[nmax]) {
            nmax = i;
        }
    }

    printf("Гистограмма частоты встречаемости случайных чисел:\n");
    printHistogram(counter, nmax);

    return 0;
}

void printHistogram(int counter[], int nmax) {
    int R = 50;
    for (int i = 1; i <= K; ++i) {
        int x = (int)((double)counter[i] / counter[nmax] * R);
        printf("%2d | ", i);
        for (int j = 0; j < x; ++j) {
            printf("*");
        }
        printf("\n");
    }
}
