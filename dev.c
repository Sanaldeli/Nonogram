#include "header.h"

/*
void printUTable_dev(int **userTable, int **gameTable)
{
    int i, j;
    int size = diff[d].userTableSize;
    for (i = 0; i < size; ++i)
    {
        for (j = 0; j < size; ++j)
            printf("%3d", userTable[i][j]);
        printf("\n");
    }
}
//*/
void printGTable_dev(gameTable table)
{
    int i, j;
    int size = table.difficulty.gameTableSize;
    for (i = 0; i < size; ++i)
    {
        for (j = 0; j < size; ++j)
            printf("%3d", (table.game)[i][j]);
        printf("\n");
    }
}

void printUTable_dev(gameTable table)
{
    int i, j;
    int GTSize = table.difficulty.gameTableSize;
    int UTSize = table.difficulty.userTableSize;
    int lim = table.difficulty.limit;
    printf("\n\n<<Dev>>\n\n");

    for (i = 0; i < lim; ++i)
    {
        for (j = 0; j < lim; ++j)
            printf("   ");
        printf("  ");
        for (; j < UTSize; ++j)
            printf("%3d", (table.user)[i][j]);
        printf("\n");
    }

    for (i = 0; i < lim; ++i)
        printf("   ");
    printf("  ");
    for (; i < UTSize; ++i)
        printf("___");
    printf("\n");

    for (i = 0; i < GTSize; ++i)
    {
        for (j = 0; j < lim; ++j)
            printf("%3d", (table.user)[i + lim][j]);

        printf(" |");

        for (j = 0; j < GTSize; ++j)
            printf("%3d", (table.game)[i][j]);

        printf("\n");
    }
} //*/
