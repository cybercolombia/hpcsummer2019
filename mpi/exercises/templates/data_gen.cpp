#include <iostream>
#include <chrono>
#include <random>
#include <fstream>
using namespace std;

int main(){
  int N = 1000000;

  //Generador de números aleatorios---------------------------
  unsigned seed = chrono::system_clock::now().time_since_epoch().count();
  minstd_rand0 rng(seed);
  //Generación de lista de enteros aleatorios
  int numeros[N];
  for(int i = 0; i < N; i++){
    numeros[i] = int(100*(double(rng())/rng.max()));
  }
  //---------------------------------------------------------

  ofstream output;
  output.open("data.dat");
  for(int i = 0; i < N; i++)
    output << numeros[i] << endl;
  output.close();
  
  
  return 0;
}
