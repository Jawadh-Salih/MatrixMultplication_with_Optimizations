//
// Created by jawadhsr on 3/20/17.
//

#include "optimized.h"
#include <omp.h>
#include <iostream>
#include <pmmintrin.h>

void transpose(int size, double** m)
{
    int i,j;
    #pragma omp parallel for private (i,j)
    for ( i = 0; i < size; i++) {
        for ( j = i + 1; j < size; j++) {
            std::swap(m[i][j], m[j][i]);
        }
    }
}
double optimized_matrix_mul_sse3(int n,double ** O,double ** A,double ** B){
    double start,end;
    start= omp_get_wtime();
    int i,j,k;
    transpose(n, B);
    #pragma omp parallel for private(i,j,k)

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            __m128d c = _mm_setzero_pd();

            for (int k = 0; k < n; k += 2) {
                c = _mm_add_pd(c, _mm_mul_pd(_mm_load_pd(&A[i][k]), _mm_load_pd(&B[j][k])));
            }
            c = _mm_hadd_pd(c, c);
            _mm_store_sd(&O[i][j], c);
        }
    }
    end = omp_get_wtime();
    return (end-start) * 1000;
}

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
