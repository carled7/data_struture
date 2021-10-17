#include <stdio.h>
#include <stdlib.h>


void printMatrix(int mtr[], int row, int col, int transpose){
    int k;
    for(int i = 0; i < row; ++i){
        for (int j = 0; j < col; ++j)
        {
            k = i * col + j;
            if(transpose){
                if((k % row) == 0){
                    printf("\n");
                }
            }else{
                if((k % col) == 0){
                printf("\n");
            }
            }
            printf("   %d", mtr[k]);
        }
        
    }
    printf("\n");
}

void fillMatrix(int mtr[], int row, int col){

    int k;
    for(int i = 0; i < row; ++i){
        for (int j = 0; j < col; ++j)
        {
            k = i * col + j;
            if((k % col) == 0){
                printf("\n");
            }
            printf("  [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &mtr[k]);
        }
        
    }

}

int* allocMatrix(int row, int col){

    int* matrix;
    matrix = malloc(sizeof(int) * row * col);
    return matrix;

}

void inputMatrix(int* row, int* col){

    printf("How many rows? ");
    scanf("%d", row);
    printf("\nHow many colums? ");
    scanf("%d", col);
    
}

int main(){

    int row, col;
    int* mtr;
    int* transMtr;
    inputMatrix(&row, &col);
    mtr = allocMatrix(row, col);
    transMtr = allocMatrix(row, col);
    fillMatrix(mtr, row, col);
    printf("\n========== MATRIz =============\n");
    printMatrix(mtr, row, col, 0);
    printf("\n===== TRANSPOSE MATRIz ========\n");
    printMatrix(mtr, row, col, 1);


    printf("\n\n\n");

    return 0;
}