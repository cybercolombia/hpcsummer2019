#include <iostream>
#include <fstream>
#include <unistd.h>
#include <limits>
#include <cmath>
#include <sys/time.h>

#include "defs.h"
#define INFO_BUFFER_SIZE 1024

using namespace std;

int main(int argc, char *argv[]){
#ifdef _OPENMP
    printf("**MESSAGE** OpenMP enabled\n");
    (void) omp_set_dynamic(FALSE);
    if (omp_get_dynamic()) {printf("\t**Warning** dynamic adjustment of threads has been set\n");}
    (void) omp_set_num_threads(8);
#else
    printf("**MESSAGE** OpenMP disabled\n");
#endif

    SimpleTimer_t t1;

    int j,N = 200;
    Crandom r(10);
    double *v1;
    double norm_v1;
    CREATEARRAY(v1,double,N,r.gaussian(0,0.5));

    PRINTARRAY(v1,N);

    printf("\nPart 1\n");

    norm_v1 = 0;
    for(j = 0; j < N; j++)
        norm_v1 += v1[j]*v1[j];
    printf("v1 norm = %lf\n",norm_v1);

    return 0;
}
