#include <stdio.h>
#include <stdlib.h>

int times = 5;

void printTimes(char text[]) {
    for(int i = 0; i < times; i++) {
        printf("%s\n", text);
    }
}

void incrementTimes() {
    times++;
}

int isValidYear(int year) {
    /*if(year >= 1900 && year <= 2100) {
        return 1;
    }

    return 0;*/

    return year >= 1900 && year <= 2100;
}

int isValidMonth(int month) {
    return month >= 1 && month <= 12;
}

int isLeapYear(int year) {
    return 1;
}

int isValidDay(int day, int month, int year) {
    if(day <= 0) {
        return 0;
    }

    return 1;
}

int isValidDate(int day, int month, int year) {
    return isValidYear(year) && isValidMonth(month) && isValidDay(day, month, year);
}

int main() {
    printf("Is Valid? %d\n", isValidYear(1899));

    //double percentage = 12.32;
    //printf("Value: %d %d\n", something(percentage), somethingElse());

    int day = 30;
    int month = 9;
    int year = 2025;

    if(isValidDate(day, month, year)) {
        printf("Valid Date");
    } else {
        printf("Invalid Date");
    }

    return 0;
}