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

    int x = 10;

    printf("thread %d original value: %d\n",omp_get_thread_num(),x);
    #pragma omp parallel private(x)
    {
        int TID = omp_get_thread_num();
        printf("thread %d value: %d\n",TID,x);
    } /*-- End of parallel region --*/
    printf("thread %d after value: %d\n",omp_get_thread_num(),x);

    return 0;
}
