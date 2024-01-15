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

	printf("\nПривет. Я игра в кости\n\n");
	
	printf("Подбросьте первую кость \n\n");
	printf("-Для этого нажмите любую клавишу-\n");
	getch();

	bound1 = 1 + rand() % (6 - 1 + 1);
	enemy1 = 1 + rand() % (6 - 1 + 1);
	system("cls");
	printf("\nНа первой кости выпало %d\n\n", bound1);
	printf("Вашему противнику выпало %d\n\n", enemy1);
	if(enemy1>bound1) printf("Вы проигрываете. Включите вашу удачу\n\n");
	printf("Подбросьте вторую кость\n");
	getch();
	printf("\n----------\n");
	bound2 = 1 + rand() % (6 - 1 + 1);
	enemy2 = 1 + rand() % (6 - 1 + 1);
	sum1 = bound1 + bound2;
	sum2 = enemy1 + enemy2;
	
	printf("\nНа второй кости вам выпало %d\n", bound2);
	printf("Ваша сумма очков равна %d\n\n", sum1);
	printf("Вашему противнику на второй кости выпало %d\n", enemy2);
	printf("Его сумма равна %d\n\n", sum2);
	if (sum1 > sum2) printf("Вы выиграли. Вашей удачи можно позавидовать\n");
	if(sum1 < sum2) printf("Вы проиграли. Не волнуйтесь, повезёт в следующий раз.");
	else printf("Ничья. Ничего себе");
	getch();
	
	return 0;
}