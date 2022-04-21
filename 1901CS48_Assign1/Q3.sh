#!/bin/bash
# Problem 3
if [ $# -ne 2 ] 
then
    echo "Error: Invalid number of arguments."

else
    FILE_NAME=$1
    NUM_OF_LINES=$2
    TOTAL=0
    while read -r line || [ -n "$line" ]
    do
        TOTAL=$(($TOTAL + 1))
    done  < "$FILE_NAME"
    
    echo "Number of lines in file: $TOTAL"

    if [ $TOTAL -lt $NUM_OF_LINES ]
    then
        echo "Therefore, deleting..."
        rm -f $FILE_NAME
    fi
fi