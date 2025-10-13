#include <stdio.h>
#include <stdlib.h>

void printValue(int myInt) {
    printf("%d\n", myInt);
}

void printReference(int* myRef) {
    printf("%d\n", *myRef);
}

void printArray(int myArr[], int myArrSize) {
    for(int i = 0; i < myArrSize; i++) {
        printf("%d\n", myArr[i]);
    }
}

void printWorld(int worldSizeX, int worldSizeY, char world[worldSizeX][worldSizeY]) {
    for(int y = 0; y < worldSizeY; y++) {
        for(int x = 0; x < worldSizeX; x++) {
            printf("%c ", world[x][y]);
        }

        printf("\n");
    }
}

int main() {
    int worldSizeX = 5;
    int worldSizeY = 5;

    char world[worldSizeX][worldSizeY];

    for(int y = 0; y < worldSizeY; y++) {
        for(int x = 0; x < worldSizeX; x++) {
            world[x][y] = ' ';
        }
    }

    world[2][1] = 'x';
    world[0][1] = '~';
    world[0][0] = '~';
    world[0][2] = '~';
    world[1][1] = '~';
    world[3][2] = 'w';
    world[4][2] = 'w';
    world[4][3] = 'w';
    world[4][4] = 'w';

    printWorld(worldSizeX, worldSizeY, world);

    int myInt = 17;
    printValue(myInt);
    printReference(&myInt);

    int arrayElementCount;
    printf("Enter the number of elements: ");
    scanf("%d", &arrayElementCount);

    int myIntArray[arrayElementCount];

    for(int i = 0; i < arrayElementCount; i++) {
        printf("Enter the value of element '%d': ", i + 1);
        scanf("%d", &myIntArray[i]);
    }

    printArray(myIntArray, arrayElementCount);

    return 0;
}
