#include <stdio.h>
#include <stdlib.h>

void increment(int* value);
int isValidDate(int day, int month, int year);
int isValidYear(int year);
int isValidMonth(int month);
int isValidDay(int day);

int main() {
    int i = 123;
    int day = 30;
    int month = 9;
    int year = 2025;

    if(isValidDate(day, month, year)) {
        printf("TRUE\n");
    } else {
        printf("FALSE\n");
    }

    increment(&i);
    printf("%d\n", i);
}

void increment(int* value) {
    *value += 1;
}

int isValidDate(int day, int month, int year) {
    printf("isValidDate\n");
    return isValidDay(day) && isValidMonth(month) && isValidYear(year);
}

int isValidYear(int year) {
    printf("isValidYear\n");
    return year >= 1900 && year <= 2100;
}

int isValidMonth(int month) {
    /*if(month >= 1 && month <= 12) {
        return 1;
    }

    return 0;*/

    printf("isValidMonth\n");
    return month >= 1 && month <= 12;
}

int isValidDay(int day) {
    printf("isValidDay\n");
    return 1;
}