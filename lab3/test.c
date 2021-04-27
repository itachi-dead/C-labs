#include "solution.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>




int main(void) {

    int n = 3, m = 3;

    int **matrix = (int **)malloc(n * sizeof(int*));
    for(int i = 0; i < n; i++) matrix[i] = (int *)malloc(m * sizeof(int));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = 0;
        }
    }

    matrix[1][1] = 1;

    short updated = remove_lines(matrix, &n, &m);

    
    assert(updated > 0);
    assert(n == 2);
    assert(m == 2);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            assert(matrix[i][j] == 0);
        }
    }

    
    
    printf("Tests OK");
}