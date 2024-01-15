#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main() {
	setlocale(LC_CTYPE, "RUS");
	
    FILE *inputFile, *outputFile;
    char inputFileName[] = "winter.txt";
    char outputFileName[100];

    inputFile = fopen(inputFileName, "r");

    if (inputFile == NULL) {
        printf("������ �������� ����� %s.\n", inputFileName);
        return 1;
    }

    printf("������� ��� ��� ������ �����: ");
    fgets(outputFileName, sizeof(outputFileName), stdin);

    outputFileName[strcspn(outputFileName, "\n")] = '\0';

    outputFile = fopen(outputFileName, "w");

    char line[1000];

    while (fgets(line, sizeof(line), inputFile) != NULL) {
        line[strcspn(line, "\n")] = '\0';

        // ��������� ������ ����� ��� ����
        char *firstWord = strtok(line, " ");
        if (firstWord != NULL) {
            fprintf(outputFile, "%s %s\n", firstWord, firstWord);
        }
    }

    fclose(inputFile);
    fclose(outputFile);

    printf("�������������� ��������� �������. ��������� ������� � ���� %s.\n", outputFileName);

    return 0;
}
