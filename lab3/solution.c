#include <stdlib.h>
#include <string.h>
#include <stdio.h>

short remove_lines(int** matrix, int* rows_cnt, int* columns_cnt) {

    int n = *rows_cnt;
    int m = *columns_cnt;

    short MATRIX_CHANGED = 0;

    int* rows = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) { rows[i] = 0; }
    int* columns = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) { columns[i] = 0; }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] != 0) {
                rows[i]++;
                columns[j]++;
            }
        }
    }

    int rows_new = n;
    for (int i = 0; i < n; i++) {
        if (rows[i] == 1) {
            rows_new--;
            MATRIX_CHANGED = 1;
        }
    }

    int columns_new = m;
    for (int j = 0; j < m; j++) {
        if (columns[j] == 1) {
            columns_new--;
            MATRIX_CHANGED = 1;
        }
    }

    
    int** matrix_new = (int**)malloc(rows_new * sizeof(int*));
    for (int index = 0; index < n; ++index)
    {
        matrix_new[index] = (int*)malloc(columns_new * sizeof(int));
    }

    int i1 = 0, j1 = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (rows[i] != 1 && columns[j] != 1) {
                matrix_new[i1][j1] = matrix[i][j];
                j1++;
                i1 += j1 / columns_new;
                j1 %= columns_new;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i < rows_new && j < columns_new) {
                matrix[i][j] = matrix_new[i][j];
            } else {
                matrix[i][j] = -1;
            }
        }
    }

    

    for (int i = 0; i < rows_new; i++) {
        free(matrix_new[i]);
    }

    free(matrix_new);
    free(rows);
    free(columns);

    *rows_cnt = rows_new;
    *columns_cnt = columns_new;

    return MATRIX_CHANGED;
}
