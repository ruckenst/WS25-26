#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t = 123;
    int isRunning = 1;

    for(int i = 0; i < 100; i++) {
        printf("%d\n", i);
    }

    int xPos = 0;
    int yPos = 0;

    while() {
        printf("x: %d, y: %d\n", xPos, yPos);

        char direction;
        scanf("%c", &direction);

        switch(direction) {
            case 'W':
            case 'w':
                yPos++;
                break;
            case 'A':
            case 'a':
                xPos--;
                break;
            case 'S':
            case 's':
                yPos--;
                break;
            case 'D':
            case 'd':
                xPos++;
                break;
            default:
                printf("Oh no! You've entered garbage\n");
                break;
        }
    }

    return 0;
}
