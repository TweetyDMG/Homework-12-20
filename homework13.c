#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
int count_letter(char* array);

int main() {

    setlocale(LC_ALL, "Russian");

    char string[100];


    printf("Введите строку: ");
    fgets(string, sizeof(string), stdin);

    int count = count_letter(string);

    printf("Количество букв в двух последних словах: %d\n", count);

    return 0;
}

int count_letter(char* array)
{
    int length = strlen(array);
    int count = 0;
    int wordCount = 0;
    int inWord = 0;

    for (int i = length - 1; i >= 0; i--) {
        char currentChar = array[i];
        if ((currentChar >= 'a' && currentChar <= 'z') || (currentChar >= 'A' && currentChar <= 'Z')) {
            count++;
            inWord = 1;
        }
        else {
            if (inWord) {
                wordCount++;
                inWord = 0;
            }
        }

        if (wordCount == 2) {
            break;
        }
    }
    return count;
}