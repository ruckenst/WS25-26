#include <stdio.h>
#include <stdlib.h>

int main()
{
    int xPos = 0;
    int yPos = 0;

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
            printf("Oh no! You entered something stupid!\n");
            break;
    }

    printf("x: %d, y: %d\n", xPos, yPos);

    return 0;
}
