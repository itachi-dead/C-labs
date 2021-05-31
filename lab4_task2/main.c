#include <stdio.h>
#include <stdlib.h>
#include "mylib.h"

#define STUDENTS_AMOUNT 27

#define MAX_STRING_LENGTH 80

int main()
{
    FILE* fin;
    FILE* fout;
    char** students = (char**)malloc(STUDENTS_AMOUNT * sizeof(char*));
    if(!students) {
        printf("out of memory");
        return 1;
    }
    for (int i = 0; i < STUDENTS_AMOUNT; i++) {
        students[i] = (char*)malloc(MAX_STRING_LENGTH * sizeof(char));
        if(!students[i]) {
            printf("out of memory");
            return 1;
    }   }
    if (!(fin = fopen("input.txt", "r"))) {
        printf("File can't be open");
        exit(1);
    }
    for (int i = 0; i < STUDENTS_AMOUNT; i++) {
        fgets(students[i], MAX_STRING_LENGTH, fin);
    }
    sort(students, 0);
    edit_names(students);
    if (!(fout = fopen("output.txt", "w"))) {
        printf("File can't be open");
        exit(1);
    }
    for (int i = 0; i < STUDENTS_AMOUNT; i++) {
        fputs(students[i], fout);
    }
    fclose(fout);
    fclose(fin);
    for (int i = 0; i < STUDENTS_AMOUNT; i++) {
        free(students[i]);
        students[i] = NULL;
    }
    free(students);
    students = NULL;
    return 0;
}