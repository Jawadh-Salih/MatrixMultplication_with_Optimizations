//
// Created by jawadhsr on 3/20/17.
//

#include "optimized.h"
#include <omp.h>
double optimized_matrix_mul(int n,double ** O,double ** A,double ** B){
    double start,end;
    start= omp_get_wtime();
    int i,j,k;
#pragma omp parallel for private(i,j,k)
    for(i=0;i<n;i++){
        for(k=0;k<n;k++){
            for(j=0;j<n;j++){
                O[i][j] += A[i][k]*B[k][j];
            }
        }
    }
    end = omp_get_wtime();
    return (end-start) * 1000;
}