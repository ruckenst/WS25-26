#include <stdio.h>
#include <stdlib.h>

int main()
{
    char str[256];
    printf("Gib was ein: ");
    scanf("%s", str);

    int length;
    for(length = 0; str[length] != '\0'; length++);

    int i;
    for(int j = 4; str[j] != '\0'; j+=6) {
        for(i = length; i > j; i--) {
            str[i+1] = str[i];
            str[i] = 'X';
        }
    }

    printf("%s", str);
    return 0;
}
