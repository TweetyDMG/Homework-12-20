#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <math.h>

#define M_PI 3.14

FILE* out;

int main(void) {
    setlocale(LC_CTYPE, "Russian");
    double step, sum_x = 0, sum_y = 0, x_read, y_read, average_value_x, average_value_y;
    char fname[20] = "temp.txt";
    int selection;
    int amount_x = 0;
    int amount_y = 0;

    do {
        printf("����\n");
        printf("1. ������ � ����� ����\n");
        printf("2. ������ � ������������ ����\n");
        printf("3. ������� ������ �� �����\n");
        printf("0. �����\n");
        printf("��������: \n");
        scanf("%d", &selection);

        switch (selection) {
        case 1:
            getchar();
            printf("������� ����� ��� ��� ����� � ����������� txt (�� ����� 20 ��������): ");
            gets(fname);
            puts("�������� �����");
            if ((out = fopen(fname, "wt")) == NULL) {
                printf("������ �������� ����� ��� ������");
                return 1;
            }

            printf("����������� �������: y = x^2 - (cos(M_PI*x))^2 �� ��������� [1;3]\n");
            printf("������� ��� ���������: ");
            scanf("%lf", &step);

            for (double i = 1.; i <= 3; i += step) {
                double x = i;
                double result = x * x - pow(cos(M_PI * x), 2);
                fprintf(out, "|  %2.2lf  |  %2.2lf  |\n", x, result);
                printf("|  %2.2lf  |  %2.2lf  |\n", x, result);
            }

            fclose(out);
            printf("������ ������� �������� � ���� %s\n", fname);
            break;

        case 2:
            printf("������� ������ � ���� %s\n", fname);
            puts("�������� �����");
            if ((out = fopen(fname, "a+")) == NULL) {
                printf("������ �������� ����� ��� ������");
                return 1;
            }

            printf("����������� �������: y = x^2 - (cos(M_PI*x))^2 �� ��������� [1;3]\n");
            printf("������� ��� ���������: ");
            scanf("%lf", &step);

            for (double i = 1.; i <= 3; i += step) {
                double x = i;
                double result = x * x - pow(cos(M_PI * x), 2);
                fprintf(out, "|  %2.2lf  |  %2.2lf  |\n", x, result);
                printf("|  %2.2lf  |  %2.2lf  |\n", x, result);
            }
            fprintf(out, "\n");
            fclose(out);
            printf("������ ������� �������� � ���� %s\n", fname);
            break;

        case 3:
            puts("������� ���� ��� ������");
            scanf("%s", fname);
            out = fopen(fname, "rt");
            if (out == NULL) {
                printf("������ �������� �����");
                return 1;
            }
            sum_x = 0;
            sum_y = 0;
            amount_x = 0;
            amount_y = 0;

            while (!feof(out)) {
                fscanf(out, "%lf %lf", &x_read, &y_read);
                sum_x += x_read;
                sum_y += y_read;
                amount_x++;
                amount_y++;
            }

            fclose(out);

            if (amount_x > 0) {
                average_value_x = sum_x / amount_x;
                printf("������� �������� ��� ���� x: %.2lf\n", average_value_x);
            } else {
                printf("��� ������ ��� ������� �������� �������� x\n");
            }

            if (amount_y > 0) {
                average_value_y = sum_y / amount_y;
                printf("������� �������� ��� ���� y: %.2lf\n", average_value_y);
            } else {
                printf("��� ������ ��� ������� �������� �������� y\n");
            }
            break;

        case 0:
            break;

        default:
            printf("������������ ����� ��������.\n");
            return 1;
        }
    } while (selection != 0);

    return 0;
}
