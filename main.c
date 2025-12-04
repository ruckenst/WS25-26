#include <stdio.h>
#include <stdlib.h>

#define ARRAY_SIZE 100
#define MAX_VALUE 50

void printArray(int arr[], int size) {
    printf("[");
    for(int i = 0; i < size; i++) {
        printf("%d", arr[i]);

        if(i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void initializeArray(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        int factor = i * (i + size);
        int primedFactor = factor % 19 * (i + 13);
        int shiftedFactor = primedFactor  >> 3;

        arr[i] = shiftedFactor % MAX_VALUE;
    }
}

void bubbleSortArray(int arr[], int count) {
    for(int i = 0; i < count - 1; i++) {
        for(int j = 0; j < count /*- i*/ - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void bubbleSortArrayVisualgo(int arr[], int count) {
    int swapped = 0;
    int sortedCount = 0;

    do {
        swapped = 0;
        for(int i = 0; i < count - sortedCount - 1; i++) {
            if(arr[i] > arr[i + 1]) {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;

                swapped = 1;
            }
        }

        sortedCount++;
    }while(swapped);
}

int main()
{
    int arr[ARRAY_SIZE];
    initializeArray(arr, ARRAY_SIZE);
    printArray(arr, ARRAY_SIZE);

    bubbleSortArray(arr, ARRAY_SIZE);
    //bubbleSortArrayVisualgo(arr, ARRAY_SIZE);

    printArray(arr, ARRAY_SIZE);

    return 0;
}
