//
// Created by jawadhsr on 3/10/17.
//

#ifndef CONCURRENT_LAB3_MATRIXMULTIPLIER_H
#define CONCURRENT_LAB3_MATRIXMULTIPLIER_H


#include "Matrix.h"

class MatrixMultiplier {

private:
    Matrix matrix_a = Matrix(0, false);
    Matrix matrix_b = Matrix(0, false);
    Matrix matrix_c = Matrix(0, false);
    int dimension;

public:
    MatrixMultiplier(Matrix A,Matrix B,Matrix C);

    Matrix get_matrix_a();
    Matrix get_matrix_b();
    Matrix get_matrix_c();
    int get_dimension();

    void multiply_matrix(int n,Matrix C,Matrix A,Matrix B);
    void multiply_matrix_parallel(int n, Matrix C,Matrix A,Matrix B);
};


#endif //CONCURRENT_LAB3_MATRIXMULTIPLIER_H
