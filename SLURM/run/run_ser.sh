#!/bin/bash

#SBATCH -J test               # Job name
#SBATCH -o job.%j.out         # Name of stdout output file (%j expands to jobId)
#SBATCH -c 1                  # Number of cores per task
#SBATCH -t 00:30:00           # Run time (hh:mm:ss) - 0.5 hours

# Set OMP_NUM_THREADS to the same value as -c
# with a fallback in case it isn't set.
# SLURM_CPUS_PER_TASK is set to the value of -c, 
# but only if -c is explicitly set

# Launch executable

prog=$1
arg1=$2

srun ./${prog} ${arg1}

