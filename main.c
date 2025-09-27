#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 16
#define MAX_NAME_ARRAY_LENGTH (MAX_NAME_LENGTH + 1)

int main()
{
    char name[MAX_NAME_ARRAY_LENGTH];
    scanf("%16s", &name);

    for(int i = 0; i < MAX_NAME_ARRAY_LENGTH; i++) {
        printf("%c", name[i]);
    }


    int xPos = 0;
    int yPos = 0;

    while(1) {
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
                default:
                    printf("Oh no! You've entered garbage\n");
                    isInvalidInput = 1;
                    break;
            }
        } while(isInvalidInput);
    }

    return 0;
}
