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
    int filledBoxAmount;
    int limit;
} difficultyInfo;

typedef struct
{
    int **game;
    int **user;
    difficultyInfo difficulty;
} gameTable;

// ASCII characters for drawing the game table
#define TransparentBox 178
#define SolidBox 219
// line characters
#define hor_line 186
#define TR_corner 187
#define BR_corner 188
#define BL_corner 200
#define TL_corner 201
#define ver_line 205

#endif
