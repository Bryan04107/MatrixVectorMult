#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mylib/mylib.h"

#define LOWER 1
#define UPPER 100

int GRandInt(int lower, int upper){
    return (rand() % (upper-lower+1)) + lower;
}

void initMat(int* M, int N){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            M[N*i+j] = GRandInt(LOWER,UPPER);
        }
    }
}

void initVec(int* V, int N){
    for(int i=0; i<N; i++){
        V[i] = GRandInt(LOWER,UPPER);
    }
}

int main(void) {
    int N = 5000;
    int* M = (int *) malloc(N*N*sizeof(int));
    int* V = (int *) malloc(N*sizeof(int));
    int* VResult = (int *) malloc(N*sizeof(int));

    initMat(M, N);
    initVec(V, N);

    float startTime = (float)clock()/CLOCKS_PER_SEC;
    matVecMult(M, V, VResult, N);
    float endTime  = (float)clock()/CLOCKS_PER_SEC;

    double timeTaken = endTime - startTime;

    printf("Time elapsed = %d : %fs\n", N, timeTaken);

    return 0;
}