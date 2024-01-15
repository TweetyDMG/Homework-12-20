#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h> 
#include <time.h>

#define YEARS 10
#define DAYS_IN_MONTH 31
#define DAYS_IN_FESTIVAL 7
#define MIN_TEMPERATURE 20
#define MAX_TEMPERATURE 40

void generateTemperatures(int temperatures[YEARS][DAYS_IN_MONTH]);
void findWarmestDays(int temperatures[YEARS][DAYS_IN_MONTH], int* startYear, int* startDay);

int main() {
    setlocale(LC_ALL, "Russian");
    int temperatures[YEARS][DAYS_IN_MONTH] = { {0} };
    int startYear, startDay;

    // Генерация случайных температур за последние 10 лет
    generateTemperatures(temperatures);

    // Поиск 7 подряд идущих дней с наиболее теплой температурой
    findWarmestDays(temperatures, &startYear, &startDay);

    // Вывод результатов
    printf("Температуры за последние 10 лет:\n");
    for (int i = 0; i < YEARS; i++) {
        for (int j = 0; j < DAYS_IN_MONTH; j++) {
            printf("%2d ", temperatures[i][j]);
        }
        printf("\n");
    }

    printf("\nВыбранные 7 дней для фестиваля (с %d июля по %d июля %d года):\n", startDay + 1, startDay + DAYS_IN_FESTIVAL, startYear + 1);
    for (int j = startDay; j < startDay + DAYS_IN_FESTIVAL; j++) {
        printf("%2d ", temperatures[startYear][j]);
    }
    printf("\n");

    return 0;
}

void generateTemperatures(int temperatures[YEARS][DAYS_IN_MONTH]) {
    srand(time(NULL));

    for (int i = 0; i < YEARS; i++) {
        for (int j = 0; j < DAYS_IN_MONTH; j++) {
            temperatures[i][j] = rand() % (MAX_TEMPERATURE - MIN_TEMPERATURE + 1) + MIN_TEMPERATURE;
        }
    }
}

void findWarmestDays(int temperatures[YEARS][DAYS_IN_MONTH], int* startYear, int* startDay) {
    int maxSum = 0;
    int currentSum = 0;

    for (int i = 0; i < YEARS; i++) {
        for (int j = 0; j < DAYS_IN_FESTIVAL; j++) {
            currentSum += temperatures[i][j];
        }

        if (currentSum > maxSum) {
            maxSum = currentSum;
            *startYear = i;
            *startDay = 0;
        }

        for (int j = DAYS_IN_FESTIVAL; j < DAYS_IN_MONTH; j++) {
            currentSum = currentSum - temperatures[i][j - DAYS_IN_FESTIVAL] + temperatures[i][j];

            if (currentSum > maxSum) {
                maxSum = currentSum;
                *startYear = i;
                *startDay = j - DAYS_IN_FESTIVAL + 1;
            }
        }
    }
}