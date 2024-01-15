#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <Windows.h>

#define LENGTH 100

typedef struct{
    int trainNumber;
    char arrivalLocation[LENGTH];
    char arrivalTime[LENGTH];
    char departureLocation[LENGTH];
    char departureTime[LENGTH];
} train;

void writeTrainRecordsToFile(train* records, int numRecords, const char* filename);

int main() {
    setlocale(LC_CTYPE, "RUS");

    int numTrains;

    printf("Введите количество поездов: ");
    scanf("%d", &numTrains);
    printf("\n");

    train* trainRecords = (train*)malloc(numTrains * sizeof(train));

    for (int i = 0; i < numTrains; ++i) {
        printf("Введите информацию о поезде %d:\n", i + 1);
        printf("Номер поезда: ");
        scanf("%d", &trainRecords[i].trainNumber);

        printf("Пункт прибытия и время (в формате 'Москва 14:30'): ");
        scanf("%s %s", trainRecords[i].arrivalLocation, trainRecords[i].arrivalTime);

        printf("Пункт отбытия и время (в формате 'Санкт-Петербург 18:45'): ");
        scanf("%s %s", trainRecords[i].departureLocation, trainRecords[i].departureTime);
    }

    char filename[LENGTH];
    printf("Введите имя файла: ");
    scanf("%s", filename);

    writeTrainRecordsToFile(trainRecords, numTrains, filename);

    free(trainRecords);

    printf("Информация о поездах записана в файл '%s'.\n", filename);

    system("pause");

    return 0;
}

void writeTrainRecordsToFile(train* records, int numRecords, const char* filename) {
    FILE* file = fopen(filename, "w");

    if (file == NULL) {
        printf("Ошибка открытия файла.\n");
        return;
    }

    for (int i = 0; i < numRecords; ++i) {
        fprintf(file, "Поезд №%d: %s %s - %s %s || ",
                records[i].trainNumber,
                records[i].arrivalLocation,
                records[i].arrivalTime,
                records[i].departureLocation,
                records[i].departureTime);
    }

    fclose(file);
}

