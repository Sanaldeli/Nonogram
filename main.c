#include "header.h"

extern void createTable(int);

int main()
{
    int difficulty;
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
    scanf("%d", &difficulty);

    createTable(difficulty);

    return 0;
}