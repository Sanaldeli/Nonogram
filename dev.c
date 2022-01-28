#include "header.h"

extern const difficulty diff[3];
extern const int d;
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
void printGTable_dev(int **gameTable)
{
    int i, j;
    int size = diff[d].gameTableSize;
    for (i = 0; i < size; ++i)
    {
        for (j = 0; j < size; ++j)
            printf("%3d", gameTable[i][j]);
        printf("\n");
    }
}

void printUTable_dev(int **userTable, int **gameTable)
{
    int i, j;
    int GTSize = diff[d].gameTableSize;
    int UTSize = diff[d].userTableSize;
    int lim = diff[d].limit;
    printf("\n\n<<Dev>>\n\n");

    for (i = 0; i < lim; ++i)
    {
        for (j = 0; j < lim; ++j)
            printf("   ");
        printf("  ");
        for (; j < UTSize; ++j)
            printf("%3d", userTable[i][j]);
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
            printf("%3d", userTable[i + lim][j]);

        printf(" |");

        for (j = 0; j < GTSize; ++j)
            printf("%3d", gameTable[i][j]);

        printf("\n");
    }
} //*/
