/*
 *    i  j -------------> n
 *    | 00   01 ... 0n-1
 *    | 10   11
 *    | 20
 *    | .
 *    v m-10 ...... m-1n-1
 *    m
 */

#include "pgmio.hpp"


/*
 *  Routine to get the size of a PGM data file
 *
 *  Note that this assumes a single line comment and no other white space.
 */
void pgmsize(string filename, int &m, int &n){
  ifstream fp;
  fp.open(filename, ios::in);
  if(fp.fail()){
    cerr << "pgmsize: cannot open <" << filename << ">\n";
    exit(-1);
  }

  int ml = MAXLINE;
  char dummy[MAXLINE];
  fp.getline(dummy,ml);
  fp.getline(dummy,ml);

  fp >> n >> m;
  
  fp.close();
}


/*
 *  Routine to read a PGM data file into a 2D floating point array
 *  vx[nx][ny].
 *
 *  Note that this assumes a single line comment and no other white space.
 */
void pgmread(string filename, float *vx, int m, int n){
  ifstream fp;
  fp.open(filename, ios::in);
  if(fp.fail()){
    cerr << "pgmread: cannot open <" << filename << ">\n";
    exit(-1);
  }

  int ml = MAXLINE;
  char dummy[MAXLINE];
  fp.getline(dummy,ml);
  fp.getline(dummy,ml);
  
  int mt, nt;
  fp >> nt >> mt;
  if(mt != m || nt != n){
    cerr << "pgmread: size mismatch, (m,n) = (" << mt << ","
	 << nt << ") expected (" << m << "," << n << ")\n";
    exit(-1);
  }

  int t;
  fp >> t;

  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){  
      fp >> vx[i*n+j];
      //cout << vx[i*n+j] << " ";
    }
  }
  
  fp.close();
}


/*
 *  Routine to write a PGM image file from a 2D floating point array
 *  x[nx][ny].
 */
void pgmwrite(string filename, float *vx, int m, int n){
  ofstream fp;
  fp.open(filename, ios::out);
  if(fp.fail()){
    cerr << "pgmwrite: cannot open <" << filename << ">\n";
    exit(-1);
  }
  
  cout << "Writing " << n << " x "<< m << " picture into file: "
       << filename << "\n";

  /*
   *  Find the max and min absolute values of the array
   */
  float xmin = fabs(vx[0]);
  float xmax = fabs(vx[0]);
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      if(fabs(vx[i*n+j]) < xmin) xmin = fabs(vx[i*n+j]);
      if(fabs(vx[i*n+j]) > xmax) xmax = fabs(vx[i*n+j]);
    }
  }
  if(xmin == xmax) xmin = xmax-1.0;

  float thresh = 255.0;
  
  fp << "P2\n";
  fp << "# Written by pgmio::pgmwrite\n";
  fp << n << " " << m << "\n";
  fp << int(thresh) << "\n";
  
  double fval;
  int grey, k = 0;
  for(int i = 0; i < m; i++){
    for(int j = 0; j < n; j++){
      /*
       *  Scale the value appropriately so it lies between 0 and thresh
       */
      fval = thresh*((fabs(vx[i*n+j])-xmin)/(xmax-xmin))+0.5;
      grey = int(fval);

      fp << setw(3) << grey << " ";

      if(0 == (k+1)%18) fp << "\n";

      k++;
    }
  }
  
  if(0 != (k+1)%18) fp << "\n";
  fp.close();
}




  
