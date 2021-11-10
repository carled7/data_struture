
#include "TAD_mkPoint.h"
#include <stdlib.h>

struct point {

    float x;
    float y;

};

void printPoint(POINT* p){
    printf("X: %f\n", p->x);
    printf("Y: %f\n", p->y);
}

POINT* createPoint(){

    POINT* p = malloc(sizeof(POINT));
    p->x = 1;
    p->y = 20;


    return p;
}
