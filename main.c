#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node* next;
};

void printNode(struct node* node) {
    printf("%d -> ", node->value);
}

struct node* initializeNode(int value) {
    struct node* newNode = malloc(sizeof(struct node));
    #ifdef DEBUG_PRINT
    printf("Node initialized (%d)\n", value);
    #endif

    newNode->value = value;
    newNode->next = NULL;

    return newNode;
};

void freeNode(struct node* node) {
    int value = node->value;
    free(node);

    #ifdef DEBUG_PRINT
    printf("Node freed (%d)\n", value);
    #endif
}

void printList(struct node* head) {
    struct node* current = head;

    while(current != NULL) {
        printNode(current);
        current = current->next;
    }

    printf("NULL\n");
}

void freeList(struct node* head) {
    struct node* current = head;

    while(current != NULL) {
        struct node* next = current->next;
        freeNode(current);
        current = next;
    }
}

void printListRecursive(struct node* head) {
    if(head == NULL) {
        printf("NULL\n");
        return;
    }

    printNode(head);
    printListRecursive(head->next);
}

void freeListRecursive(struct node* head) {
    if(head == NULL) {
        return;
    }

    struct node* next = head->next;
    freeNode(head);

    freeListRecursive(next);
}

void insertBack(struct node** head, struct node* newNode) {
    // Check if list is empty
    if(*head == NULL) {
        *head = newNode;
        return;
    }

    struct node* current = *head;

    // Go to the last valid element
    while(current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
}

void insertFront(struct node** head, struct node* newNode) {
    newNode->next = *head;
    *head = newNode;
}

void insertSorted(struct node** head, struct node* newNode) {
    // Check if list is empty
    if(*head == NULL) {
        *head = newNode;
        return;
    }

    struct node* previous = NULL;
    struct node* current = *head;

    // Go to the last valid element or the first bigger element
    while(current != NULL &&
          current->value < newNode->value) {
        previous = current;
        current = current->next;
    }

    if(previous == NULL) {
        insertFront(head, newNode);
        return;
    }

    previous->next = newNode;
    newNode->next = current;
}

void removeAt(struct node** head, int index) {
    if(*head == NULL) {
        printf("Error! The list is empty!\n");
        return;
    }

    if(index < 0) {
        printf("Error! Index cannot be negative!\n");
        return;
    }

    struct node* current = *head;
    if(index == 0) {
        *head = current->next;
        freeNode(current);
        return;
    }

    int currentIndex = 0;
    struct node* previous = NULL;
    while(current->next != NULL && currentIndex < index) {
        previous = current;
        current = current->next;
        currentIndex++;
    }

    if(currentIndex != index) {
        printf("Error! Index '%d' is out of bounds! (max index: '%d')\n", index, currentIndex);
        return;
    }

    previous->next = current->next;
    freeNode(current);
}

int main()
{
    struct node* head = NULL;
    printList(head); // NULL

    removeAt(&head, 0); // ERROR!

    insertBack(&head, initializeNode(7));
    insertBack(&head, initializeNode(4));
    insertBack(&head, initializeNode(5));
    insertBack(&head, initializeNode(6));
    printList(head); // 7 -> 4 -> 5 -> -> 6 NULL

    removeAt(&head, -12); // ERROR!
    removeAt(&head, 73); // ERROR!
    removeAt(&head, 0); // REMOVE 7 (4 -> 5 -> 6)
    removeAt(&head, 1); // REMOVE 5 (4 -> 6)
    removeAt(&head, 1); // REMOVE 6 (4)
    removeAt(&head, 0); // REMOVE 4
    printList(head); // NULL

    return 0;

    while(1) {
        int input;
        printf("Enter your number: ");
        scanf("%d", &input);

        insertBack(&head, initializeNode(input));
        if(!(input % 2)) {
            removeAt(&head, 0);
        }

        printList(head);
    }

    return 0;
}
