#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <math.h>
#include <conio.h>
#include <windows.h>
#define SCREENW 60
#define SCREENH 40

typedef double (*TFun)(double);

double fun1(double);
double fun2(double);
double fun3(double);
void t_res(TFun, double, double, double);
void calculate_value(TFun);
void tabulate(TFun f);
void read_from_file(TFun f);
void plot(double x0, double x1, TFun f);
double* transform(TFun prtf, double xmin, double dx);
void printArray(double* array);

int main(void)
{
    setlocale(LC_CTYPE, "RUS");
    int choice;
    int function_choice;
    TFun selected_function;
    double x0, x1;
    double xmin, dx;
    TFun func[3] = {fun1, fun2, fun3};

    do
    {
        system("cls");
        puts("����");
        puts("1. ������� �������");
        puts("2. ��������� ��������");
        puts("3. ������������");
        puts("4. ��������� �������� �� �����");
        puts("5. ���������� ������");
        puts("6. ������ � �������� �� 25 ���������");
        puts("7. �����");
        printf("�������� ����� (1-7): ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:

            printf("�������� �������:\n");
            printf("1. S(x)\n");
            printf("2. V(x)\n");
            printf("3. Y(x)\n");
            printf("�������� ����� (1-3): ");
            scanf("%d", &function_choice);

            switch (function_choice)
            {
            case 1:
                selected_function = func[1];
                break;
            case 2:
                selected_function = func[2];
                break;
            case 3:
                selected_function = func[3];
                break;
            }
            break;
        case 2:
            printf("\n\t �������: 2. ��������� ��������\n");
            calculate_value(selected_function);
            break;
        case 3:
            printf("\n\t �������: 3. ������������\n");
            tabulate(selected_function);
            break;
        case 4:
            read_from_file(selected_function);
            break;

        case 5:
            puts("������� �������� x0: ");
            scanf("%lf", &x0);
            puts("������� �������� x1: ");
            scanf("%lf", &x1);
            plot(x0, x1, selected_function);
            break;

        case 6:
            puts("������� xmin: ");
            scanf("%lf", &xmin);
            puts("������� dx: ");
            scanf("%lf", &dx);
            double* result = transform(selected_function, xmin, dx);
            printArray(result);
            break;

        case 7:
            printf("\n\t �����\n");
            break;
        }

        printf("\n������� ����� ������� ��� �����������...\n");
        getch();
    } while (choice != 7);

    return 0;
}

void printArray(double* array) {
    for (int i = 0; i < 25; ++i) {
        printf("%d: %lf\n", i, array[i]);
    }
}

double* transform(TFun prtf, double xmin, double dx)
{
    double* result = (double*)malloc(25 * sizeof(double));

    for (int i = 0; i < 25; ++i)
    {
        result[i] = prtf(xmin + i * dx);
    }

    return result;
}



double fun1(double r)
{
    return log(fabs(pow(r, 1.0 / 3)));
}

double fun2(double r)
{
    double result;
    if (r > 1)
    {
        result = sqrt(tan(r * r - 1));
    }
    else if (r >= 0 && r <= 1)
    {
        result = -2 * r;
    }
    else
    {
        result = exp(cos(r));
    }
    return result;
}

double fun3(double r)
{
    double res1 = ((r - 1) / (r + 1)) + (1.0 / 3) * pow(((r - 1) / (r + 1)), 3);
    double res2 = (1.0 / 5) * pow(((r - 1) / (r + 1)), 5);
    double res3 = (1.0 / 7) * pow(((r - 1) / (r + 1)), 7);
    double result = res1 + res2 + res3;
    return result;
}

void t_res(TFun f, double xn, double xk, double h)
{
    for (double x = xn; x <= xk; x += h)
    {
        printf(" x = %5.2lf, y = %8.5lf\n", x, f(x));
    }
}

void calculate_value(TFun f)
{
    double x_value;
    printf("������� �������� x: ");
    scanf("%lf", &x_value);
    printf("���������: %8.5lf\n", f(x_value));
}

void tabulate(TFun f)
{
    double xn, xk, h;
    printf("������� ��������� �������� x: ");
    scanf("%lf", &xn);
    printf("������� �������� �������� x: ");
    scanf("%lf", &xk);
    printf("������� ��� ���������: ");
    scanf("%lf", &h);
    t_res(f, xn, xk, h);
}

void read_from_file(TFun f)
{
    FILE *file;
    double value;

    file = fopen("dat.txt", "r");
    if (file == NULL)
    {
        printf("�� ������� ������� ����.\n");
        return;
    }

    printf("����������:\n");
    while (fscanf(file, "%lf", &value) != EOF)
    {
        printf("��������: %lf, ���������: %8.5lf\n", value, f(value));
    }

    fclose(file);
}

void plot(double x0, double x1, TFun f)
{

//������� ���� ������ � ��������

char screen[SCREENW][SCREENH];

double x, y[SCREENW];

double ymin=0, ymax=0;

double hx, hy;

int i, j;

int xz,yz;

hx=(x1-x0)/(SCREENW-1);

for(i=0, x=x0;i<SCREENW; ++i, x+=hx){

  	y[i]=f(x); //������ �������� ������� ��� ������ ����� ���� ������ �������

 	if(y[i]<ymin) ymin=y[i];

 	if(y[i]>ymax) ymax=y[i];

}

hy=(ymax-ymin)/(SCREENH-1);

yz=(int)floor(ymax/hy+0.5);

xz=(int)floor((0.-x0)/hx+0.5);

//���������� ���� � ���������� ������� ����������� ���������

for(j=0;j<SCREENH; ++j)

 	for(i=0;i<SCREENW; ++i) {

 	 if(j==yz && i==xz) screen[i][j]='+';

  	else if (j==yz) screen[i][j]='-';

  	 else if (i==xz) screen[i][j]='|';

   	else screen[i][j]=' ';

 	}

//����������� ��������� �������� ������� �� ���� ������

for(i=0;i<SCREENW; ++i){

 j=(int)floor((ymax-y[i])/hy+0.5);

 screen[i][j]='*';

}

//������ ������� ��������

 	for(j=0;j<SCREENH; ++j){

 		for(i=0;i<SCREENW; ++i)  putchar(screen[i][j]);

  		putchar('\n');

 	}

}