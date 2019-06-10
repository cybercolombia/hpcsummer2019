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

  //process 0 has a lot to do.. 
  if(rank == 0){
    printf("Wait! I'm stil busy...\n");
    double res = 1.;
    for(int i = 0; i < 1e6; i++)
      res *= cos(res)/res;
    printf("Ok. I'm done, we can continue.\n");
  }

  //Place the barrier (wait until all get here)
  .
  .

  //after all processes get to the barrier, continue...
  printf("Hello, world.  I am %d of %d\n", rank, size);
  
  MPI_Finalize(); 
  
  return 0;
}
