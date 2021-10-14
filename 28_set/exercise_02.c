#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void inputStr(char* str){
    printf("Type something: ");
    scanf(" %[^\n]s", str);
}

char* mallocStr(char* str){
    int N = strlen(str);
    char* output = malloc(sizeof(char) * N);
    strcpy(output, str);

    return output;
}

int main (){
    char str [30];
    inputStr(str);
    char* strDinamic = mallocStr(str);
    
    return 0;
}