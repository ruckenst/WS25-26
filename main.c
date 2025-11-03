#include <stdio.h>
#include <stdlib.h>

enum Gender {
    Female,
    Male,
    Diverse
};

struct Student {
    char        Name[33]; // 32 + \0
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

enum Month {
    January,
    February
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
    default:
        printf("Unknown Weekday\n");
        break;
    }
}

struct Coordinate {
    int X;
    int Y;
    int Z;
};

struct Player {
    int Lives;
    struct Coordinate Position;
};

void printCoordinate(struct Coordinate coord) {
    printf("{ x = %d, y = %d, z = %d }\n", coord.X, coord.Y, coord.Z);
}

int addIntegers(int integerA, int integerB) {
    int result = integerA + integerB;

    return result;
}

struct Coordinate addCoordinates(struct Coordinate coordA, struct Coordinate coordB) {
    struct Coordinate result =  {
        .X = coordA.X + coordB.X,
        .Y = coordA.Y + coordB.Y,
        .Z = coordA.Z + coordB.Z
    };

    return result;
}

void moveUp(struct Player* player) {
    //(*player).Position.Y++;
    player->Position.Y++;
}

void increment(int* i) {
    (*i)++;
}

int main() {
    struct Student myStudent = {
        .Name = "Sepp",
        .Gender = Male
    };

    int i = 123;

    increment(&i);

    // i = 124

    struct Player myPlayer = {
        .Lives = 5,
        .Position = {
            .X = 12,
            .Y = 43,
            .Z = 29
        }
    };

    printCoordinate(myPlayer.Position);
    moveUp(&myPlayer);
    printCoordinate(myPlayer.Position);


    struct Coordinate myCoordinate = {
        .X = 12,
        .Y = 43,
        .Z = 4
    };

    printCoordinate(myCoordinate);

    /*enum Month myMonth = Monday;

    if(myMonth == February) {
        printf("Hi!\n");
    } else {
        printf("Bye!\n");
    }*/

    printWeekday(Wednesday);

    printf("%d\n", Monday);
    printf("%d\n", Tuesday);
    printf("%d\n", Wednesday);
    printf("%d\n", Thursday);
    printf("%d\n", Friday);
    printf("%d\n", Saturday);
    printf("%d\n", Sunday);

    return 0;
}
