#include "header.h"

int **userTableGenerator();
int **gameTableGenerator();
void horizontalCounts(int **userTable, int **gameTable);

extern const difficulty diff[3];
extern const int d;

void createTable(int ***userTable, int ***gameTable)
{
    int i, j;
    int x, y;
    int gameTableSize = diff[d].gameTableSize;
    int userTableSize = diff[d].userTableSize;
    int blankCount = diff[d].filledPointAmount;
    int lim = diff[d].limit;

    *userTable = userTableGenerator(d);
    *gameTable = gameTableGenerator(d);

    /*
     for (i = 0; i < userTableSize; ++i)
    {
        for (j = 0; j < userTableSize; ++j)
        {
        }
    }
    //*/

    for (i = 0; i < blankCount; ++i)
    {
        do
        {
            x = rand() % gameTableSize;
            y = rand() % gameTableSize;
        } while ((*gameTable)[x][y] == 1); // if matrix already has 1 at that coordinate

        (*gameTable)[x][y] = 1;
    }

    horizontalCounts(*userTable, *gameTable);
}

void printTable(int **table)
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

int **userTableGenerator()
{
    int **matrix;
    int i, j;
    int size = diff[d].userTableSize;
    int tableSize = diff[d].gameTableSize;

    matrix = (int **)malloc(size * sizeof(int *));
    if (matrix == NULL)
        FAIL("Mallocation");
    for (i = 0; i < size; ++i)
    {
        matrix[i] = (int *)malloc(size * sizeof(int));
        if (matrix[i] == NULL)
            FAIL("Mallocation");

        for (j = 0; j < size; ++j)
            matrix[i][j] = -1;
    }

    return matrix;
}

int **gameTableGenerator()
{
    int **matrix;
    int i, j;
    int size = diff[d].gameTableSize;
    int tableSize = diff[d].gameTableSize;

    matrix = (int **)malloc(size * sizeof(int *));
    if (matrix == NULL)
        FAIL("Mallocation");
    for (i = 0; i < size; ++i)
    {
        matrix[i] = (int *)calloc(size, sizeof(int));
        if (matrix[i] == NULL)
            FAIL("Mallocation");
    }

    return matrix;
}

void horizontalCounts(int **userTable, int **gameTable)
{
    int i, j, k;
    int limit = diff[d].limit;
    int counters[10] = {0};
    int size = diff[d].gameTableSize;

    for (i = 0; i < size; ++i)
    {
        // operations for i'th row of the table
        for (j = 0; j < limit; ++j)
            counters[j] = 0;

        k = 0;
        for (j = 0; j < size; ++j)
        {
            while (gameTable[i][j])
            {
                counters[k]++;
                j++;
            }
            k++;
        }
        for (j = 0; j < limit; ++j)
            printf("%3d", counters[j]);
        printf("\n");

        for (j = limit - 1; j >= 0; --j)
        {
            if (counters[j])
                userTable[i + limit][j] = counters[limit - j - 1];
            else
                j++;
        }
    }
}

void freeUserTable(int **matrix)
{
    int i;
    int size = diff[d].userTableSize;
    for (i = 0; i < size; ++i)
        free(matrix[i]);
    free(matrix);
}

void freeGameTable(int **matrix)
{
    int i;
    int size = diff[d].gameTableSize;
    for (i = 0; i < size; ++i)
        free(matrix[i]);
    free(matrix);
}
