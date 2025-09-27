#include <stdio.h>
#include <stdlib.h>

int main()
{
    float temperature;
    printf("Please enter the temperature in degree celsius: ");
    scanf("%f", &temperature);

    printf("The temperature is %.1f degree celsius\n", temperature);

    if(temperature < 15) {
        printf("It is cold :(\n");
    } else {
        printf("It is warm :)\n");
    }

    /*
    int i = 123;
    int j = 234;

    printf("%d\n%d\n%d\n", &i, &j, );
    */
    return 0;
}
