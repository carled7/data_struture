#include <stdio.h>
#include <stdlib.h>
//#include <ctype.h>
#include <string.h>

void inputStr(char* str){
    printf("Type something: ");
    scanf(" %[^\n]s", str);
}

char* mallocStr(char* str){
    int N = strlen(str);
    char* output = malloc(sizeof(char) * N);
    strcpy(output, str);
    for(int i = 0; i < N; i++){
        if(output[i] > 64 && output[i] < 91){
            continue;
        }
        output[i] -= 32;
    }
    printf("%s", output);
    return output;
}

int main (){
    char str [30];
    inputStr(str);
    char* strDinamic = mallocStr(str);
    
    printf(" %s\n", str);
    printf(" %s\n\n\n", strDinamic);

    return 0;
}