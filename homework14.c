#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>
int countSignChanges(const int* arr, int size); 

int main() {
    setlocale(LC_ALL, "Russian");

    int size;
    int array[100];

    do
    {
        printf("������� ������ �������(�� ������ 100): ");
        scanf("%d", &size);
        if (size <= 0 || size > 100) {
            printf("������������ ������ �������.\n");
        }
    } while (size <= 0 || size > 100);
  
    printf("������� �������� �������:\n");

    for (int i = 0; i < size; i++) {
        printf("������� %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    int result = countSignChanges(array, size);
    printf("����� ��������� ����� �������� �������� ���������: %d\n", result);
    getchar();
    getchar();

    return 0;
}

int countSignChanges(const int* arr, int size) {
    int signChanges = 0;

    for (int i = 1; i < size; i++) {
        if ((arr[i - 1] >= 0 && arr[i] < 0) || (arr[i - 1] < 0 && arr[i] >= 0)) {
            signChanges++;
        }
    }
    return signChanges;
}