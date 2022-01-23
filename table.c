#include "header.h"

const int tableSizeMatrix[3] = {8, 15, 23};
const int blankCountMatrix[3] = {15, 60, 105};
const int limits[3] = {3, 5, 8};

int **tableMatrix(int);

int **createTable(int difficulty)
{
    int i, j;
    int x, y;
    int tableSize = TABLE_SIZE(difficulty);
    int blankCount = blankCountMatrix[difficulty];
    int lim = limits[difficulty];
    int **table = tableMatrix(difficulty);

    for (i = 0; i < tableSizeMatrix[difficulty]; ++i)
    {
        for (j = 0; j < tableSizeMatrix[difficulty]; ++j)
        {
        }
    }

    for (i = 0; i < blankCount; ++i)
    {
        do
        {
            x = rand() % tableSize + lim;
            y = rand() % tableSize + lim;
        } while (table[x][y] == 1); // if matrix already has 1 at that coordinate

        table[x][y] = 1;
    }

    return table;
}

void printTable(int **table, int difficulty)
{
    int tableSize = tableSizeMatrix[difficulty];
    int i, j;
    int x = TABLE_SIZE(difficulty);

    printf("\n\n\t ");
    for (i = 0; i <= limits[difficulty]; ++i)
        printf("   ");
    for (i = 0; i < x; ++i)
        printf(" %1x ", i);
    printf("\n\t  %c%c", 201, 205);
    for (i = 0; i < tableSize; ++i)
        printf("%c%c%c", 205, 205, 205);

    for (i = 0; i < tableSize; ++i)
    {
        if (i < limits[difficulty])
            printf("\n\t  %c ", 186);
        else
            printf("\n\t%1x %c ", i - limits[difficulty], 186);

        for (j = 0; j < tableSize; ++j)
        {
            if (table[i][j] == -1)
                printf("%c%c%c", 177, 177, 177);
            else if (table[i][j] == 0)
                printf("   ");
            else
                printf("%c%c%c", 219, 219, 219);
        }
    }
}

int **tableMatrix(int difficulty)
{
    int **matrix;
    int i, j;
    int size = tableSizeMatrix[difficulty];
    int tableSize = TABLE_SIZE(difficulty);

    matrix = (int **)calloc(size, sizeof(int *));
    if (matrix == NULL)
        FAIL("Mallocation");
    for (i = 0; i < size; ++i)
    {
        matrix[i] = (int *)calloc(size, sizeof(int));
        if (matrix[i] == NULL)
            FAIL("Mallocation");

        for (j = 0; j < size; ++j)
            matrix[i][j] = -1;
    }

    return matrix;
}

void freeTableMatrix(int **matrix, int difficulty)
{
    int i;
    int size = tableSizeMatrix[difficulty];
    for (i = 0; i < size; ++i)
        free(matrix[i]);
    free(matrix);
}