#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define LEN 3
#define NOTES 5

typedef struct student{
    char* name;
    float notes[NOTES], average;
}STUDENT;

char rateAverage(float num){
    if(num >= 9){
        return 'A';
    }else if(num >= 8){
        return 'B';
    }else if(num >= 6){
        return 'C';
    }else{
        return 'D';
    }
}

void outputData(STUDENT* class){

    system("clear");
    for (int i = 0; i < LEN; i++)
    {
        printf("\n\n%d - STUDENT", i+1);
        printf("\nName: %s", (class[i]).name);
        for (int n = 0; n < NOTES; n++)
        {
            printf("\n%d - Note: %f", n + 1, (class[i]).notes[n]);
        }
        printf("\nAverage: %c", rateAverage((class[i]).average));
    }
    printf("\n\n");
}

void inputData(STUDENT* class){

    char buffer[30];
    for (int i = 0; i < LEN; i++)
    {
        (class[i]).average = 0;  

        printf("\n%d - STUDENT", i+1);
        printf("\nName: ");
        scanf(" %[^\n]s", buffer);
        (class[i]).name = malloc(sizeof(char) * strlen(buffer));
        strcpy((class[i]).name, buffer);
        for (int n = 0; n < NOTES; n++)
        {
            printf("%d - Note: ", n + 1);
            scanf(" %f", &(class[i]).notes[n]);
            (class[i]).average += (class[i]).notes[n];
        }
        (class[i]).average /= NOTES;

    }
}

int main(){

    STUDENT class[LEN];

    inputData(class);
    outputData(class);
    return 0;
}