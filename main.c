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
        strcpy(employees[i]->firstname, "Name A");
        strcpy(employees[i]->lastname, "Name B");
        employees[i]->id = i;
    }

    FILE* newFile = fopen("./files/Export.csv", "w");
    if(newFile == NULL) {
        printf("File could not be opened!\n");
        return 1;
    }

    for(int i = 0; i < 10; i++) {
        fprintf(newFile, "%s,%s,%d\n",
                employees[i]->firstname,
                employees[i]->lastname,
                employees[i]->id);
    }

    fclose(newFile);

    for(int i = 0; i < 10; i++) {
        free(employees[i]);
    }

    FILE* file = fopen("./files/Test.csv", "r");
    if(file == NULL) {
        printf("File could not be opened!\n");
        return 1;
    }

    char line[65];
    while(fscanf(file, "%64s\n", &line) != EOF) {
        printf("%s\n", line);
    }

    fclose(file);

    return 0;
}
