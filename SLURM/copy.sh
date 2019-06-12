File=$1
Dest=$2

scp -i my.name.pem -P 37022 ${File} my.name@login01-hpc.urosario.edu.co:${Dest}

