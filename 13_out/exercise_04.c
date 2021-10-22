#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct point{
    float x, y;
}POINT;
typedef struct rect{
    POINT downLeft;
    POINT upRight;
}RECT;

void printPosition(int pos){
    switch (pos)
    {
    case -1:
        printf("\nThe point is inside the rectangle.");
        break;
    case 0:
        printf("\nThe point is on the rectangle's margin.");
        break;
    case 1:
        printf("\nThe point is outside the rectangle.");
        break;
    
    }
    printf("\n\n");
}

int calcDistance(float x1, float y1, RECT* C){

    if(((C->downLeft.x <= x1) && (C->upRight.x >= x1)) && ((C->downLeft.y <= y1) && (C->upRight.y >= y1))){
        if((x1 == C->downLeft.x) || (x1 == C->upRight.x) || (y1 == C->downLeft.y) || (y1 == C->upRight.y)){
            return 0;
        }else{
            return -1;
        }
    }else {
        return 1;
    }
}

void inputData(POINT* point, RECT* rect){
    printf("- RECTANGLE");
    printf("\nWhat's the down-left conner?");
    printf("\nx = ");
    scanf("%f", &rect->downLeft.x);
    printf("y = ");
    scanf("%f", &rect->downLeft.y);
    printf("\nWhat's the up-right conner?");
    printf("\nx = ");
    scanf("%f", &rect->upRight.x);
    printf("y = ");
    scanf("%f", &rect->upRight.y);

    printf("\n\n- POINT");
    printf("\nx = ");
    scanf("%f", &point->x);
    printf("y = ");
    scanf("%f", &point->y);
}

int main(){

    POINT A;
    RECT rectangle;
    int position;

    inputData(&A, &rectangle);
    position = calcDistance(A.x, A.y, &rectangle);
    printPosition(position);

    return 0;
}