#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 32
#define MAX_NAME_ARRAY_LENGTH (MAX_NAME_LENGTH + 1)

int main()
{
    char name[MAX_NAME_ARRAY_LENGTH];
    scanf("%32s", &name);

    for(int i = 0; name[i] != '\0' && i < MAX_NAME_ARRAY_LENGTH; i++) {
        printf("%c", name[i]);
    }

    int xPos = 0;
    int yPos = 0;

    int isRunning = 1;

    while(isRunning) {
        printf("x: %d, y: %d\n", xPos, yPos);

        int isInvalidInput;
        do {
            char direction;
            scanf(" %c", &direction);

            isInvalidInput = 0;

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
                case 'X':
                case 'x':
                    isRunning = 0;
                    break;
                default:
                    printf("Oh no! You entered something stupid!\n");
                    isInvalidInput = 1;
                    break;
            }
        } while(isInvalidInput);
    }

    return 0;
}
