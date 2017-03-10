//
// Created by jawadhsr on 3/10/17.
//

#ifndef CONCURRENT_LAB3_MATRIX_H
#define CONCURRENT_LAB3_MATRIX_H


#include "util.h"

class Matrix {

private:
    int N = 0;
    util::double_def ** mat;

public:
    Matrix(int n,bool populate);


    // getters
    int get_N();
    util::double_def  ** get_matrix();

    //setters
    void set_N(int n);
    void set_matrix(util::double_def  ** mat);
    void set_element(int i,int j,util::double_def  element);

    void generate_matrix(const int n);
    void print_matrix();
    util::double_def  get_element(int i,int j);
};


#endif //CONCURRENT_LAB3_MATRIX_H
