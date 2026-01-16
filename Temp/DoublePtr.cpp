#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand((unsigned int) time(NULL));
   
    const int ROW = 10;
    const int COL = 5;

    int **matrix = (int**)malloc(sizeof(int*) * ROW);
    if(matrix == NULL) return 1;

    for (int i = 0; i < ROW; i++){
        matrix[i] = (int*)malloc(sizeof(int) * COL);
    }

    for (int i = 0; i < ROW; i++){
        printf("\nROW %d: ", i);
        for (int j = 0; j < COL; j++){
            matrix[i][j] = rand() % 10;
            printf("%d, ", matrix[i][j]);
        }
    }
    
    printf("\n");
    int *ofMtrx = (int*)malloc(sizeof(int) * (ROW * COL));

    for (int i = 0; i < ROW; i++){
        printf("\nROW %d: ", i);
        for (int j = 0; j < COL; j++){
            ofMtrx[(ROW * i) + j] = rand() % 10;
            printf("%d, ", ofMtrx[(ROW * i) + j]);
        }
    }

    

    printf("\n");
    return 0;
}
