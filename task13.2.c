#include <stdio.h>
#include <string.h>
#include <locale.h>

int main() {

    setlocale(LC_ALL, "Russian");


    printf("Введите ваше имя: ");


    char Name[20];
    scanf("%s", Name);


    char Snew[20]; 
    strcpy(Snew, "Привет, ");
    strcat(Snew, Name);

    for (int i = 0; i < strlen(Snew); i++) {
        if (i == 0) {
            Snew[i] = tolower(Snew[i]);
        }
        else {
            Snew[i] = toupper(Snew[i]);
        }
    }

    printf("%s\n", Snew);

    return 0;
}