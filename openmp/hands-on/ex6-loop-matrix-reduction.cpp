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

    int j,k,l;
    int Nt = 10, Nr1 = 8, Nc2 = 12; // Nt transaction elements
    Crandom r(10);
    double **m1,**m2,**res;
    double norm_v1;

    CREATEMATRIX(m1,double,Nr1,Nt,r.gaussian(0,0.5));
    CREATEMATRIX(m2,double,Nt,Nc2,r.n(-10,10));
    CREATEMATRIX(res,double,Nr1,Nc2,0);

    PRINTMATRIX(m1,Nr1,Nt);
    PRINTMATRIX(m2,Nt,Nc2);

    for(j = 0; j < Nr1; j++)
        for(k = 0; k < Nc2; k++)
            for(l = 0; l < Nt; l++)
                res[j][k] += m1[j][l]*m2[l][k];

    PRINTMATRIX(m1,Nr1,Nc2);

    return 0;
}
