#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "mylib.h"

#define MAX_STRINGS_AMOUNT 10

#define MAX_STRING_LENGTH 80

letters get_info(char str[MAX_STRINGS_AMOUNT][MAX_STRING_LENGTH])
{
    letters temp;
    temp.a_amount = 0;
    temp.e_amount = 0;
    temp.i_amount = 0;
    temp.o_amount = 0;
    temp.u_amount = 0;
    temp.y_amount = 0;
    
    for (int i = 0; i < MAX_STRINGS_AMOUNT; i++) {
        for (int j = 0; j < strlen(str[i]); j++) {
            switch (str[i][j])
            {
            case 'A':
                temp.a_amount++;
                break;

            case 'a':
                temp.a_amount++;
                break;

            case 'E':
                temp.e_amount++;
                break;

            case 'e':
                temp.e_amount++;
                break;

            case 'I':
                temp.i_amount++;
                break;

            case 'i':
                temp.i_amount++;
                break;

            case 'O':
                temp.o_amount++;
                break;

            case 'o':
                temp.o_amount++;
                break;

            case 'U':
                temp.u_amount++;
                break;

            case 'u':
                temp.u_amount++;
                break;

            case 'Y':
                temp.y_amount++;
                break;

            case 'y':
                temp.y_amount++;
                break;
            }
        }
    }
    return temp;
}

void diagram(letters temp)
{
    printf("\n");
    printf("a - ");
    for (int i = 0; i < temp.a_amount; i++)
        printf("+");
    printf("\ne - ");
    for (int i = 0; i < temp.e_amount; i++)
        printf("+");
    printf("\ni - ");
    for (int i = 0; i < temp.i_amount; i++)
        printf("+");
    printf("\no - ");
    for (int i = 0; i < temp.o_amount; i++)
        printf("+");
    printf("\nu - ");
    for (int i = 0; i < temp.u_amount; i++)
        printf("+");
    printf("\ny - ");
    for (int i = 0; i < temp.y_amount; i++)
        printf("+");
}