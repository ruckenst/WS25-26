#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node* next;
};

struct node* createNode(int value) {
    struct node* newNode = malloc(sizeof(struct node));
    printf("Node Created (%d)\n", value);

    newNode->value = value;
    newNode->next = NULL;

    return newNode;
};

void freeNode(struct node* node) {
    int value = node->value;

    free(node);
    printf("Node Freed (%d)\n", value);
}

void printNode(struct node* node) {
    //printf("value: %d\n", node->value);
    //printf("next:  %d\n", node->next);

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

int main()
{
    struct node* head = NULL;
    printList(head);

    head = createNode(12);
    head->next = createNode(27);
    freeList(head);

    head = createNode(123);

    printList(head);
    printListRecursive(head);

    freeList(head);

    return 0;
}
