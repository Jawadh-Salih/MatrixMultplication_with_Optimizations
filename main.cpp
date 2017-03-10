
#include "Resources/Matrix.h"
#include "Resources/MatrixMultiplier.h"
#include <iostream>

using namespace std;
int main() {
    srand(time(NULL));
    util utilities;
    time_t start,end;
    cout << "Enter Dimensions of the Matrix" << endl;

    for (int n = 100 ; n < 1001 ; n += 100){
        cout << "Populating Matrix  A and B of " << n << "x" << n << " with random real numbers...." << endl;

        Matrix matrix_a(n,1),matrix_b(n,1),matrix_c(n,0),matrix_p(n,0);

        MatrixMultiplier multiplier(matrix_a,matrix_b,matrix_c);

        start = clock();
        multiplier.multiply_matrix(n,matrix_c,matrix_a,matrix_b);
        end = clock();

        cout << matrix_c.get_element(0,0)  << endl;
        double elapsed_time_sequential = utilities.elapsed_time(start,end);

        start = clock();
        multiplier.multiply_matrix_parallel(n,matrix_p,matrix_a,matrix_b);
        end = clock();

//    matrix_a.print_matrix();
//    matrix_b.print_matrix();
//    matrix_c.print_matrix();
//    matrix_p.print_matrix();
        double elapsed_time_parallel = utilities.elapsed_time(start,end);


        cout << "Elapsed Time for Sequential Matrix Multiplication for N ="<< n <<" : "<< elapsed_time_sequential <<endl;
        cout << "Elapsed Time for Parallel Matrix Multiplication for N ="<< n <<" : "<< elapsed_time_parallel <<endl;
}
//    matrix_a.print_matrix();
//    cout << endl;
//    matrix_b.print_matrix();
//
//    matrix_c.print_matrix();
//    cout << endl;


    return 0;
}
