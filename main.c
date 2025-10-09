#include <stdio.h>
#include <stdlib.h>

void increment(int* x) {
    (*x)++;
}

int* createIntegerVariable(int* myInt) {
    *myInt = 123;
    return myInt;
}

int max(int x, int y) {
    if(x > y) {
        return x;
    }

    return y;
}

int* maxPointer(int* x, int* y) {
    if(*x > *y) {
        return x;
    }

    return y;
}

void maxDoublePointer(int* x, int* y, int** target) {
    if(*x > *y) {
        *target = x;
    }

    *target = y;
}

int main() {
    int y = 124;
    int x = 123;

    int m = max(x, y);

    printf("x: %d\n", x);
    printf("y: %d\n", y);
    printf("max (m): %d\n", m);

    int* mp = maxPointer(&x, &y);
    (*mp)++;

    printf("x: %d\n", x);
    printf("y: %d\n", y);
    printf("max (mp): %d\n", *mp);

    int* mpp = &x;

    printf("x: %d\n", x);
    printf("y: %d\n", y);
    printf("mpp - original: %d\n", *mpp);

    maxDoublePointer(&x, &y, &mpp);

    printf("x: %d\n", x);
    printf("y: %d\n", y);
    printf("mpp: %d\n", *mpp);

    int myInt = 5;
    int* myOtherInt = createIntegerVariable(&myInt);
    int* myOtherOtherInt = myOtherInt;

    printf("%d\n", myInt);
    printf("%d\n", *myOtherInt);
    printf("%d\n", *myOtherOtherInt);

    printf("%d\n", &myInt);
    printf("%d\n", myOtherInt);
    printf("%d\n", myOtherOtherInt);

    printf("%d\n", &myInt);
    printf("%d\n", &myOtherInt);
    printf("%d\n", &myOtherOtherInt);

    int** myDoubleOther = &myOtherInt;
    printf("%d\n", myDoubleOther);
    printf("%d\n", *myDoubleOther);
    printf("%d\n", **myDoubleOther);
    return 0;
}
