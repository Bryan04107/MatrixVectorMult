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

void initVec(int* v, int N){
    for(int i=0; i<N; i++){
        v[i] = GRandInt(LOWER,UPPER);
    }
}

int main(void){
    int N = 3;
    int* M = (int *) malloc(N*N*sizeof(int));
    int* v = (int *) malloc(N*sizeof(int));
    int* b = (int *) malloc(N*sizeof(int));

    if(M == NULL | v == NULL){
        exit(0);
    } else {
        initMat(M, N);
        printf("M=");
        printMat(M, N);
        initVec(v, N);
        printf("v=");
        printVec(v, N);
        matVecMult(M,v,b,N);
        printf("b=");
        printVec(b, N);
    }

    free(M);
    free(v);
    free(b);

    return 0;
}