#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

int main(void) {
    setlocale(LC_CTYPE, "RUS");
	
    srand(time(NULL));

    int m = 1 + rand() % 10;
    int bound1, bound2, enemy1, enemy2, sum1, sum2; 

	printf("\n������. � ���� � �����\n\n");
	
	printf("���������� ������ ����� \n\n");
	printf("-��� ����� ������� ����� �������-\n");
	getch();

	bound1 = 1 + rand() % (6 - 1 + 1);
	enemy1 = 1 + rand() % (6 - 1 + 1);
	system("cls");
	printf("\n�� ������ ����� ������ %d\n\n", bound1);
	printf("������ ���������� ������ %d\n\n", enemy1);
	if(enemy1>bound1) printf("�� ������������. �������� ���� �����\n\n");
	printf("���������� ������ �����\n");
	getch();
	printf("\n----------\n");
	bound2 = 1 + rand() % (6 - 1 + 1);
	enemy2 = 1 + rand() % (6 - 1 + 1);
	sum1 = bound1 + bound2;
	sum2 = enemy1 + enemy2;
	
	printf("\n�� ������ ����� ��� ������ %d\n", bound2);
	printf("���� ����� ����� ����� %d\n\n", sum1);
	printf("������ ���������� �� ������ ����� ������ %d\n", enemy2);
	printf("��� ����� ����� %d\n\n", sum2);
	if (sum1 > sum2) printf("�� ��������. ����� ����� ����� ������������\n");
	if(sum1 < sum2) printf("�� ���������. �� ����������, ������ � ��������� ���.");
	else printf("�����. ������ ����");
	getch();
	
	return 0;
}