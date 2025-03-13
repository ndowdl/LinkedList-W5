#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "LinkedList.c"

int main() {
    LinkedList list;
    initLinkedList(&list);

    insertFirst(&list, 7);
    printList(&list);

    insertLast(&list, 11);
    printList(&list);

    insertBetween(&list, 9);
    printList(&list);

    insertFirst(&list, 5);
    printList(&list);

    insertLast(&list, 13);
    printList(&list);

    deleteLast(&list);
    printList(&list);

    deleteBetween(&list);
    printList(&list);

    deleteFirst(&list);
    printList(&list);

    deleteAll(&list);
    printList(&list);
}