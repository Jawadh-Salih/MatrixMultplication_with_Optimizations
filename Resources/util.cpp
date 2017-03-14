//
// Created by jawadhsr on 3/10/17.
//

#include <cmath>
#include "util.h"



double util::elapsed_time(time_t start_time,time_t end_time){

    double elapsed =(double) (end_time - start_time) /CLOCKS_PER_SEC;
    return elapsed;
}

double util::get_sample_count(double sd, double pop_mean){

    double sample_count = 100*z*sd/(r*pop_mean);

    return sample_count;
}

double  util::speedup(double elapsed_time_old,double elapsed_time_new){

    double speedup = elapsed_time_old/elapsed_time_new;
    return speedup;
}

double  util::get_mean(double * population,int n){

    double mean=0.0;
    for(int i=0;i<n;i++){
        mean += population[i];
    }

    mean /= n;
    return  mean;
}

double  util::get_SD(double *population, double mean, int n){

    double std = 0.0;
    for (int i=0;i<n;i++){
        std += pow((population[i]-mean),2);
    }
    std /= n;
    std = sqrt(std);
    return std;
}
