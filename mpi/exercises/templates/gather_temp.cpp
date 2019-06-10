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

  //Get local size of array and allocate memmory---------------
  int local_data_size = 10;
  int *local_data = new int[local_data_size];
  for(int i = 0; i < local_data_size; i++){
    local_data[i] = rank*local_data_size + i;
  }
  printf("I, rank %d, send from %d to %d.\n", rank,
	local_data[0],local_data[local_data_size-1]);
  
  //total data
  int *data;
  int data_size = local_data_size * size;
  if(rank == 0){
    //Allocate
    data = new int[data_size];
  }
  //Gather data
  .
  .
  
  if(rank == 0){
    printf("I, rank %d, have recieved from %d to %d.\n",rank,
	   data[0],data[data_size-1]);
  }
  
  delete[] local_data;
  if(rank == 0)
    delete[] data;
  
  MPI_Finalize();
  
  return 0;
}
