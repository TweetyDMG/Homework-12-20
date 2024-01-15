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
    printf("��������� ��� ������ ������� � ����.\n\n");
    printf("����:\n");
    printf("1) ������ �������:\n");
    printf("2) �����:\n");
    scanf("%d", &menu);

    if (menu == 1)
    {
        numAlbum++;
        getchar();
        printf("������� �������� �����, ���� ����� �������� ������ ������� (�� ����� 10 ��������, ������� ������ txt):\n");
        gets(name_file);
        printf("�������� �����...\n");
        file = fopen(name_file, "a+");
        printf("������� �������� �������: ");
        gets(objetcsAlbum[numAlbum].name);
        printf("������� ��� ������� �������: ");
        scanf("%d", &objetcsAlbum[numAlbum].year_release);
        getchar();
        printf("������� ����� �������: ");
        gets(objetcsAlbum[numAlbum].style);
        printf("������� ���������� ������ � �������: ");
        scanf("%d", &objetcsAlbum[numAlbum].amount_tracks);
        getchar();
        printf("������� ����������������� �������� �������: ");
        scanf("%d", &objetcsAlbum[numAlbum].sound_duration);
        getchar();

        replace(objetcsAlbum[numAlbum].name);
        replace(objetcsAlbum[numAlbum].style);

        for (int i = 1; i <= numAlbum; i++)
        {
            fprintf(file, "\n��������: %s\n��� �������: %d\n�����: %s\n���������� ������: %d\n�����������������: %d\n", objetcsAlbum[i].name, objetcsAlbum[i].year_release, objetcsAlbum[i].style, objetcsAlbum[i].amount_tracks, objetcsAlbum[i].sound_duration);
        }

        fclose(file); // ��������� ���� ����� ������
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

