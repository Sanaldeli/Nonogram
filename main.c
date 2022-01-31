#include "header.h"

extern gameTable createTable(difficultyInfo diff);
extern void printTable(gameTable table);
extern void printUTable_dev(gameTable table);
extern void printGTable_dev(gameTable table);
extern void freeTable(gameTable table);

const difficultyInfo diff[3] = {{8, 5, 15, 3}, {15, 10, 60, 5}, {23, 15, 105, 8}};
gameTable table;

int main()
{
    int difficulty;
    srand(time(NULL));
    system("CLS");

    printf("\t###########################\n");
    printf("\t### WELCOME TO NONOGRAM ###\n");
    printf("\t###########################\n");
    printf("\t   >> by Anil Karasah <<   \n\n");

    printf("Nonogram is a logic puzzle game. Cells in a\n");
    printf("grid must be colored or left blank according\n");
    printf("to numbers at the side of the grid.\n\n");
    system("PAUSE");

    do
    {
        printf("Please select which difficulty you would like to play!\n");
        printf("0: Easy         (5x5 grid)\n");
        printf("1: Intermediate (10x10 grid)\n");
        printf("2: Hard         (15x15 grid)\n");
        printf("\n\t> ");
        scanf("%d", &difficulty);
        system("CLS");
    } while (difficulty < 0 || difficulty > 2);

    table = createTable(diff[difficulty]);
    //  printTable(userTable, difficulty);
    printf("\n\n");
    printUTable_dev(table);
    printf("\n");
    printGTable_dev(table);

    freeTable(table);

    printf("\n\n\t>> PROGRAM SUCCESSFULLY TERMINATED <<\n");

    return 0;
}
