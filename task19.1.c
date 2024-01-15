#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

int main(void) {
    setlocale(LC_ALL, "Russian");
    char fname[20] = "number.txt";
    FILE* out;
    puts("Создание файла");
    if ((out = fopen(fname, "wt")) == NULL)
    {
        printf("Ошибка открытия файла для записи");
        return 0;
    }
    fprintf(out, "%.2f\n", 12.56);
    fprintf(out, "%.2f\n", 12.56);
    fclose(out);
    return 1;
}