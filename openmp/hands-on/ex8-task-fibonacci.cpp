#include <iostream>
#include <fstream>
#include <unistd.h>
#include <limits>
#include <cmath>
#include <sys/time.h>

#include "defs.h"
#define INFO_BUFFER_SIZE 1024

using namespace std;

int fib(int);

int main(int argc, char *argv[]){
#ifdef _OPENMP
    printf("**MESSAGE** OpenMP enabled\n");
    (void) omp_set_dynamic(FALSE);
    if (omp_get_dynamic()) {printf("\t**Warning** dynamic adjustment of threads has been set\n");}
    (void) omp_set_num_threads(8);
#else
    printf("**MESSAGE** OpenMP disabled\n");
#endif

    int N;
    printf("Enter a positive integer ");
    scanf("%d",&N);

    printf("\nPart 1\n");

    printf("Fib[%d] = %d\n",N,fib(N));

    return 0;
}


int fib(int x){
    if(x == 0 || x == 1)
        return 1;
    else
        return fib(x-1) + fib(x-2);
}
