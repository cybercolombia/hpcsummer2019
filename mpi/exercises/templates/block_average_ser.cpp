#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include <sys/time.h>
using namespace std;


double gettime(){
  struct timeval tp;
  gettimeofday (&tp, NULL);
  return tp.tv_sec + tp.tv_usec/(double)1.0e6;
}

double average(double* data, int start, int end){
  double av = 0.;
  for(int i = start; i < end; i++){
    av += data[i];
  }
  return av/(end-start);
}

double variance(double av, double* data, int size){
  double dif, var = 0.;
  for(int i = 0; i < size; i++){
    dif = data[i] - av;
    var += dif*dif;
  }
  return var/(size-1);
}


int main(int argc, char* argv[]){
  int data_size = atoi(argv[1]);
  int size = atoi(argv[2]);

  int block_size = data_size / size;

  double *data;
  //allocate memmory
  data = new double[data_size];
  
  //read data
  ifstream input;
  input.open("data.dat");
  for(int i = 0; i < data_size; i++){
    input >> data[i];
  }
  input.close();

  //Starting time----------
  double tstart = gettime();
  
  double *part_av = new double[size];
  //Compute block averages
  for(int i = 0; i < size; i++){
    part_av[i] = average(data, i*block_size,(i+1)*block_size);
  }
  //Compute the total average
  double tot_av = 0.;
  for(int i = 0; i < size; i++)
    tot_av += part_av[i];
  tot_av /= size;
  printf("tot av: %f\n",tot_av);

  //Compute the total variance
  double tot_var = variance(tot_av, data, data_size);
  printf("tot var: %f\n",tot_var);

  //block average variance
  double block_var = variance(tot_av, part_av, size);
  printf("block var: %f\n",block_var);

  //Statistical inefficiency and corrected std dev
  double s = block_size * block_var / tot_var;
  double sig = sqrt(tot_var * s / size);
  printf("Corrected std dev: %f\n",sig);

  
  
  //Stoping time----------
  double tstop = gettime();
  printf("\nTime taken was  %f seconds\n", tstop-tstart);
  
  delete[] part_av;
  delete[] data;

  return 0;
}
