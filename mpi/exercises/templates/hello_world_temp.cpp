#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <mpi.h>

int main(){

  //initialize mpi environment ----------------------------------
  .
  .
  
  int rank, size;
  MPI_Comm comm = MPI_COMM_WORLD; //Communicator
  //Find out rank, size
  .
  .
  .
  //-------------------------------------------------------------
  
  // Each process prints out its rank
  printf("Hello, world.  I am %d of %d\n", rank, size);

  //Exit the mpi environment ------------------------------------
  .
  .
  //-------------------------------------------------------------

  return 0;
}
