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

  int data_size = 10*size;
  
  //Get local size of array and allocate memmory---------------
  int local_data_size = data_size / size;
  int *local_data = new int[local_data_size];

  //total data
  int *data;
  if(rank == 0){
    //Allocate data and initialize it
    printf("rank %d allocating data...\n",rank);
    data = new int[data_size];
    for(int i = 0; i < data_size; i++)
      data[i] = i;
    printf("data initialized.\n");
    printf("Scattering data...\n");
  }
  //Scatter the data
  .
  .

  printf("I, rank %d, have recieved from %d to %d.\n", rank,
	 local_data[0],local_data[local_data_size-1]);
  
  delete[] local_data;
  if(rank == 0)
    delete[] data;

  MPI_Finalize();
  
  return 0;
}
