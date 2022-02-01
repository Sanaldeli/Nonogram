#include "header.h"

bool isGameOver(gameTable table);
void printTable(gameTable table);

void playGame(gameTable table)
{
    int opt, row, col;
    int limit = table.difficulty.limit;
    int tableSize = table.difficulty.gameTableSize;
    // Option 0: Mark as empty
    // Option 1: Mark as checked
    // Row and Col points to table's index

    do
    {
        system("CLS");
        printTable(table);
        printf("\n\n\tYou must enter 3 numbers. <Option Row Column>\n");
        printf("(Options: 0 for marking empty, 1 for marking checked, otherwise EXIT)\n\t\t> ");
        scanf("%d %x %x", &opt, &row, &col);

        if (opt > 1 || opt < 0)
            return;

        while ((row >= tableSize || row < 0) || (col >= tableSize || col < 0))
        {
            printf("Please re-enter the row and column. <Row Column>\n\t\t> ");
            scanf("%x %x", &row, &col);
        }

		if (opt)
			(table.user)[row + limit][col + limit] = -1;
		else
    		(table.user)[row + limit][col + limit] = 0;
    } while (!isGameOver(table));

    system("CLS");
    printf("\n\t>> YOU HAVE FINISHED THE PUZZLE <<\n\n");
    printTable(table);
}

bool isGameOver(gameTable table)
{
    int i, j;
    int size = table.difficulty.gameTableSize;
    int limit = table.difficulty.limit;

    for (i = 0; i < size; ++i)
        for (j = 0; j < size; ++j)
            if ((table.game)[i][j] != (table.user)[i + limit][j + limit] + 2)
                return false;

    return true;
}

void printTable(gameTable table)
{
    int i, j;
    int userTS = table.difficulty.userTableSize;
    int gameTS = table.difficulty.gameTableSize;
    int limit = table.difficulty.limit;
    char transparentHolder[4] = {TransparentBox, TransparentBox, TransparentBox};
    char solidHolder[4] = {SolidBox, SolidBox, SolidBox};
    char verticalLine[4] = {ver_line, ver_line, ver_line};

    printf("\t%c%c", TL_corner, ver_line);
    for (i = 0; i < userTS; ++i)
        printf("%s", verticalLine);
    printf("%c", TR_corner);

    for (i = 0; i < userTS; ++i)
    {
        printf("\n\t%c ", hor_line);

        for (j = 0; j < userTS; ++j)
        {
            if ((table.user)[i][j] == 0)
                printf("   ");
            else if ((table.user)[i][j] > 0)
                printf("%2d ", (table.user)[i][j]);
            else if ((table.user)[i][j] == -1)
                printf("%s", solidHolder);
            else
                printf("%s", transparentHolder);
        }
        printf("%c", hor_line);
        if (i >= limit)
            printf("%1X", i - limit);
    }
    printf("\n\t%c", BL_corner);
    for (i = 0; i < userTS; ++i)
        printf("%s", verticalLine);
    printf("%c%c\n\t", ver_line, BR_corner);
    for (i = 0; i <= limit; ++i)
        printf("   ");
    for (i = 0; i < gameTS; ++i)
        printf("%1X  ", i);
}
