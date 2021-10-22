#include <stdio.h>
#include <stdlib.h>
#include <math.h>


typedef struct point{
    float x, y;
}POINT;

void calcDistance(float x1, float y1, float x2, float y2){
    double distance;
    distance = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
    printf("\nThe distance between these two points is: %lf\n\n\n", distance);
}

void inputData(POINT* A, POINT* B){
    printf("\nDigite o primerio ponto:");
    scanf("%f", &A->x);
    scanf("%f", &A->y);
    printf("\nDigite o segundo ponto:");
    scanf("%f", &B->x);
    scanf("%f", &B->y);
}

int main(){

    POINT A, B;

    inputData(&A, &B);
    calcDistance(A.x, A.y, B.x, B.y);

    return 0;
}