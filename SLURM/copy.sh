File=$1
Dest=$2

#echo carlosedu.alvarez.pem -P 37022 ${File} carlosedu.alvarez@login01-hpc.urosario.edu.co:${Dest}

scp -i workshop.hpc.pem -P 37022 ${File} workshop.hpc@login01-hpc.urosario.edu.co:${Dest}

