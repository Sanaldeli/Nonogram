#include "header.h"

int **allocateTable(int size);
void adjacentCounter(gameTable table);

gameTable createTable(difficultyInfo difficulty)
{
    int i, j, x, y;
    gameTable result;

    result.user = allocateTable(difficulty.userTableSize);
    result.game = allocateTable(difficulty.gameTableSize);

    // for (i = 0; i < difficulty.userTableSize; ++i)
    //     for (j = 0; j < difficulty.userTableSize; ++j)
    //         (result.user)[i][j] = -2;

    for (i = difficulty.limit; i < difficulty.userTableSize; ++i)
        for (j = difficulty.limit; j < difficulty.userTableSize; ++j)
            (result.user)[i][j] = -2;

    for (i = 0; i < difficulty.filledBoxAmount; ++i)
    {
        do
        {
            x = rand() % difficulty.gameTableSize;
            y = rand() % difficulty.gameTableSize;
        } while ((result.game)[x][y] == 1); // if matrix already has 1 at that coordinate

        (result.game)[x][y] = 1;
    }

    result.difficulty = difficulty;
    adjacentCounter(result);

    return result;
}

void adjacentCounter(gameTable table)
{
    int i, j;
    int k_hor, k_ver;
    int limit = table.difficulty.limit;
    int size = table.difficulty.gameTableSize;

    for (i = 0; i < size; ++i)
    {
        // operations for i'th row and column of the table

        k_hor = k_ver = limit;
        for (j = size - 1; j >= 0; --j)
        {
            if ((table.game)[i][j])
            {
                --k_hor;
                while (j >= 0 && (table.game)[i][j])
                {
                    ((table.user)[limit + i][k_hor])++;
                    --j;
                }
            }
        }

        for (j = size - 1; j >= 0; --j)
        {
            if ((table.game)[j][i])
            {
                --k_ver;
                while (j >= 0 && (table.game)[j][i])
                {
                    ((table.user)[k_ver][limit + i])++;
                    --j;
                }
            }
        }
    }
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
