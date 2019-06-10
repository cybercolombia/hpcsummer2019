#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <mpi.h>
using namespace std;

double gettime(){
  return MPI_Wtime();
}

double average(double* data, int size){
  double av = 0.;
  for(int i = 0; i < size; i++){
    av += data[i];
  }
  return av/size;
}

double variance(double av, double* data, int size){
  double dif, var = 0.;
  for(int i = 0; i < size; i++){
    dif = data[i] - av;
    var += dif*dif;
  }
  return var/(size-1);
}

double part_variance(double av, double* data, int size){
  double dif, var = 0.;
  for(int i = 0; i < size; i++){
    dif = data[i] - av;
    var += dif*dif;
  }
  return var;
}

int main(int argc, char* argv[]){
  
  //initialize mpi environment and get rank/size-----------------
  MPI_Init(NULL, NULL);
  //Find out rank, size
  int rank, size;
  MPI_Comm comm = MPI_COMM_WORLD; //Communicator
  MPI_Comm_rank(comm, &rank);
  MPI_Comm_size(comm, &size);
  //-------------------------------------------------------------
  
  int data_size = atoi(argv[1]);
  double *data;
  if(rank == 0){
    //allocate memmory
    data = new double[data_size];
    
    //read data
    ifstream input;
    input.open("data.dat");
    for(int i = 0; i < data_size; i++){
      input >> data[i];
    }
    input.close();
  }

  //Your code--------------
  .
  .
  .
  .
  //-----------------------
  
  if(rank == 0)
    delete[] data;
    
  MPI_Finalize();
  
  return 0;
}
