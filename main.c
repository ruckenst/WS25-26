#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node* next;
};

void printNode(struct node* node) {
    //printf("value: %d\n", node->value);
    //printf("next:  %d\n", node->next);

    printf("%d -> ", node->value);
}

struct node* initializeNode(int value) {
    struct node* newNode = malloc(sizeof(struct node));
    printf("Node initialized (%d)\n", value);

    newNode->value = value;
    newNode->next = NULL;

    return newNode;
};

void freeNode(struct node* node) {
    int value = node->value;
    free(node);
    printf("Node freed (%d)\n", value);
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

int main()
{
    struct node* head = NULL;
    printListRecursive(head);

    head = initializeNode(7);
    head->next = initializeNode(9);
    freeList(head);

    head = initializeNode(83);

    printList(head);
    freeListRecursive(head);
}
