#ifndef HEADER_H_
#define HEADER_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define FAIL(x)                         \
    {                                   \
        printf("\n\t>> %s fail <<", x); \
        exit(-1);                       \
    }

typedef struct
{
    int userTableSize;
    int gameTableSize;
    int filledPointAmount;
    int limit;
} difficultyInfo;

typedef struct
{
    int **game;
    int **user;
    difficultyInfo difficulty;
} gameTable;

#endif
