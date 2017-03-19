//
// Created by jawadhsr on 3/20/17.
//

#include <iostream>
#include <omp.h>
#include "optimized.h"
#include <stdlib.h>
#include <math.h>
using namespace std;

double **mat_a,**mat_b,**mat_s,**mat_p,**mat_o;
double **init_matrix(int n);
void populate_matrix(int n,double ** mat);
double print_matrix(int n, double ** mat);

double serial_matrix_mul(int n);
double parallel_matrix_mul(int n);

double get_mean(double *X, int samples);
double get_std(double *X,double mean, int samples);
double get_speedup(double time_new , double time_old);
double get_sample_count(double std,double mean);
int main(){

    srand(time(NULL));

    int n=0,sample_cnt = 20;
    cout << "N" << "\t" << "Serial " << "\t\t" << "Parallel "<< "\t" << "Optimized " << "\t"
         <<"SpeedUp "<< "\t" << "New SpeedUp " << "\t" <<"Gained SpeedUp"<< "\t" << endl;
    for(int n = 100 ; n < 1001; n+= 100){

        double time_serials[sample_cnt]={0},time_parallels[sample_cnt]={0},time_optmizeds[sample_cnt]={0};
        for(int sample = 0;sample < sample_cnt ; sample++){
            mat_a = init_matrix(n);
            mat_b = init_matrix(n);
            mat_s = init_matrix(n);
            mat_p = init_matrix(n);
            mat_o = init_matrix(n);

            populate_matrix(n,mat_a);
            populate_matrix(n,mat_b);

            double time_serial = serial_matrix_mul(n);
            double time_parallel= parallel_matrix_mul(n);
            double time_optimized = optimized_matrix_mul(n,mat_o,mat_a,mat_b);

            time_serials[sample] = time_serial;
            time_parallels[sample] = time_parallel;
            time_optmizeds[sample] = time_optimized;

        }
        double mean_serial = get_mean(time_serials,sample_cnt)
              ,mean_parallel = get_mean(time_parallels,sample_cnt)
              ,mean_optimized = get_mean(time_optmizeds,sample_cnt);

        double std_serial = get_std(time_serials,mean_serial,sample_cnt)
        ,std_parallel = get_std(time_parallels,mean_parallel,sample_cnt)
        ,std_optimized = get_std(time_optmizeds,mean_optimized,sample_cnt);

        double sample_cnt_serial = get_sample_count(std_serial,mean_serial)
              ,sample_cnt_parallel = get_sample_count(std_parallel,mean_parallel)
              ,sample_cnt_optimized = get_sample_count(std_optimized,mean_optimized);

        if(sample_cnt_serial>sample_cnt && sample_cnt_parallel>sample_cnt && sample_cnt_optimized>sample_cnt){
            cout << "Accuracy of the results are not enough to give the 95% confidence level" << endl;
            // Start Again.
        }
        else{
            double speedUp = get_speedup(mean_parallel,mean_serial);
            double speedUp_new = get_speedup(mean_optimized,mean_serial);
            double speedUp_gained = speedUp_new - speedUp;

            cout << n << "\t" << mean_serial << "ms\t" << mean_parallel << "ms\t" << mean_optimized<< "ms\t"
                 <<speedUp << "\t\t" <<speedUp_new<< "\t\t" <<speedUp_gained<< "\t" << endl;
        }
    }
    return 0;
}

double **init_matrix(int n){
    double ** mat = new double*[n];
    for(int i=0;i<n;i++){
        mat[i] = new double[n];
    }

    return mat;
}
void populate_matrix(int n,double ** mat){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            mat[i][j] = (double)rand()/RAND_MAX*10;
        }
    }

}
double print_matrix(int n, double ** mat){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
           cout <<  mat[i][j] << "  " << endl;
        }
    }
}

double serial_matrix_mul(int n){
    int i,j,k;
    double sum = 0;
    double start,end;
    start = omp_get_wtime();
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            sum = 0;
            for(k=0;k<n;k++){
                sum += mat_a[i][k]*mat_b[k][j];
            }
            mat_s[i][j] = sum;
        }
    }
    end = omp_get_wtime();

    return (end-start)*1000;
}
double parallel_matrix_mul(int n){
    int i,j,k;
    double sum = 0;

    double start ,end;
    start = omp_get_wtime();

#pragma omp parallel for    private(i,j,k)
    for(i  =0; i<n; i++){
#pragma omp parallel for
        for( j=0; j<n; j++){
            double sum =0;
            for( k=0; k<n; k++){
                sum += mat_a[i][k] * mat_b[k][j];
            }
            mat_p[i][j] = sum;
        }
    }
    end = omp_get_wtime();
    return (end-start) * 1000;

}

double get_mean(double *X, int samples){
    double mean=0;
    for(int i=0;i<samples;i++){
        mean += X[i];
    }

    return mean/samples;
}
double get_std(double *X,double mean, int samples){
    double std=0;
    for(int i=0;i<samples;i++){
        std += (X[i]-mean)*(X[i]-mean);
    }
    std /=samples;

    return sqrt(std);
}
double get_speedup(double time_new , double time_old){
    return time_old/time_new;
}
double get_sample_count(double std,double mean){
    double z = 1.96,r = 5;

    return sqrt((100*z*std)/(r*mean));
}