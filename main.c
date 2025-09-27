#include <stdio.h>
#include <stdlib.h>

#define MAX_NAME_LENGTH 16
#define MAX_NAME_ARRAY_LENGTH (MAX_NAME_LENGTH + 1)

int spellString(char string[], int stringLength);
int move(char direction, int* xPos, int* yPos);
void incrementByReference(int* i);
int incrementByValue(int i);
void A();
void B();

int main()
{
    A();
    B();

    char name[MAX_NAME_ARRAY_LENGTH];
    scanf("%16s", &name);

    spellString(name, MAX_NAME_ARRAY_LENGTH);

    int xPos = 0;
    int yPos = 0;

    while(1)
    {
        printf("x: %d, y: %d\n", xPos, yPos);

        int isInvalidInput;
        do
        {
            char direction;
            scanf(" %c", &direction);

            isInvalidInput = move(direction, &xPos, &yPos);
        }
        while(isInvalidInput);
    }

    return 0;
}

int spellString(char string[], int stringLength)
{
    for(int charIndex = 0; charIndex < stringLength; charIndex++)
    {
        if(string[charIndex] == '\0') {
            return charIndex;
        }

        printf("%c\n", string[charIndex]);
    }

    return stringLength;
}

int move(char direction, int* xPos, int* yPos)
{
    switch(direction)
    {
        case 'W':
        case 'w':
            (*yPos)++;
            break;
        case 'A':
        case 'a':
            (*xPos)--;
            break;
        case 'S':
        case 's':
            (*yPos)--;
            break;
        case 'D':
        case 'd':
            (*xPos)++;
            break;
        default:
            printf("Oh no! You've entered garbage\n");
            return 1;
    }

    return 0;
}

void incrementByReference(int* i) {
    (*i)++;
    //*i = *i + 1;
    //*i += 1;
}

int incrementByValue(int i) {
    i++;

    return i;
}

void A() {
    B();
    printf("A\n");
}

void B() {
    printf("B\n");
}
