#include <stdio.h>
#include <stdlib.h>

enum Gender {
    Female,
    Male,
    Diverse
};

struct Student {
    char Name[33]; // 32 + \0
    enum Gender Gender;
};






enum Weekday {
    Sunday,
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday
};

void printWeekday(enum Weekday day) {
    switch(day) {
    case Monday:
        printf("Monday\n");
        break;
    case Tuesday:
        printf("Tuesday\n");
        break;
    case Wednesday:
        printf("Wednesday\n");
        break;
    case Thursday:
        printf("Thursday\n");
        break;
    case Friday:
        printf("Friday\n");
        break;
    case Saturday:
        printf("Saturday\n");
        break;
    case Sunday:
        printf("Sunday\n");
        break;
    }
}

struct Coordinate {
    int X;
    int Y;
    int Z;
};

void printCoordinate(struct Coordinate coord) {
    printf("{ x = %d, y = %d, z = %d }\n", coord.X, coord.Y, coord.Z);
}

int addInteger(int integerA, int integerB) {
    int result = integerA + integerB;

    return result;
}

struct Coordinate addCoordinates(struct Coordinate coordA, struct Coordinate coordB) {
    struct Coordinate result = {
        .X = coordA.X + coordB.X,
        .Y = coordA.Y + coordB.Y,
        .Z = coordA.Z + coordB.Z
    };

    return result;
}

void increment(int* i) {
    (*i)++;
}

//increment(&i);

void moveUp(struct Coordinate* coord) {
    //(*coord).Y++;
    coord->Y++;
}

int main()
{
    int i = 123;
    struct Coordinate myCoord = {
        .X = 12,
        .Y = 53,
        .Z = 9
    };

    printCoordinate(myCoord);
    moveUp(&myCoord);
    printCoordinate(myCoord);

    printWeekday(Tuesday);

    printf("%d\n", Monday);
    printf("%d\n", Tuesday);
    printf("%d\n", Wednesday);
    printf("%d\n", Thursday);
    printf("%d\n", Friday);
    printf("%d\n", Saturday);
    printf("%d\n", Sunday);

    return 0;
}
