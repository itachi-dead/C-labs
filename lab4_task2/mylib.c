#include <stdlib.h>
#include <stdbool.h>
#include "mylib.h"

#define STUDENTS_AMOUNT 27

#define MAX_STRING_LENGTH 80

void q_sort(char** stud, int left, int right, int poz)
{
    int l = left, r = right;
    char* temp = NULL;
    char* root = stud[(l + r) / 2];
    do {
        while (stud[l][poz] < root[poz]) {
            l++;
        }
        while (stud[r][poz] > root[poz]) {
            r--;
        }
        if (l <= r) {
            temp = stud[l];
            stud[l] = stud[r];
            stud[r] = temp;
            ++l;
            --r;
        }
    } while (l < r);
    if (left < r) q_sort(stud, left, r, poz);
    if (right > l) q_sort(stud, l, right, poz);
}

void sort(char** stud, int poz)
{
    q_sort(stud, 0, STUDENTS_AMOUNT - 1, poz);
    int i, temp;
    bool isSort;
    while (poz != 5) {
        for (i = 0; i < STUDENTS_AMOUNT - 1; ++i) {
            isSort = false;
            temp = i;
            while (i < STUDENTS_AMOUNT - 1 && stud[i][poz] == stud[i + 1][poz]) {
                if (stud[i][0] < stud[i + 1][0])
                    break;
                isSort = true;
                i++;
            }
            if(isSort)
                q_sort(stud, temp, i, poz + 1);
        }
        poz++;
    }
}

void to_upper_case(char* name)
{
    for (int i = 0; i < str_length(name); i++) {
        if (name[i] != ' ')
            continue;
        while (name[i] == ' ')
            i++;
        if (name[i] > 90) {
            name[i] -= 32;
            break;
        }
    }
}

void edit_names(char** stud)
{
    for (int i = 0; i < STUDENTS_AMOUNT; i++) {
        to_upper_case(stud[i]);
    }
}

int str_length(char* str)
{
    int lenght = 0;
    while(str[lenght] != '\0')
        lenght++;
    return lenght;
}

bool str_compare(char* str1, char* str2)
{
    if(str_length(str1) != str_length(str2))
        return true;

    for(int i = 0; i < str_length(str1); i++) {
        if(str1[i] != str2[i])
            return true;
    }
    return false;
}