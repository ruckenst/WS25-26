#include <stdio.h>
#include <stdlib.h>

int power(int x, int y) {
    if(y == 0) {
        return 1;
    }

    return x * power(x, y - 1);
}

/*
void printFileStructure(char path[]) {
    if(!isDirectory(path)) {
        printf("Path: %s", path);
        return;
    }

    // Get all Files and Directories
    // subPaths = getDirectoryStructure(path);

    // go over each element
    printFileStructure(currentSubPath);
}
*/

void printTree(int currentDepth, int maxDepth) {
    if(currentDepth >= maxDepth) {
        return;
    }

    for(int i = 0; i < currentDepth; i++) {
        printf(" ");
    }

    printf("Depth: %d\n", currentDepth);

    printTree(currentDepth + 1, maxDepth);
    printTree(currentDepth + 1, maxDepth);
}

int add(int x, int y) {
    int result = x + y;

    return result;
}

void increment(int* x) {
    int derefX = *x;
    derefX++;
}

int main() {
    int x;
    int y;

    printf("x: ");
    scanf("%d", &x);

    printf("y: ");
    scanf("%d", &y);

    increment(&x);
    printf("%d + %d = %d\n", x, y, add(x, y));

    printTree(0, 4 );
    return 0;
}
