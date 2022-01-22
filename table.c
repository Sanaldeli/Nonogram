#include "header.h"

void createTable(int difficulty)
{
    int tableSize = TABLE_SIZE(difficulty);
}

int **tableMatrix(int difficulty)
{
    int **matrix;
    int i;
    int tableSize[3] = {8, 15, 23};
    int size = tableSize[difficulty];

    matrix = (int **)malloc(size * sizeof(int *));
    if (matrix == NULL)
        FAIL("Malloc");
    for (i = 0; i < size; ++i)
    {
        matrix[i] = (int *)malloc(size);
        if (matrix[i] == NULL)
            FAIL("Malloc");
    }
}

void freeTableMatrix(int **matrix, int size)
{
    int i;
    for (i = 0; i < size; ++i)
        free(matrix[i]);
    free(matrix);
}