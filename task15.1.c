#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h> 
char a[26][26];
int i, j;
void printArray(int n, int m);
void fillArray(int n, int m);

int main() {
    setlocale(LC_ALL, "Russian");
    int m, n;
    do {
        printf("Введите количество строк (не больше 5): ");
        scanf("%d", &n);
        printf("Введите количество столбцов (не больше 5): ");
        scanf("%d", &m);
        if (n <= 0 || n > 5 ||m <= 0 || m > 5) printf("Некорректные данные. Повторите ввод\n");
    } while (n <= 0 || n > 5 || m <= 0 || m > 5);
    fillArray(n, m);
    printArray(n, m);
}

void fillArray(int n, int m) {
    char currentChar = 'A';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = currentChar + j;
        }
        currentChar += m;
    }
}

void printArray(int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%c ", a[i][j]);
        }
        printf("\n");
    }
}