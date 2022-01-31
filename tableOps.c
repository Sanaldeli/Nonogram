#include "header.h"

int **allocateTable(int tableSize);
void horizontalCounts(gameTable table);

gameTable createTable(difficultyInfo difficulty)
{
    int i, j;
    int x, y;
    gameTable result;

    result.user = allocateTable(difficulty.userTableSize);
    result.game = allocateTable(difficulty.gameTableSize);

    for (i = 0; i < difficulty.filledPointAmount; ++i)
    {
        do
        {
            x = rand() % difficulty.gameTableSize;
            y = rand() % difficulty.gameTableSize;
        } while ((result.game)[x][y] == 1); // if matrix already has 1 at that coordinate

        (result.game)[x][y] = 1;
    }

    horizontalCounts(result);

    result.difficulty = difficulty;

    return result;
}

void printTable(gameTable table)
{
    int i, j;
    int userTS = table.difficulty.userTableSize;
    int gameTS = table.difficulty.gameTableSize;
    int limit = table.difficulty.limit;

    printf("\n\n\t ");
    printf("\n\t%c%c", 201, 205);
    for (i = 0; i < userTS; ++i)
        printf("%c%c%c", 205, 205, 205);

    for (i = 0; i < userTS; ++i)
    {
        printf("\n\t%c ", 186);

        for (j = 0; j < userTS; ++j)
        {
            if ((table.user)[i][j] == -1)
                printf("%c%c%c", 177, 177, 177);
            else if ((table.user)[i][j] == 0)
                printf("   ");
            else
                printf("%c%c%c", 219, 219, 219);
        }
        if (i >= limit)
            printf(" %1x", i - limit);
    }
    printf("\n\t");
    for (i = 0; i <= limit; ++i)
        printf("   ");
    for (i = 0; i < gameTS; ++i)
        printf("%1x  ", i);
}

int **allocateTable(int size)
{
    int **matrix;
    int i, j;

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

// int **gameTableGenerator(difficultyInfo difficulty)
// {
//     int **matrix;
//     int i, j;
//     int size = difficulty.gameTableSize;

//     matrix = (int **)malloc(size * sizeof(int *));
//     if (matrix == NULL)
//         FAIL("Mallocation");
//     for (i = 0; i < size; ++i)
//     {
//         matrix[i] = (int *)calloc(size, sizeof(int));
//         if (matrix[i] == NULL)
//             FAIL("Mallocation");
//     }

//     return matrix;
// }

void horizontalCounts(gameTable table)
{
    int i, j, k;
    int limit = table.difficulty.limit;
    int size = table.difficulty.gameTableSize;
    int counters[8];
    bool firstBoxFlag;

    for (i = 0; i < size; ++i)
    {
        // operations for i'th row of the table
        for (j = 0; j < limit; ++j)
            counters[j] = 0;

        k = limit;
        firstBoxFlag = false;
        for (j = size - 1; j >= 0;)
        {
            if (!firstBoxFlag && (table.game)[i][j])
            {
                firstBoxFlag = true;
                --k;
            }

            while ((table.game)[i][j])
            {
                (counters[k])++;
                --j;
            }

            firstBoxFlag = false;
        }

        for (j = limit - 1; j >= 0; --j)
        {
        }
    }
}

void freeTable(gameTable table)
{
    int i;

    for (i = 0; i < table.difficulty.gameTableSize; ++i)
        free((table.game)[i]);
    free(table.game);

    for (i = 0; i < table.difficulty.userTableSize; ++i)
        free((table.user)[i]);
    free(table.user);
}
