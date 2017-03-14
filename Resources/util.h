//
// Created by jawadhsr on 3/10/17.
//

#ifndef CONCURRENT_LAB3_UTIL_H
#define CONCURRENT_LAB3_UTIL_H

#define z 1.96 // 95% Confidennce.
#define r  5 // 5% accuracy
#include <time.h>

class util {

public:
    typedef double double_def;


    double elapsed_time(time_t start_time, time_t end_time);
    double get_sample_count(double sd, double pop_mean);
    double speedup(double elapsed_time_old,double elapsed_time_new);
    double get_mean(double * population,int n);
    double get_SD(double *population, double mean, int n);

    };

#endif //CONCURRENT_LAB3_UTIL_H
