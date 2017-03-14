
#include "Resources/Matrix.h"
#include "Resources/MatrixMultiplier.h"
#include <iostream>

using namespace std;
int main() {
    srand((uint)time(NULL));
    util utilities;
    time_t start,end;
//    cout << "Enter Dimensions of the Matrix" << endl;

    for (int n = 100 ; n < 1001; n += 100){
//        cout << "Populating Matrix  A and B of " << n << "x" << n << " with random real numbers...." << endl;
        double time_seq[20]={0},time_parallel[20]={0};
        for (int sample= 0;sample < 20;sample++){
            Matrix matrix_a(n,1),matrix_b(n,1),matrix_c(n,0),matrix_p(n,0);

            MatrixMultiplier multiplier(matrix_a,matrix_b,matrix_c);

            start = clock();
            multiplier.multiply_matrix(n,matrix_c,matrix_a,matrix_b);
            end = clock();

//            cout << matrix_c.get_element(0,0)  << endl;
            double elapsed_time_sequential = utilities.elapsed_time(start,end);
            time_seq[sample] = elapsed_time_sequential;
            start = clock();
            multiplier.multiply_matrix_parallel(n,matrix_p,matrix_a,matrix_b);
            end = clock();

            double elapsed_time_parallel = utilities.elapsed_time(start,end);
            time_parallel[sample] =elapsed_time_parallel;

//            cout << "Elapsed Time for Sequential Matrix Multiplication for N ="<< n <<" : "<< elapsed_time_sequential <<endl;
//            cout << "Elapsed Time for Parallel Matrix Multiplication for N ="<< n <<" : "<< elapsed_time_parallel <<endl;
        }
        double mean_seq = utilities.get_mean(time_seq,20)
              ,mean_parallel = utilities.get_mean(time_parallel,20);

        double std_seq = utilities.get_SD(time_seq,mean_seq,20)
              ,std_parallel = utilities.get_SD(time_parallel,mean_parallel,20);

        double sample_count_seq = utilities.get_sample_count(std_seq,mean_seq)
              ,sample_count_parallel = utilities.get_sample_count(std_parallel,mean_parallel);

        if(sample_count_parallel >20 && sample_count_seq > 20){
            cout << "Not achieved the 95% confidence Level ! Run Again.." << endl;

        }
        else{
            double speedup = utilities.speedup(mean_seq,mean_parallel);
            cout << "SAverage Execution time Serial n = "<< n << " is :" << mean_seq << endl;
            cout << "SAverage Execution time Serial n = "<< n << " is :" << mean_parallel << endl;
            cout << "Speed Up for n = "<< n << " is :" << speedup << endl;
        }





//    matrix_a.print_matrix();
//    matrix_b.print_matrix();
//    matrix_c.print_matrix();
//    matrix_p.print_matrix();

}
//    matrix_a.print_matrix();
//    cout << endl;
//    matrix_b.print_matrix();
//
//    matrix_c.print_matrix();
//    cout << endl;


    return 0;
}
