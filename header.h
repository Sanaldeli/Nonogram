#ifndef HEADER_H_
#define HEADER_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define FAIL(x)                         \
    {                                   \
        printf("\n\t>> %s fail <<", x); \
        exit(-1);                       \
    }

#endif