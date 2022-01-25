#include "header.h"

typedef struct
{
    int userTableSize;
    int gameTableSize;
    int filledPointAmount;
    int limit;
} difficulty;

const difficulty diff[3] = {{8, 5, 15, 3}, {15, 10, 60, 5}, {23, 15, 105, 8}};

int **userTableGenerator(int);

void createTable(int ***userTable, int ***gameTable, int d)
{
    int i, j;
    int x, y;
    int tableSize = diff[d].gameTableSize;
    int blankCount = diff[d].filledPointAmount;
    int lim = diff[d].limit;

    *userTable = userTableGenerator(d);

    for (i = 0; i < diff[d].userTableSize; ++i)
    {
        for (j = 0; j < diff[d].userTableSize; ++j)
        {
        }
    }

    for (i = 0; i < blankCount; ++i)
    {
        do
        {
            x = rand() % tableSize + lim;
            y = rand() % tableSize + lim;
        } while ((*userTable)[x][y] == 1); // if matrix already has 1 at that coordinate

        (*userTable)[x][y] = 1;
    }
}

void printTable(int **table, int d)
{
    int i, j;
    int userTS = diff[d].userTableSize;
    int gameTS = diff[d].gameTableSize;
    int lim = diff[d].limit;

    printf("\n\n\t ");
    printf("\n\t%c%c", 201, 205);
    for (i = 0; i < userTS; ++i)
        printf("%c%c%c", 205, 205, 205);

    for (i = 0; i < userTS; ++i)
    {
        printf("\n\t%c ", 186);

        for (j = 0; j < userTS; ++j)
        {
            if (table[i][j] == -1)
                printf("%c%c%c", 177, 177, 177);
            else if (table[i][j] == 0)
                printf("   ");
            else
                printf("%c%c%c", 219, 219, 219);
        }
        if (i >= lim)
            printf(" %1x", i - lim);
    }
    printf("\n\t");
    for (i = 0; i <= lim; ++i)
        printf("   ");
    for (i = 0; i < gameTS; ++i)
        printf("%1x  ", i);
}

int **userTableGenerator(int d)
{
    int **matrix;
    int i, j;
    int size = diff[d].userTableSize;
    int tableSize = diff[d].gameTableSize;

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

void freeUserTable(int **matrix, int d)
{
    int i;
    int size = diff[d].userTableSize;
    for (i = 0; i < size; ++i)
        free(matrix[i]);
    free(matrix);
}

void freeGameTable(int **matrix, int d)
{
    int i;
    int size = diff[d].gameTableSize;
    for (i = 0; i < size; ++i)
        free(matrix[i]);
    free(matrix);
}