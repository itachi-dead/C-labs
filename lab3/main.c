#define _CRT_SECURE_NO_WARNINGS

#include "solution.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void) {

    int n, m;

    scanf("%d %d", &n, &m);

    int N = n, M = m;

    int **matrix = (int **)malloc(n * sizeof(int*));
    for(int i = 0; i < n; i++) matrix[i] = (int *)malloc(m * sizeof(int));


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int iteration = 1;

    short MATRIX_CHANGED = 1;

    while (MATRIX_CHANGED)
    {
        printf("\nIteration %d\n\n", iteration++);
        MATRIX_CHANGED = remove_lines(matrix, &n, &m);

        printf("Matrix: %d %d\n", n, m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                printf("%d ", matrix[i][j]);
            }
            printf("\n");
        }

        if (n == 0 || m == 0) {
            break;
        }
    }

    for (int i = 0; i < N; i++) {
        free(matrix[i]);
    }
    free(matrix);  
   

}

