#include <cstdio>
#include <cstdlib>
#include <mpi.h>

int main(int argc, char* argv[]){

  //initialize mpi environment and get rank/size-----------------
  MPI_Init(NULL, NULL);
  //Find out rank, size
  int rank, size;
  MPI_Comm comm = MPI_COMM_WORLD; //Communicator
  MPI_Comm_rank(comm, &rank);
  MPI_Comm_size(comm, &size);
  //-------------------------------------------------------------

  //Need at least 2 processes
  if(size < 2){
    printf("World size must be greater than 1\n");
    MPI_Abort(MPI_COMM_WORLD, 1);
  }

  //Allocate memmory for array
  int N = atoi(argv[1]);
  int *myDynarr = new int[N];

  if(rank == 0){
    int other = 1;
    int tag = 0;
    //Set array to -1
    for(int i = 0; i < N; ++i)
      myDynarr[i] = -1;
    printf("Process %d sends data to process %d\n",rank,other);
    
    //Send array to process 1
    .
    .
    .
  }else if(rank == 1){
    int other = 0;
    int tag = 0;
    //Receive the array from process 0
    .
    .
    .
    
    //Print the data
      printf("Process %d received from process %d:\n",rank,other);
    for(int i = 0; i < N ; ++i)
      printf("%d ",myDynarr[i]);
    printf("\n");
  }

  //Free memory
  delete[] myDynarr;
  
  //Exit the mpi environment ------------------------------------
  MPI_Finalize();
  //-------------------------------------------------------------

  return 0;
}
