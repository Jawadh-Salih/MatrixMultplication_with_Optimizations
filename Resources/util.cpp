//
// Created by jawadhsr on 3/10/17.
//

#include "util.h"


double util::elapsed_time(time_t start_time,time_t end_time){

    double elapsed =(double) (end_time - start_time) /CLOCKS_PER_SEC;
    return elapsed;
}
