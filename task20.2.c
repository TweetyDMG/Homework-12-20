#include <stdio.h>
#include <string.h>
#include <locale.h>


FILE* input;
FILE* output;

int main(void) {
    setlocale(LC_CTYPE, "RUS");
    double numbers[50];
    int count = 0;

    char inputFileName[50] = "input.txt";
    char outputFileName[50] = "inputparity.txt";

    printf("������� ��� ����� ��� ������ (��������, input.txt): ");
    scanf("%s", inputFileName);

    printf("������ �� ����� %s\n", inputFileName);

    input = fopen(inputFileName, "r");
    if (input == NULL) {
        printf("������ �������� ����� ��� ������\n");
        return 1;
    }

    while (fscanf(input, "%lf", &numbers[count]) == 1 && count < 50) {
        count++;
    }

    fclose(input);

    for (int i = 0; i < count; i++) {
        if (numbers[i] > 100) {
            numbers[i] /= 2;
        }
    }

    printf("������ � ���� %s\n", outputFileName);

    output = fopen(outputFileName, "w");

    for (int i = 0; i < count; i++) {
        fprintf(output, "%.2lf\n", numbers[i]);
    }

    fclose(output);

    printf("������ ������� �������� � ���� %s\n", outputFileName);

    return 0;
}
