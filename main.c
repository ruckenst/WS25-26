#include <stdio.h>
#include <stdlib.h>

void A();
void B();
int spellString(char string[], int stringLength);

void increment(int* x) {
    (*x)++;
}

int main()
{
    int i = 123;

    increment(&i);

    printf("%d\n", i);

    char name[17];
    scanf("%16s", &name);

    int numberOfPrintedCharacters = spellString(name, 17);
    printf("%d\n", numberOfPrintedCharacters);

    return 0;
}

void A() {
    printf("A\n");
}

void B() {
    printf("B\n");
}

/*
void spellString(char string[], int stringLength){
    for(int currentIndex = 0; currentIndex < stringLength; currentIndex++) {
        if(string[currentIndex] == '\0') {
            return;
        }

        printf("%c\n", string[currentIndex]);
    }
}
*/

int spellString(char string[], int stringLength){
    for(int currentIndex = 0; currentIndex < stringLength; currentIndex++) {
        if(string[currentIndex] == '\0') {
            return currentIndex;
        }

        printf("%c\n", string[currentIndex]);
    }

    return stringLength;
}
