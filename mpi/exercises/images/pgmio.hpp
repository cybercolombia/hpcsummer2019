#ifndef _PGMIO_HPP
#define _PGMIO_HPP

#include <cmath>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

#define MAXLINE 128


void pgmsize(string filename, int &m, int &n);
void pgmread(string filename, float *vx, int m, int n);
void pgmwrite(string filename, float *vx, int m, int n);

#endif
