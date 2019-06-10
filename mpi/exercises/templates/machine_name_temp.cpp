#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <mpi.h>

int main(){

  //initialize mpi environment and get rank/size-----------------
  MPI_Init(NULL, NULL);
  //Find out rank, size
  int rank, size;
  MPI_Comm comm = MPI_COMM_WORLD; //Communicator
  MPI_Comm_rank(comm, &rank);
  MPI_Comm_size(comm, &size);
  //-------------------------------------------------------------

  int namelen;
  char procname[MPI_MAX_PROCESSOR_NAME];

  //Get the name of the machine that runs the process
  .
  .
    
  printf("Rank %d is on machine %s\n", rank, procname);
  
  MPI_Finalize();

  return 0;
}
