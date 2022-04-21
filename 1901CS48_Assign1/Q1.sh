#!/bin/bash
# Problem 1

if [ $# -eq 0 ]
then
    echo "Error: Argument is not there.\n"

elif [ $# -gt 1 ]
then
    echo "Error: Too many arguments.\n"

else
    N=$1
    RES=0
    while [ $N -ne 0 ]
    do
        RES=$(($RES * 10 + $N % 10))
        N=$(($N / 10))
    done
    echo $RES
fi