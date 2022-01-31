#include "header.h"

void printTable(gameTable table)
{
    int i, j;
    int userTS = table.difficulty.userTableSize;
    int gameTS = table.difficulty.gameTableSize;
    int limit = table.difficulty.limit;
    char transparentHolder[4] = {TransparentBox, TransparentBox, TransparentBox};
    char solidHolder[4] = {SolidBox, SolidBox, SolidBox};
    char verticalLine[4] = {ver_line, ver_line, ver_line};

    // system("CLS");
    printf("\n\n\t ");
    printf("\n\t%c%c", TL_corner, ver_line);
    for (i = 0; i < userTS; ++i)
        printf("%s", verticalLine);
    printf("%c", TR_corner);

    for (i = 0; i < userTS; ++i)
    {
        printf("\n\t%c ", hor_line);

        for (j = 0; j < userTS; ++j)
        {
            if ((table.user)[i][j] == -1)
                printf("%s", transparentHolder);
            else if ((table.user)[i][j] > 0)
                printf("%2d ", (table.user)[i][j]);
            else if ((table.user)[i][j] == -2)
                printf("%s", solidHolder);
            else
                printf("   ");
        }
        printf("%c", hor_line);
        if (i >= limit)
            printf("%1x", i - limit);
    }
    printf("\n\t%c", BL_corner);
    for (i = 0; i < userTS; ++i)
        printf("%s", verticalLine);
    printf("%c%c\n\t", ver_line, BR_corner);
    for (i = 0; i <= limit; ++i)
        printf("   ");
    for (i = 0; i < gameTS; ++i)
        printf("%1x  ", i);
}