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

    printf("\nPart 1\n");

    #pragma omp parallel
    {
        int TID = omp_get_thread_num();
        sleep(omp_get_thread_num());

        printf("In parallel region - Thread ID is %d\n",TID);
    } /*-- End of parallel region --*/

    printf("\nPart 2\n");

    int extra_time = 0;
    #pragma omp parallel
    {
        int TID = omp_get_thread_num();
        #pragma omp master
        {
            printf("\tInside Block - Thread ID is %d\n",TID);
            sleep(1);
            extra_time = 1;
        }
        sleep(TID+extra_time);
        printf("In parallel region - Thread ID is %d\n",TID);
    } /*-- End of parallel region --*/

    return 0;
}
