
#include "Matrix.h"
#include <random>

#include <iostream>
#include "util.h"

Matrix::Matrix(int n,bool populate) {
    // Now generate a random nxn Matrix.
    set_N(n);
    mat = new util::double_def*[n];
    for(int i=0;i<n;i++){
       mat[i] = new util::double_def[n];
        for(int j=0;j<n;j++){
            mat[i][j] = 0;
        }
    }

    if(populate)
        generate_matrix(n);
}
int Matrix::get_N() {
    return N;
}
util::double_def ** Matrix::get_matrix(){
    return mat;
}
util::double_def  Matrix::get_element(int i,int j){
    return mat[i][j];
}

// call this method to set the N value.
void Matrix::set_N(int n) {
    Matrix::N = n;
}
void Matrix::set_matrix(util::double_def  **mat) {
    Matrix::mat = mat;
}

void Matrix::set_element(int i, int j, util::double_def  element) {
    mat[i][j] = element;
}
void Matrix::generate_matrix(const int n) {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            util::double_def f =100* (util::double_def) rand() / RAND_MAX;
            mat[i][j] = f;
        }
    }

}

void Matrix::print_matrix() {

    int n = Matrix::N;
    for (int i = 0;i< n;i++){
        std::cout << std::endl;
        for (int j = 0;j< n;j++){
            std::cout << Matrix::mat[i][j] << "  " ;
        }
    }
    std::cout << std::endl;
}
