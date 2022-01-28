#include "header.h"

extern void createTable(int ***userTable, int ***gameTable);
extern void printTable(int **table);
extern void freeTableMatrix(int **table);
extern void printUTable_dev(int **userTable, int **gameTable);
extern void printGTable_dev(int **gameTable);

const difficulty diff[3] = {{8, 5, 15, 3}, {15, 10, 60, 5}, {23, 15, 105, 8}};
int d; // stands for difficulty

int main()
{
    srand(time(NULL));
    int **userTable;
    int **gameTable;
    system("CLS");

    printf("\t###########################\n");
    printf("\t### WELCOME TO NONOGRAM ###\n");
    printf("\t###########################\n");
    printf("\t   >> by Anil Karasah <<   \n\n");

    printf("Nonogram is a logic puzzle game. Cells in a\n");
    printf("grid must be colored or left blank according\n");
    printf("to numbers at the side of the grid.\n\n");
    system("PAUSE");

    printf("Please select which difficulty you would like to play!\n");
    printf("0: Easy         (5x5 grid)\n");
    printf("1: Intermediate (10x10 grid)\n");
    printf("2: Hard         (15x15 grid)\n");
    printf("\n\t> ");
    scanf("%d", &d);

    system("CLS");

    createTable(&userTable, &gameTable);
    //  printTable(userTable, difficulty);
    printf("\n");
    printUTable_dev(userTable, gameTable);
    printf("\n");
    printGTable_dev(gameTable);

    freeUserTable(userTable);
    freeGameTable(gameTable);

    printf("\n\n\t>> PROGRAM SUCCESSFULLY TERMINATED <<\n");

    return 0;
}
