#include <stdio.h>
#include <stdlib.h>

int* createInteger(int* myInt) {
    *myInt = 567;
    return myInt;
}

int max(int x, int y) {
    if(x > y) {
        return x;
    }

    return y;
}

int* maxReference(int* x, int* y) {
    if(*x > *y) {
        return x;
    }

    return y;
}

void maxDoubleReference(int* x, int* y, int** target) {
    if(*x > *y) {
        *target = x;
    }

    *target = y;
}

int main()
{
    int x = 12;
    int y = 83;

    int maximum = max(x, y);
    printf("x: %d\n", x);
    printf("y: %d\n", y);
    printf("max: %d\n\n", maximum);

    int* maximumReference = maxReference(&x, &y);
    (*maximumReference)++;

    printf("x: %d\n", x);
    printf("y: %d\n", y);
    printf("max: %d\n\n", *maximumReference);

    maxDoubleReference(&x, &y, &maximumReference);
    (*maximumReference)++;

    printf("x: %d\n", x);
    printf("y: %d\n", y);
    printf("max: %d\n", *maximumReference);

    return 0;

    int myInt = 123;
    int* myOtherInt = createInteger(&myInt);
    int* myOtherOtherInt = myOtherInt;

    printf("%d\n", myInt);
    printf("%d\n", myOtherInt);
    printf("%d\n", myOtherOtherInt);

    printf("Addr. MyInt: %d\n", &myInt);
    printf("Addr. MyOtherInt: %d\n", &myOtherInt);
    printf("Addr. MyOtherOtherInt: %d\n", &myOtherOtherInt);

    int** doublePointer = &myOtherInt;
    printf("Val DoublePointer: %d\n", doublePointer);
    printf("Deref. DoublePointer: %d\n", *doublePointer);
    printf("Double Deref. DoublePointer: %d\n", **doublePointer);

    return 0;
}
