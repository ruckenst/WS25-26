#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node* next;
};

struct node* createNode(int value) {
    struct node* newNode = malloc(sizeof(struct node));
    #ifdef DEBUG_PRINT
    printf("Node Created (%d)\n", value);
    #endif

    newNode->value = value;
    newNode->next = NULL;

    return newNode;
};

void freeNode(struct node* node) {
    int value = node->value;

    free(node);
    #ifdef DEBUG_PRINT
    printf("Node Freed (%d)\n", value);
    #endif
}

void printNode(struct node* node) {
    printf("%d -> ", node->value);
}

void freeList(struct node* head) {
    struct node* current = head;

    while(current != NULL) {
        struct node* next = current->next;
        freeNode(current);

        current = next;
    }
}

void freeListRecursive(struct node* head) {
    if(head == NULL) {
        return;
    }

    struct node* next = head->next;
    freeNode(head);

    freeListRecursive(next);
}

void printList(struct node* head) {
    struct node* current = head;

    while(current != NULL) {
        printNode(current);
        current = current->next;
    }

    printf("NULL\n");
}

void printListRecursive(struct node* head) {
    if(head == NULL) {
        printf("NULL\n");
        return;
    }

    printNode(head);
    printListRecursive(head->next);
}

void addBack(struct node** head, struct node* newNode){
    // Check if list is empty
    if(*head == NULL) {
        *head = newNode;
        return;
    }

    // Get last valid element
    struct node* current = *head;
    while(current->next != NULL) {
        current = current->next;
    }

    current->next = newNode;
}

void addFront(struct node** head, struct node* newNode) {
    newNode->next = *head;
    *head = newNode;
}

void addSorted(struct node** head, struct node* newNode) {
    // Check if list is empty
    if(*head == NULL) {
        *head = newNode;
        return;
    }

    struct node* previous = NULL;
    struct node* current = *head;

    // Go over each element, until you reach one with a higher value
    while(current != NULL &&
          newNode->value > current->value) {
        previous = current;
        current = current->next;
    }

    // Check if the element needs to be inserted in the beginning
    if(previous == NULL) {
        addFront(head, newNode);
        return;
    }

    previous->next = newNode;
    newNode->next = current;
}

int main()
{
    struct node* head = NULL;

    addSorted(&head, createNode(7));
    addSorted(&head, createNode(3));
    addSorted(&head, createNode(5));

    printList(head);

    return 0;

    for(int i = 0; i < 10; i++) {
        addBack(&head, createNode(i));
    }

    printList(head);

    for(int i = 0; i < 10; i++) {
        addFront(&head, createNode(i));
    }

    printList(head);
    freeList(head);

    return 0;

    head = createNode(123);

    printList(head);
    printListRecursive(head);

    freeList(head);

    return 0;
}
