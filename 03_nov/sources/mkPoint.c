#include <stdio.h>
#include <stdlib.h>
#include "../headers/mkPoint.h"

typedef struct point
{
    float x, y;
} POINT;

POINT createPoint (float x, float y){
    POINT p;

    p.x = x;
    p.y = y;

    return p;
}

void accessPoint (POINT p, float* x, float* y){

    p.x = *x;
    p.y = *y;

}

void freePoint (){
    printf("free function \n");
}
