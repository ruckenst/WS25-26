#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x = 123;
    if(x == 234){
        printf("true\n");
    } else {
        printf("false\n");
    }

    float temperature;
    printf("Enter the current temperature in degree celsius: ");
    scanf("%f", &temperature);

    printf("The temperature is: %.1f Degree Celsius\n", temperature);


    if (temperature < 15) {
        printf("It is cold :(\n");
    }
    else if (temperature >= 25 && temperature < 33) {
        printf("It is warm :)\n");
    }
    else if (temperature >= 33) {
        printf("It is hot :'(\n");
    }

    return 0;
}
