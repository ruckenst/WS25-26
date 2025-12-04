#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node* next;
};

struct node* createNode(int value) {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->value = value;
    newNode->next = NULL;

    return newNode;
};

void insertFront(struct node** head, struct node* newNode) {
   newNode->next = *head;
   *head = newNode;
}

void printList(struct node* head) {
    struct node* current = head;

    while(current != NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }

    printf("NULL\n");
}

void freeList(struct node** head) {
    struct node* current = *head;

    while(current != NULL) {
        struct node* next = current->next;
        free(current);
        current = next;
    }

    *head = NULL; // Etwas sauberer, da kein Dangling Pointer
}

void swapNodeValues(struct node* nodeA, struct node* nodeB) {
    int temp = nodeA->value;
    nodeA->value = nodeB->value;
    nodeB->value = temp;
}

void bubbleSort(struct node* head){
    if(head == NULL) {
        return;
    }

    int swapped = 0;
    struct node* firstSorted = NULL;

    do {
        swapped = 0;

        struct node* current = head;
        struct node* next = current->next;

        while(next != firstSorted) {
            if(current->value > next->value) {
                swapNodeValues(current, next);
                swapped = 1;
            }

            current = current->next;
            next = next->next;
        }

        firstSorted = current;
    }while(swapped);
}

int main()
{
    struct node* head = NULL;

    insertFront(&head, createNode(4));
    insertFront(&head, createNode(2));
    insertFront(&head, createNode(6));
    insertFront(&head, createNode(3));
    insertFront(&head, createNode(5));
    insertFront(&head, createNode(3));

    printList(head);

    swapNodeValues(head, head->next->next->next);
    printList(head);

    bubbleSort(head);
    printList(head);

    freeList(&head);

    return 0;
}
