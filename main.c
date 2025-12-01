#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAY_SIZE 100

void fillArray(int myArr[], int size) {
    for(int i = 0; i < size; i++) {
        myArr[i] = size - i;
    }
}

void bubbleSortVisualgo(int myArr[], int size) {
    int swapped = 0;
    int sortedCount = 0;

    do {
        swapped = 0;
        for(int i = 0; i < size - sortedCount - 1; i++) {
            int temp = myArr[i];
            myArr[i] = myArr[i + 1];
            myArr[i + 1] = temp;

            swapped = 1;
        }

        sortedCount++;
    } while(swapped);
}

void bubbleSortArray(int myArr[], int size) {
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size /*- i*/ - 1; j++) {
            if(myArr[j] > myArr[j + 1]) {
                int temp = myArr[j];
                myArr[j] = myArr[j + 1];
                myArr[j + 1] = temp;
            }
        }
    }
}

void printArray(int myArr[], int size) {
    printf("[");
    for(int i = 0; i < size; i++) {
        printf("%d", myArr[i]);

        if(i < size - 1) {
            printf(", ");
        }
    }

    printf("]\n");
}

int main()
{
    int myArr[ARRAY_SIZE];

    fillArray(myArr, ARRAY_SIZE);

    printArray(myArr, ARRAY_SIZE);

    bubbleSortArray(myArr, ARRAY_SIZE);

    printArray(myArr, ARRAY_SIZE);

    return 0;
}
