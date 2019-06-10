#include <cstdio>
#include <cstdlib>
#include <mpi.h>
using namespace std;

int main(){
  int value;
  
  //initialize mpi environment and get rank/size-----------------
  MPI_Init(NULL, NULL);
  //Find out rank, size
  int rank, size;
  MPI_Comm comm = MPI_COMM_WORLD; //Communicator
  MPI_Comm_rank(comm, &rank);
  MPI_Comm_size(comm, &size);
  //-------------------------------------------------------------
  
  //If I am rank 0
  if(rank == 0){
    //initialize value
    value = 3;
    printf("I, rank %d, will send number %d to all ranks.\n",
	   rank,value);
  }
  //send from 0 to all other processes
  .
  .
  
  printf("I, rank %d, recieved number %d.\n",rank,value);

  MPI_Finalize();
  
  return 0;
}
