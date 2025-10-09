#include <stdio.h>
#include <stdlib.h>

void something(int i) {
    if(i <= 0) {
        return;
    }

    printf("Hi! %d\n", i);

    i--;
    something(i);
}

int power(int x, int y) {
    int result = 1;

    for(int i = 0; i < y; i++) {
        result *= x;
    }

    return result;
}

int powerRecursive(int x, int y) {
    if(y == 0) {
        return 1;
    }

    return x * powerRecursive(x, y - 1); // x * x^(y-1)
}

/*
void printFileStructure(char path[]) {
    if(isFile(path)) {
        printf("File: %s", path);
        return;
    }

    children = getChildPaths(path);

    for(GO OVER CHILDREN) {
        printFileStructure(children);
    }
}
*/

void printTree(int currentDepth, int maxDepth) {
    if(currentDepth >= maxDepth) {
        return;
    }

    for(int i = 0; i < currentDepth; i++) {
        printf("   ");
    }

    printf("File in depth: %d\n", currentDepth);

    printTree(currentDepth + 1, maxDepth);
    printTree(currentDepth + 1, maxDepth);
    printTree(currentDepth + 1, maxDepth);
}

int main()
{
    printTree(0, 10);

    printf("result: %d\n", power(2, 3));
    printf("result: %d\n", powerRecursive(2, 3));
    return 0;
}
