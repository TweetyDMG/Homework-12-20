#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

void replace(char *str);

typedef struct ALBUM
{
    char name[50];
    int year_release;
    char style[20];
    int amount_tracks;
    int sound_duration;
} album;

album objetcsAlbum[100];
int numAlbum = 0;

FILE *file;

int main(void)
{
    setlocale(LC_ALL, "RUS");

    int menu;
    char name_file[100];
    printf("Программа для записи альбома в файл.\n\n");
    printf("Меню:\n");
    printf("1) Запись альбома:\n");
    printf("2) Выход:\n");
    scanf("%d", &menu);

    if (menu == 1)
    {
        numAlbum++;
        getchar();
        printf("Введите названия файла, куда будет сохранёны данные альбома (не более 10 символов, включая формат txt):\n");
        gets(name_file);
        printf("Создание файла...\n");
        file = fopen(name_file, "a+");
        printf("Введите название альбома: ");
        gets(objetcsAlbum[numAlbum].name);
        printf("Введите год выпуска альбома: ");
        scanf("%d", &objetcsAlbum[numAlbum].year_release);
        getchar();
        printf("Введите стиль альбома: ");
        gets(objetcsAlbum[numAlbum].style);
        printf("Введите количество треков в альбоме: ");
        scanf("%d", &objetcsAlbum[numAlbum].amount_tracks);
        getchar();
        printf("Введите продолжительность звучания альбома: ");
        scanf("%d", &objetcsAlbum[numAlbum].sound_duration);
        getchar();

        replace(objetcsAlbum[numAlbum].name);
        replace(objetcsAlbum[numAlbum].style);

        for (int i = 1; i <= numAlbum; i++)
        {
            fprintf(file, "\nНазвание: %s\nГод выпуска: %d\nСтиль: %s\nКоличество треков: %d\nПродолжительность: %d\n", objetcsAlbum[i].name, objetcsAlbum[i].year_release, objetcsAlbum[i].style, objetcsAlbum[i].amount_tracks, objetcsAlbum[i].sound_duration);
        }

        fclose(file); // Закрываем файл после записи
    }

    return 0;
}

void replace(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == ' ')
        {
            str[i] = '_';
        }
    }
}

