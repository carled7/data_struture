#include <stdlib.h>
#include <stdio.h>
#include "./headers/mkPoint.h"

typedef struct point
{
    float x;
    float y;
} POINT;

int main (){

    int x = 3, y = 2;
    POINT p;

    p = createPoint(x, y);
    freePoint();

    return 0;
}
