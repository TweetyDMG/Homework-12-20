#include <stdio.h>
#include <locale.h>
double findMaxInRange(double *ptr_array, int start, int end);


int main() {
    setlocale(LC_CTYPE, "RUS");

    int arraySize;

    // ������ � ������������ ������� �������
    printf("������� ������ �������: ");
    scanf("%d", &arraySize);

    // �������� ������� � �������� ������������� ��������
    double myArray[100];

    // ���������� ������� ����������, ���������� �������������
    printf("������� %d ��������� �������:\n", arraySize);
    for (int i = 0; i < arraySize; ++i) {
        printf("������� %d: ", i + 1);
        scanf("%lf", &myArray[i]);
    }

    // ����� ������� ��� �����������
    printf("��������� ������:\n");
    for (int i = 0; i < arraySize; ++i) {
        printf("%.2lf ", myArray[i]);
    }
    printf("\n");

    // ������ � ������������ ������ ���������
    int startIdx, endIdx;
    printf("������� ��������� � �������� ������� ��������� (����� ������): ");
    scanf("%d %d", &startIdx, &endIdx);



    // ������������� ������� ��� ���������� ������������� �������� � ���������
    double maxInRange = findMaxInRange(myArray, startIdx, endIdx);

    printf("������������ �������� � ��������� [%d, %d]: %.2lf\n", startIdx, endIdx, maxInRange);

    getchar();

    return 0;
}

double findMaxInRange(double *ptr_array, int start, int end) {
    if (start > end) {
        printf("������������ ������� ���������.\n");
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
