#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
#include <Windows.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct Queue {
    Node* front;
    Node* rear;
} Queue;

void enqueue(Queue* queue, int value);
void dequeue(Queue* queue); 
int isEmpty(Queue* queue);
void printQueue(Queue* queue);
int getListSize(Queue* queue);

int main(void) {
    setlocale(LC_CTYPE, "RUS");

    char menu;
    int value = 0;
    Queue myQueue = {NULL, NULL};

    do {
        printf("\n--��������� ��� ������ � �������� �� ��������� ������--\n\n");
        printf("1) �������� ������� � �������\n");
        printf("2) ������� ������� �� �������\n");
        printf("3) �������� �� ������� ��������� � �������\n");
        printf("4) ������� ������ �������\n");
        printf("0) ����� �� ���������\n");
        menu = getch();
        system("cls");

        switch (menu) {
            case '1':
                printf("\n������� ��������(����� �����), ������� ������ �������� � �������: ");
                scanf("%d", &value);
                enqueue(&myQueue, value);
                system("cls");
                break;
            case '2':
                dequeue(&myQueue);
                getch();
                system("cls");
                break;
            case '3':
                if (isEmpty(&myQueue)) {
                    printf("\n������� �����.\n");
                } else {
                    printf("\n� ������� ���-�� ����\n������������ ��������:\n");
                    printQueue(&myQueue);
                }
                getch();
                system("cls");
                break;
            case '4':
                printf("\n������� ������ �������: %d\n", getListSize(&myQueue));
                getch();
                system("cls");
                break;
            case '0':
                return 0;
            default:
                printf("�� ������ �� �� �������\n");
                getch();
                system("cls");
                break;
        }
    } while (menu != '0');
}

void enqueue(Queue* queue, int value) {
    Node* tmp = (Node*)malloc(sizeof(Node));
    if (tmp == NULL) {
        printf("������ ��� ��������� ������\n");
        return;
    }
    tmp->value = value;
    tmp->next = NULL;
    if (isEmpty(queue)) {
        queue->front = tmp;
        queue->rear = tmp;
    } else {
        queue->rear->next = tmp;
        queue->rear = tmp;
    }
}

void dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("������� �����. �������� ����������.\n");
        return;
    }
    Node* tmp = queue->rear;
    queue->rear = tmp->next;
    free(tmp);
    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    printf("\n������� ������� ����� �� �������\n");
}

int isEmpty(Queue* queue) {
    return queue->front == NULL;
}

void printQueue(Queue* queue) {
    Node* current = queue->front;
    while (current != NULL) {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");
}

int getListSize(Queue* queue) {
    int size = 0;
    Node* current = queue->front;
    while (current != NULL) {
        size++;
        current = current->next;
    }
    return size;
}