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

    char hostname[INFO_BUFFER_SIZE];
    char username[INFO_BUFFER_SIZE];

    printf("\nPart 1\n");

    #pragma omp parallel
    {
    gethostname(hostname, INFO_BUFFER_SIZE);
    getlogin_r(username, INFO_BUFFER_SIZE);

    printf("Hostname %s in thread %d\n",hostname,omp_get_thread_num());
    printf("Username %s in thread %d\n",username,omp_get_thread_num());
    } /*-- End of parallel region --*/

    printf("\nPart 2\n");

    #pragma omp parallel
    {
    gethostname(hostname, INFO_BUFFER_SIZE);
    getlogin_r(username, INFO_BUFFER_SIZE);

    cout<<"Hostname "<<hostname<<" in thread "<<omp_get_thread_num()<<endl;
    cout<<"Username "<<username<<" in thread "<<omp_get_thread_num()<<endl;
    } /*-- End of parallel region --*/

    return 0;
}
