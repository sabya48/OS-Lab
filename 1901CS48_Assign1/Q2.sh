#!/bin/bash
# Problem 2
read A
read B
if [ $A -gt $B ]
then
    echo "Error: Invalid Order of Input."

else 
    while [ $A -le $B ]
    do
        echo -n "$A "
        A=$(($A + 1)) 
    done
    echo ""
fi
