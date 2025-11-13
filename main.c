#include <stdio.h>
#include <stdlib.h>

struct Something {
    int age;
    char name[100];
};

int main()
{
    int i = 123;
    int* heapI = malloc(10 * sizeof(int));
    if(heapI == NULL) {
        printf("Oh no! Not enough memory :(\n");
        return 1;
    }

    for(int x = 0; x < 10; x++) {
        heapI[x] = x;
    }

    for(int x = 0; x < 10; x++) {
        printf("heapI = %d\n", heapI[x]);
    }

    free(heapI);
    return 0;
}
