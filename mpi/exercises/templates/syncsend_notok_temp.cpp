#include <cstdio>
#include <cstdlib>
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

  //Need at least 2 processes
  if(size < 2){
    printf("World size must be greater than 1\n");
    MPI_Abort(MPI_COMM_WORLD, 1);
  }

  int message1;
  char message2;
  
  if(rank == 0){
    //Initialize messages
    message1 = 5;
    message2 = 'e';
    //tags
    int tag1 = 1;
    int tag2 = 2;
    //receiver
    int other = 1;
    
    //Send fist message
    printf("Sending message 2...\n");
    .
    .
    //Send second message
    printf("Sending message 1...\n");
    .
    .
  }else if(rank == 1){
    //tags
    int tag1 = 1;
    int tag2 = 2;
    //sender
    int other = 0;
    
    //Receive second message
    .
    .
    printf("I received message 2: %c\n",message2);
    //Receive first message
    .
    .
    printf("I received message 1: %d\n",message1);
  }
  
  //Exit the mpi environment ------------------------------------
  MPI_Finalize();
  //-------------------------------------------------------------

  return 0;
}

