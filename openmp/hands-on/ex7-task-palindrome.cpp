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

    printf("\nPart 1\n");

    printf("A ");
    printf("race ");
    printf("car ");
    printf("is fun to watch.\n");

    printf("\nPart 2\n");

    #pragma omp parallel
    {
        #pragma omp single
        {
            printf("A ");
            #pragma omp task
            { printf("race "); }
            #pragma omp task
            { printf("car "); }
            printf("is fun to watch.");
        }
    }
    printf("\n");

    return 0;
}
