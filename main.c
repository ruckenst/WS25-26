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

void removeAt(struct node** head, int index) {
    if(*head == NULL) {
        printf("Error! List is empty.\n");
        return;
    }

    if(index < 0) {
        printf("Error! Index cannot be negative.\n");
        return;
    }

    struct node* current = *head;

    if(index == 0) {
        *head = (*head)->next;
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
        printf("Error! Index '%d' is out of bounds (max index = '%d')\n", index, currentIndex);
        return;
    }

    previous->next = current->next;
    freeNode(current);
}

int isEmpty(struct node* head) {
    return head == NULL;
}

int main()
{
    struct node* head = NULL;

    while(1) {
        int input;
        printf("Enter your value to be inserted: ");
        scanf("%d", &input);

        addBack(&head, createNode(input));

        if(!(input % 2)) {
            removeAt(&head, 0);
        }

        printList(head);
    }


    return 0;

    //struct node* head = NULL;
    printList(head); // NULL

    removeAt(&head, 0); // Error!
    printList(head); // NULL

    addSorted(&head, createNode(1));
    addSorted(&head, createNode(7));
    addSorted(&head, createNode(4));
    addSorted(&head, createNode(6));

    printList(head); // 1 -> 4 -> 6 -> 7 -> NULL

    removeAt(&head, 74); // Error!
    removeAt(&head, -35); // Error!
    removeAt(&head, 0); // 1 removed (4 -> 6 -> 7)
    removeAt(&head, 1); // 6 removed (4 -> 7)
    removeAt(&head, 1); // 7 removed (4)
    removeAt(&head, 0); // 4 removed (NULL)

    printList(head); // NULL

    return 0;

    //struct node* head = NULL;

    addSorted(&head, createNode(7));
    addSorted(&head, createNode(3));
    addSorted(&head, createNode(5));

    printList(head);

    for(int i = 0; i < 10; i++) {
        addBack(&head, createNode(i));
    }

    printList(head);

    for(int i = 0; i < 10; i++) {
        addFront(&head, createNode(i));
    }

    printList(head);
    freeList(head);

    head = createNode(123);

    printList(head);

    freeList(head);

    return 0;
}
