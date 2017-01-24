#include <stdio.h>
#include <time.h>
#include <malloc.h>


int main(){

    // A matrix multiplaction example. Multiply matrix1 and matrix2. 

    int length = 1000;
    int i, j, k, m;
    float temp;
    float *matrix1[length], *matrix2[length], *matrix3[length];

    // Timing Variables
    int msec = 0;
    clock_t before, difference;

    // Initializing matrices
    for (i=0; i<length; i++){
        matrix1[i] = (float*)malloc(length * sizeof(float));
        matrix2[i] = (float*)malloc(length * sizeof(float));
        matrix3[i] = (float*)malloc(length * sizeof(float));
        // memset
    }



    // First Operation - Non-contiguous access of matrix2
    before=clock();
    for(int j = 0; j < length; j++){
        for (int k = 0; k < length; k++){
            temp = 0;
            for (int m = 0; m < length; m++){
                // here in the inner loop we are sweeping m. Every time m changes, we are getting the
                // kth element from a different array/portion of matrix2
                temp = temp + matrix1[j][m] * matrix2[m][k]; 
        }
        matrix3[j][k] = temp;
        }
    }
    difference=clock()-before;
    msec = difference * 1000 / CLOCKS_PER_SEC;

    printf("Operation 1 time: %d ms\n", msec);



    // Second Operation - Contiguous access of matrix2
    before=clock();
    for(int j = 0; j < length; j++){
        for (int k = 0; k < length; k++){
            temp = 0;
            for (int m = 0; m < length; m++){
                // here in the inner loop we are sweeping m. Every time m changes, we are getting the
                // next consecurive element from the same kth array/portion of matrix2
                temp = temp + matrix1[j][m] * matrix2[k][m];
        }
        matrix3[j][k] = temp;
        }
    }
    difference=clock()-before;
    msec = difference * 1000 / CLOCKS_PER_SEC;

    printf("Operation 2 time: %d ms\n", msec);
    return 0;
}