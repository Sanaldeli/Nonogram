#include "header.h"

void printTable_dev(gameTable table)
{
    int i, j;

    printf("\n\t<<DEV>>\n\n");

    printf("GAMETABLE\n");
    for (i = 0; i < table.difficulty.gameTableSize; ++i)
    {
        for (j = 0; j < table.difficulty.gameTableSize; ++j)
            if (table.game[i][j])
                printf("  %d", (table.game)[i][j]);
            else
                printf("   ");
        printf("\n");
    }

    printf("\nUSERTABLE\n");
    for (i = 0; i < table.difficulty.userTableSize; ++i)
    {
        for (j = 0; j < table.difficulty.userTableSize; ++j)
            // if (table.user[i][j])
            printf("  %d", (table.user)[i][j]);
        // else
        // printf("   ");
        printf("\n");
    }
}
