#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    return a / b;
}

enum Gender {
    Female,
    Male,
    Diverse
};

enum Grade {
    Ungraded,
    Excellent,
    Good,
    Ok,
    Poor,
    Failed
};

struct Lecture {
    char       Name[33]; // 32 + \0
    enum Grade Grade;
};

struct Student {
    char           Name[33]; // 32 + \0
    struct Lecture Lectures[10];
    int            NumberOfLectures;
    enum Gender    Gender;
};

void addLectureToStudent(struct Student* student,
                         char* lectureName,
                         enum Grade grade) {
    if(student->NumberOfLectures >= 10) {
        printf("The student has reached their maximum number of lectures!\n");
        return;
    }

    struct Lecture newLecture = {
        .Grade = grade
    };
    strcpy(newLecture.Name, lectureName);

    student->Lectures[student->NumberOfLectures] = newLecture;
    student->NumberOfLectures++;
}

int main()
{
    struct Student myStudent = {
        .Name = "Sepp",
        .Gender = Male,
        .NumberOfLectures = 1,
        .Lectures = {
            {
                .Name = "Prozedurale Sprachen",
                .Grade = Excellent
            }
        }
    };

    addLectureToStudent(&myStudent,
                        "Grundlagen der Informatik",
                        Poor);

    return 0;

    /*
    int valueA, valueB;
    int option;
    int (*operations[])(int, int) = { &add, &subtract, &multiply, &divide };

    printf("Enter value a: ");
    scanf("%d", &valueA);

    printf("Enter value b: ");
    scanf("%d", &valueB);

    printf("Enter your option (0 = Add, 1 = Subtract, 2 = Multiply, 3 = Divide): ");
    scanf("%d", &option);

    int result = (*operations[option])(valueA, valueB);
    printf("Result: %d\n", result);
    return 0;
    */
}
