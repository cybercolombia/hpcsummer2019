#include <cstdio>
#include <cstdlib>
#include <mpi.h>
using namespace std;

int main(){
  
  //initialize mpi environment and get rank/size-----------------
  MPI_Init(NULL, NULL);
  //Find out rank, size
  int rank, size;
  MPI_Comm comm = MPI_COMM_WORLD; //Communicator
  MPI_Comm_rank(comm, &rank);
  MPI_Comm_size(comm, &size);
  //-------------------------------------------------------------

  int value = rank;
  printf("I, rank %d, have the value %d.\n",rank,value);

  int sum;
  //Add the values of all the processes and store them in sum
  .
  .

  if(rank == 0)
    printf("The sum is %d\n",sum);
  
  MPI_Finalize();

  return 0;
}
