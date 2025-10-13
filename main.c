#include <stdio.h>
#include <stdlib.h>

void printValue(int value) {
    printf("%d\n", value);
}

void printReference(int* reference) {
    printf("%d\n", *reference);
}

void printArray(int array[], int arrayLength) {
    for(int i = 0; i < arrayLength; i++) {
        printf("%d\n", array[i]);
    }
}

void printWorld(int lengthX, int lengthY, char world[lengthX][lengthY]) {
    for(int y = 0; y < lengthY; y++) {
        for(int x = 0; x < lengthX; x++) {
            printf("%c ", world[x][y]);
        }

        printf("\n");
    }
}

int main()
{
    char world[5][5];

    for(int y = 0; y < 5; y++) {
        for(int x = 0; x < 5; x++) {
            world[x][y] = ' ';
        }
    }

    world[4][2] = 'x';
    world[1][4] = 'P';
    world[0][0] = '~';
    world[1][0] = '~';
    world[0][1] = '~';
    world[3][3] = 'w';
    world[3][4] = 'w';
    world[3][2] = 'w';
    world[4][3] = 'w';
    world[2][1] = ':';
    world[2][0] = '.';

    printWorld(5, 5, world);

    return 0;

    int myInt = 123;
    printValue(myInt);
    printReference(&myInt);

    int numberOfArrayElements;
    printf("Enter the number of elements: ");
    scanf("%d", &numberOfArrayElements);

    int myArr[numberOfArrayElements];

    for(int i = 0; i < numberOfArrayElements; i++) {
        printf("Enter the value for position '%d': ", i + 1);
        scanf("%d", &myArr[i]);
    }

    printArray(myArr, numberOfArrayElements);
    return 0;
}
