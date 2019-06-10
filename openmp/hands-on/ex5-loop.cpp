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
    (void) omp_set_num_threads(4);
#else
    printf("**MESSAGE** OpenMP disabled\n");
#endif

    SimpleTimer_t t1;

    int j,N = 10;
    Crandom r(10);
    double *v1,*v2,*res;
    CREATEARRAY(v1,double,N,r.gaussian(1,2));
    CREATEARRAY(v2,double,N,-1);
    CREATEARRAY(res,double,N,0);

    PRINTARRAY(v1,N);
    PRINTARRAY(v2,N);

    printf("\nPart 1\n");

    for(int j = 0; j < N; j++)
        res[j] = v1[j] + v2[j];
    PRINTARRAY(res,N);

    free(v1);free(v2);free(res);
    return 0;
}
