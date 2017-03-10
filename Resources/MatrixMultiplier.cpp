//
// Created by jawadhsr on 3/10/17.
//


#include "MatrixMultiplier.h"

// Included to debug and test.
///Todo : Remove this when release.
#include <iostream>
using namespace std;
MatrixMultiplier::MatrixMultiplier(Matrix A,Matrix B,Matrix C) {
    matrix_a = A;
    matrix_b = B;
    matrix_c = C;
}
Matrix MatrixMultiplier::get_matrix_a() {
    return matrix_a;
}

Matrix MatrixMultiplier::get_matrix_b() {
    return matrix_b;
}
Matrix MatrixMultiplier::get_matrix_c() {
    return matrix_c;
}

void MatrixMultiplier::multiply_matrix(int n,Matrix C, Matrix A, Matrix B) {

    double element;
    for(int i=0;i<n;i++){
        for(int k=0;k<n;k++){
            for(int j=0;j<n;j++){
                element = C.get_element(i,j) + A.get_element(i,k)*B.get_element(k,j);
                C.set_element(i,j,element);
            }
        }
    }
}



void MatrixMultiplier::multiply_matrix_parallel(int n, Matrix C, Matrix A, Matrix B) {

    double element;
    #pragma omp parallel for
    for (int i = 0; i < n; ++i) {
        #pragma omp parallel for
        for (int k= 0; k < n ; ++k) {
            for (int j = 0;j<n;j++){
                element = C.get_element(i,j) + A.get_element(i,k)*B.get_element(k,j);
                C.set_element(i,j,element);
            }
        }
    }
}