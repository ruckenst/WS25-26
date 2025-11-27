#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct employee {
    char firstname[33];
    char lastname[33];
    int id;
};

int main()
{
    struct employee* employees[10];
    for(int i = 0; i < 10; i++) {
        employees[i] = malloc(sizeof(struct employee));
        strcpy(employees[i]->firstname, "Test A");
        strcpy(employees[i]->lastname, "Test B");
        employees[i]->id = i + 1;
    }

    FILE* newFile = fopen("./files/Export.csv", "w");
    if(newFile == NULL) {
        printf("The file could not be opened!\n");
        return 1;
    }

    for(int i = 0; i < 10; i++) {
        fprintf(newFile, "%s,%s,%d\n",
                employees[i]->firstname,
                employees[i]->lastname,
                employees[i]->id);
    }

    while(1){}

    fclose(newFile);

    for(int i = 0; i < 10; i++) {
        free(employees[i]);
    }


    FILE* file = fopen("./files/Test.csv", "r");
    if(file == NULL) {
        printf("The file could not be opened!\n");
        return 1;
    }

    char line[65];
    while(fscanf(file, "%s64", &line) != EOF) {
        printf("line: %s\n", line);

        // CONVERT TO STRUCT
    }

    fclose(file);

    return 0;
}
