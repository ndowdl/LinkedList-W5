#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"

struct Node{
    int data;
    struct Node* next;
} Node;

typedef struct LinkedList{
    struct Node* head;
    struct Node* tail;
} LinkedList;

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL) {
        printf("Alokasi memori gagal");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void initLinkedList(LinkedList* list) {
    list->head = NULL;
    list->tail = NULL;
}

void insertFirst(LinkedList* list, int data) {
    struct Node* newNode = createNode(data);

    if(list->head == NULL) {
        list->head = newNode;
    } else {
        newNode->next = list->head;
    }
}

void insertLast(LinkedList* list, int data) {
    struct Node* newNode = createNode(data);

    if(list->tail == NULL) {
        list->tail = newNode;
    } else {
        newNode->next = NULL;
    }
}

void insertBetween(LinkedList* list, int position, int data) {

    if(list->head == NULL) {
        printf("LinkedList kosong");
        return 0;
    }

    struct Node* current = list->head;
    int count = 0;

    while(current != NULL && count < position) {
        current = current->next;
        count++;
    }

    if(current == NULL) {
        printf("Node dengan data %d tidak ditemukan", position);
    }

    struct Node* newNode = createNode(data);
    newNode->next = current->next;
}

void deleteFirst(LinkedList* list) {
    if(list->head == NULL) {
        printf("LinkedList kosong");
        return 0;
    }

    struct Node* temp = list->head;
    list->head = list->head->next;

    if(list->head == NULL) {
        list->tail = NULL;
    }

    free(temp);
}

void deleteLast(LinkedList* list) {
    if(list->head == list->tail) {
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
        return 0;
    }

    struct Node* current = list->head;
    while(current->next != list->tail) {
        current = current->next;
    }

    free(list->tail);
    list->tail = current;
    list->tail->next = NULL;
}

void deleteBetween(LinkedList* list) {
    if(list->head->next != NULL) {
        free(list->head->next);
    }
}

void deleteAll(LinkedList* list) {
    if(list->head == NULL) {
        printf("LinkedList kosong");
        return 0;
    }

    struct Node* current = list->head;

    while(current != NULL) {
        current = current->next;
        free(current);
    }

    list->head = NULL;
    list->tail = NULL;
}

void printList(LinkedList* list) {
    struct Node* current = list->head;
    while(current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
}