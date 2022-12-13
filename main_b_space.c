#include <stdio.h>
#include <stdlib.h>
#include "mylib/mylib.h"

#define LOWER 1
#define UPPER 100

int GRandInt(int lower, int upper){
    return (rand() % (upper - lower + 1)) + lower;
}

void initMat(int* M, int N){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            M[N * i + j] = GRandInt(LOWER, UPPER);
        }
    }
}

void initVec(int* V, int N){
    for(int i = 0; i < N; i++){
        V[i] = GRandInt(LOWER, UPPER);
    }
}

int main(void) {
    int N = 3;
    int* M = (int *) malloc(N * N * sizeof(int));
    int* V = (int *) malloc(N * sizeof(int));
    int* B = (int *) malloc(N * sizeof(int));

    if((M == NULL) | (V == NULL)){
        exit(0);
    } else {
        initMat(M, N);
        printf("\nMatrix = ");
        printMat(M, N);
        initVec(V, N);
        printf("\nVector = ");
        printVec(V, N);
        for (int i = 0; i > -1; ++i){
            matVecMult(M, V, B, N);
            printf("\nResult = " );
            printVec(B, N);
        }
    }

    free(M);
    free(V);
    free(B);

    return 0;
}