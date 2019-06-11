#!/bin/bash

#SBATCH -J test               # Job name
#SBATCH -o job.%j.out         # Name of stdout output file (%j expands to jobId)
#SBATCH -N 3                  # Total number of nodes requested
#SBATCH -n 96                 # Total number of mpi tasks requested
#SBATCH -t 00:30:00           # Run time (hh:mm:ss) - 0.5 hours

# Launch MPI-based executable

prog=$1
arg1=$2

prun ./${prog} ${arg1}

