#!/bin/bash
# Problem 4
echo -n "Enter directory_path: "
read DIRECTORY
echo -n "Enter filename_pattern: "
read PATTERN
echo -n "Enter the new_filename: "
read NEW_FILE_NAME

cd $DIRECTORY

FILE_NUM=1

for FILE in *
do
    X=0
    FILE_NAME="$(basename -- "$FILE")"
    FILE_EXTENSION="${FILE_NAME##*.}"
    for ((i=0; i < ${#FILE_NAME} && X < ${#PATTERN}; i++))
    do
        if [ "${FILE_NAME:$i:1}" == ${PATTERN:$X:1} ]
        then
            X=$(($X + 1))
        fi
    done
    if [ $X -eq ${#PATTERN} ]
    then
        NEW_NAME=${NEW_FILE_NAME}_${FILE_NUM}.${FILE_EXTENSION}
        $(mv $FILE $NEW_NAME)
        ((FILE_NUM++))
    fi
done