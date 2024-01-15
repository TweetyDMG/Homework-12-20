#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int main(void) {
    setlocale(LC_CTYPE, "RUS");

    List myList;
    List *current;
    initlist(&myList);

    fill_array(&myList);

    printf("Список до преобразования:\n");
    output_array(&current);

    paste_ten(&current);

    printf("Список после преобразования:\n");
    output_array(&current);
    
    printf("\n");
    system("pause");
    return 0;
}

void output_array(List *current)
{
    while (current != NULL) {
    printf("%d ", current->number);
    current = current->next;
    }
    printf("\n\n");
}

void paste_ten(List *current)
{
    while (current != NULL) {
    if (current->number < 0) {
        List *newItem = (List *)malloc(sizeof(List));
        newItem->number = 10;
        newItem->next = current->next;
        current->next = newItem;
        break;
    }
    current = current->next;
    }
}

void fill_array(List *MyList)
{
    for (int i = 1; i <= 8; ++i)   
    {
    int random = rand() % (9 - (-9) + 1) + (-9) / 3 ;
    insertback1(MyList, random);
    }
}

void initlist(List **head) {
    *head = NULL;
}

void insertfront(List **head, int val) {
    List *newItem = (List *)malloc(sizeof(List));

    newItem->number = val;
    newItem->next = *head;
    *head = newItem;
}

void insertback1(List **head, int val) {
    List *newItem = (List *)malloc(sizeof(List));

    newItem->number = val;
    newItem->next = NULL;

    if (*head == NULL) {
        *head = newItem;
    } else {
        List *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newItem;
    }
}

void insertfront1(List **head, char *str) {
    List *newItem = (List *)malloc(sizeof(List));

    strncpy(newItem->name, str, sizeof(newItem->name) - 1);
    newItem->next = *head;
    *head = newItem;
}

void insertback(List **head, char *str) {
    List *newItem = (List *)malloc(sizeof(List));

    strncpy(newItem->name, str, sizeof(newItem->name) - 1);
    newItem->next = NULL;

    if (*head == NULL) {
        *head = newItem;
    } else {
        List *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newItem;
    }
}

int isempty(List **head) {
    return *head == NULL;
}

int length(List *head) {
    int count = 0;
    List *current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void destroyItem(List **head, List* node) {

    if (*head == node) {
        *head = node->next;
        free(node);
        return;
    }

    List *current = *head;
    while (current->next != NULL && current->next != node) {
        current = current->next;
    }

    if (current->next == NULL) {
        fprintf(stderr, "Узел не найден в списке\n");
        return;
    }

    current->next = node->next;
    free(node);
}

List *getitem(List* head, int n) {
    List *current = head;
    while (current != NULL && current->number != n) {
        current = current->next;
    }
    return current;
}

List *getitem1(List* head, char *str) {
    List *current = head;
    while (current != NULL && strcmp(current->name, str) != 0) {
        current = current->next;
    }
    return current;
}
