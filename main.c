#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Something {
    int age;
    char name[7];
    double xy;
};

int main()
{
    while(1) {
        int* i = malloc(500);
        printf("allocated...\n");
        free(i);
    }

    int i = 123;
    int* heapI = malloc(10 * sizeof(int));
    if(heapI == NULL) {
        printf("Out of memory :(\n");
        return 1;
    }

    for(int x = 0; x < 10; x++) {
        heapI[x] = x;
    }

    for(int x = 0; x < 10; x++) {
        printf("heapI = %d\n", heapI[x]);
    }
}
