
#include "TAD_circle.h"
#include <stdlib.h>
#include <stdio.h>

int main(){

    float rad, x, y;
    CIRCLE* c1;

    printf("\nType the circle's radius: ");
    scanf("%f", &rad);
    printf("\nType the circle's center: ");
    printf("\nX:  ");
    scanf("%f", &x);
    printf("\nY:  ");
    scanf("%f", &y);

    c1 = createCircle(rad, x, y);
    accessCoordinates(c1);
    calcArea(c1);

    POINT* p;

    printf("\nType a point: ");
    printf("\nX:  ");
    scanf("%f", &x);
    printf("\nY:  ");
    scanf("%f", &y);
    p = definePoint(x, y);
    checkPosition(p, c1);

    freeMemory(c1);

    return 0;
}
