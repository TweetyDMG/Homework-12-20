#include <stdio.h>
#include <locale.h>
double findMaxInRange(double *ptr_array, int start, int end);


int main() {
    setlocale(LC_CTYPE, "RUS");

    int arraySize;

    // Запрос у пользователя размера массива
    printf("Введите размер массива: ");
    scanf("%d", &arraySize);

    // Создание массива с заданным пользователем размером
    double myArray[100];

    // Заполнение массива значениями, введенными пользователем
    printf("Введите %d элементов массива:\n", arraySize);
    for (int i = 0; i < arraySize; ++i) {
        printf("Элемент %d: ", i + 1);
        scanf("%lf", &myArray[i]);
    }

    // Вывод массива для наглядности
    printf("Введенный массив:\n");
    for (int i = 0; i < arraySize; ++i) {
        printf("%.2lf ", myArray[i]);
    }
    printf("\n");

    // Запрос у пользователя границ интервала
    int startIdx, endIdx;
    printf("Введите начальный и конечный индексы интервала (через пробел): ");
    scanf("%d %d", &startIdx, &endIdx);



    // Использование функции для нахождения максимального значения в интервале
    double maxInRange = findMaxInRange(myArray, startIdx, endIdx);

    printf("Максимальное значение в интервале [%d, %d]: %.2lf\n", startIdx, endIdx, maxInRange);

    getchar();

    return 0;
}

double findMaxInRange(double *ptr_array, int start, int end) {
    if (start > end) {
        printf("Некорректные границы интервала.\n");
        return 0;
    }

    double maxVal = ptr_array[start];

    for (int i = start + 1; i <= end; ++i) {
        if (ptr_array[i] > maxVal) {
            maxVal = ptr_array[i];
        }
    }

    return maxVal;
}
