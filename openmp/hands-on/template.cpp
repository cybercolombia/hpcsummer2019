/*

icc -std=c++11 main.cpp -o exe -qopenmp && ./exe
g++ -std=c++11 -Wall -Wextra -Werror main.cpp -o exe -fopenmp && ./exe

*/
#include <iostream>
#include <fstream>
#include <unistd.h>
#include <limits>
#include <cmath>
#include <sys/time.h>

#include "defs.h"

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

    // Timer example
    SimpleTimer_t t1;
    Crandom r(10); // seed = 10

    float *v1;
    double **m1;
    int TID = omp_get_thread_num();

    printf("Thread ID of the master thread is %d\n",TID);

    // Collect start time for this snippet
    SimpleTimer_start( &t1 );
    #pragma omp parallel
    {
        int TID = omp_get_thread_num();

        printf("In parallel region - Thread ID is %d\n",TID);
    } /*-- End of parallel region --*/
    // Collect stop time
    SimpleTimer_stop( &t1 );
    // Print duration
    SimpleTimer_print( &t1 );

    CREATEARRAY(v1,float,15,r.gaussian(0,1.0));
    CREATEMATRIX(m1,double,12,8,0);

    PRINTARRAY(v1,15);
    PRINTMATRIX(m1,12,8);

    free(v1);
    free(m1[0]);
    free(m1), m1 = NULL;
    return 0;
}
