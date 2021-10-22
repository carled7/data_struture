#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


typedef struct point{
    float x, y;
}POINT;

void calcDistance(float x1, float y1, float x2, float y2, float x3, float y3){
    float dist1To2, dist1To3, dist2To3, minorDist;
    char closerP[6];
    dist1To2 = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
    dist1To3 = sqrt(pow((x1 - x3), 2) + pow((y1 - y3), 2));
    if(dist1To2 < dist1To3){
        minorDist = dist1To2;
        strcpy(closerP, "A n B");
    }else{
        minorDist = dist1To3;
        strcpy(closerP, "A n C");
    }
    dist2To3 = sqrt(pow((x3 - x2), 2) + pow((y3 - y2), 2));
    if(dist2To3 < minorDist){
        minorDist = dist2To3;
        strcpy(closerP, "B n C");
    }

    printf("\nThe closer points are %s\n", closerP);
    printf("The distance between them is: %f\n\n\n", minorDist);
}

void inputData(POINT* A, POINT* B, POINT* C){
    printf("PRIMEIRO PONTO:");
    printf("\nx = ");
    scanf("%f", &A->x);
    printf("y = ");
    scanf("%f", &A->y);
    printf("\nSEGUNDO PONTO");
    printf("\nx = ");
    scanf("%f", &B->x);
    printf("y = ");
    scanf("%f", &B->y);
    printf("\nTERCEIRO PONTO");
    printf("\nx = ");
    scanf("%f", &C->x);
    printf("y = ");
    scanf("%f", &C->y);
}

int main(){

    POINT A, B, C;

    inputData(&A, &B, &C);
    calcDistance(A.x, A.y, B.x, B.y, C.x, C.y);

    return 0;
}