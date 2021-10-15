#include <stdio.h>
#include <stdlib.h>

void printVariance(float variance){
    system("clear");
    printf("Variance: %f\n\n\n\n", variance);
}

float calcVariance(int* values, float average, int n){

    float aux = 0;
    for(int i = 0; i < n; i++){
        aux += (values[i] - average) * (values[i] - average);
    }
    float variance = aux/average;
    return variance;
}

float calcAverage(int* values, int* n){

    int sum = 0;
    for(int i = 0; i < *n; i++){
        sum += values[i];
    }
    float average = sum/ *n;
    return average;
}

int* inputValues(int *n){

    printf("How many number to input? ");
    scanf("%d", &*n);

    int* values = malloc(sizeof(int) * *n);

    for(int i = 0; i < *n; i++){
        printf("\n- Number n%d: ", i + 1);
        scanf("%d", &values[i]);
    }

    return values;
}

int main (){

    int n;
    int* values = inputValues(&n);
    //for(int i = 0; i < 2; i++){
    //    printf("\n- N n%d: %d", i + 1, values[i]);
    //}
    float average = calcAverage(values, &n);
    float variance = calcVariance(values, average, n);

    printVariance(variance);
    
    return 0;
}