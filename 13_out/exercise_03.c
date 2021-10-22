#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


typedef struct point{
    float x, y;
}POINT;
typedef struct circle{
    POINT center;
    float radius;
}CIRCLE;

void printPosition(int pos){
    switch (pos)
    {
    case -10:
        printf("\nThe point is inside the circle.");
        break;
    case 0:
        printf("\nThe point is on the circle's margin.");
        break;
    case 1:
        printf("\nThe point is outside the circle.");
        break;
    
    }
}

int calcDistance(float x1, float y1, CIRCLE* C){

    float dist;

    dist = sqrt(pow((x1 - C->center.x), 2) + pow((y1 - C->center.y), 2));

    if(dist > C->radius){
        return 1;
    }else if(dist < C->radius){
        return -1;
    }else{
        return 0;
    }

}

void inputData(POINT* A, CIRCLE* C){
    printf("- CIRCLE");
    printf("\nWhat's the circle center?");
    printf("\nx = ");
    scanf("%f", &C->center.x);
    printf("y = ");
    scanf("%f", &C->center.y);
    printf("\nWhat's the circle radius?");
    printf("\nradius = ");
    scanf("%f", &C->radius);

    printf("\n\n- POINT");
    printf("\nx = ");
    scanf("%f", &A->x);
    printf("\ny = ");
    scanf("%f", &A->y);
}

int main(){

    POINT A;
    CIRCLE C;
    int position;

    inputData(&A, &C);
    position = calcDistance(A.x, A.y, &C);
    printPosition(position);

    return 0;
}