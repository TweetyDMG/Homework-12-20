#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h> 
char a[26][26];
int i, j;
void fillArray(int a[][7], int n, int m);
void print_array(int a[][7], int n, int m);
void transpose_array(int a[][7], int n, int m);
double arith_mean(int a[][7], int n, int m);
int count_col(int a[][7], int n, int m);
int count_row(int a[][7], int n, int m);
int count_row_col(int a[][7], int n, int m);
void find_coor(int a[][7], int n, int m, int* maxRow, int* maxCol);


int main() {
    setlocale(LC_ALL, "Russian");
    
    int a[7][7];
    double result;
    int maxRow, maxCol;

    fillArray(a, 7, 7);

    printf("Исходный массив:\n");
    print_array(a, 7, 7);

    transpose_array(a, 7, 7);

    printf("\nТранспонированный массив:\n");
    print_array(a, 7, 7);

    result = arith_mean(a, 7, 7);

    printf("\nСреднее арифметическое четных элементов третьего столбца: %.1lf\n", result);

    printf("\nЧисло пар одинаковых соседних элементов в одной строке: %d\n", count_row(a, 7, 7));
    printf("Число пар одинаковых соседних элементов в одном столбце: %d\n", count_col(a, 7, 7));
    printf("Число пар одинаковых соседних элементов в одной строке и столбце: %d\n", count_row_col(a, 7, 7));


    find_coor(a, 7, 7, &maxRow, &maxCol);

    printf("\nКоординаты максимального элемента: (%d, %d)\n", maxRow, maxCol);

    return 0;
}

void fillArray(int a[][7], int n, int m) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = rand() % 21 - 10;  // Генерация случайного числа от -10 до 10
        }
    }
}

void print_array(int a[][7], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%3d ", a[i][j]);
        }
        printf("\n");
    }
}

void transpose_array(int a[][7], int n, int m) {
    int transposedArr[7][7];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            transposedArr[j][i] = a[i][j];
        }
    }
}

double arith_mean(int a [][7], int n, int m )
{
    double result;
    double sum = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i][2] % 2 == 0) {
            sum += a[i][2];
            count++;
        }
    }
    if (count == 0) {
        return 0.0;
    }

    return (double)sum / count;
    result = sum / count;
    return result;
}

int count_row(int a[][7], int n, int m) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m - 1; j++) {
            if (a[i][j] == a[i][j + 1]) {
                count++;
            }
        }
    }

    return count;
}

int count_col(int a[][7], int n, int m) {
    int count = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == a[i + 1][j]) {
                count++;
            }
        }
    }

    return count;
}

int count_row_col(int a[][7], int n, int m) 
{
    int count = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            if (a[i][j] == a[i][j + 1] && a[i][j] == a[i + 1][j]) {
                count++;
            }
        }
    }

    return count;
}

void find_coor(int a[][7], int n, int m, int* maxRow, int* maxCol)
{
    int max_element = a[0][0];
    *maxRow = 0;
    *maxCol = 0;

    for (int j = 0; j < m; j++) {
        if (a[0][j] > max_element) {
            max_element = a[0][j];
            *maxCol = j;
        }
    }

    for (int i = 1; i < n; i++) {
        if (a[i][*maxCol] > max_element) {
            max_element = a[i][*maxCol];
            *maxRow = i;
        }
    }
    return * maxRow, * maxCol;
}