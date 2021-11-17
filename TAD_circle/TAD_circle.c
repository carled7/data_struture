
#include "TAD_circle.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct point{

    float x;
    float y;

} POINT;

typedef struct circle{

    POINT* center;
    float radius;

} CIRCLE;

CIRCLE* createCircle(float rad, float cX, float cY){


    CIRCLE* c = malloc(sizeof(CIRCLE));
    c->center->x = cX;
    c->center->y = cY;
    c->radius = rad;

    if(c){
        printf("\nThe circle has been defined");
    }

    return c;
}

POINT* definePoint(float x, float y){

    POINT* p = malloc(sizeof(POINT));
    p->x = x;
    p->y = y;

    return p;

}

void accessCoordinates(CIRCLE* c){
    printf("hi");

    printf("Circle's center: (%f,%f)\n", c->center->x, c->center->y);
    printf("Circle's radius: %f\n", c->radius);

}

void calcArea(CIRCLE* c){

    float area = 2 * 3.14;
    area *= c->radius;
    printf("\nCircle's area: %f", area);
}

void checkPosition(POINT* p, CIRCLE* c){

    float distance = sqrt(pow(p->x - c->center->x, 2)+pow(p->y - c->center->y, 2));
    if(distance <= c->radius){
        printf("The point is inside the circle\n");
    }else{
        printf("The point is outside the circle\n");
    }
}

void freeMemory(CIRCLE* c){

    free(c);

}
