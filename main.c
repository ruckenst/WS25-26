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
    // Check for empty list
    if(*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    // Check if the first element needs to be removed
    if(index == 0) {
        struct node* nodeToRemove = *head;
        *head = (*head)->next;

        freeNode(nodeToRemove);
        return;
    }

    int currentIndex = 0;
    struct node* previous = NULL;
    struct node* current = *head;

    // Go to the last valid element or until the index is hit
    while(current->next != NULL && currentIndex < index) {
        previous = current;
        current = current->next;

        currentIndex++;
    }

    // Check if the index was hit
    if(currentIndex != index) {
        printf("Index was out of bounds!\n");
        return;
    }

    struct node* nodeToRemove = current;
    previous->next = current->next;
    freeNode(nodeToRemove);
}

int main()
{
    struct node* head = NULL;
    removeAt(&head, 0);
    printListRecursive(head);

    insertSorted(&head, initializeNode(7));
    insertSorted(&head, initializeNode(3));
    insertSorted(&head, initializeNode(5));

    removeAt(&head, 0);

    printListRecursive(head);

    return 0;

    for(int i = 0; i < 10; i++) {
        insertBack(&head, initializeNode(i));
    }

    printList(head);

    for(int i = 0; i < 10; i++) {
        insertFront(&head, initializeNode(i));
    }

    printList(head);
    freeList(head);

    return 0;
}
