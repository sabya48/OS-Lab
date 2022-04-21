#!/bin/bash
# Problem 1
# As per the problem, first argument N will be number of elements in array
# Next N arguments will be the elements of array.
# Last element will be the number to be searched.

# Storing CLA into array
arr=(${@:2:$(($1))})

# Result Index and element to be searched
idx=-1
search=${!#}

# Iterating the array to check for element of interest
for i in "${!arr[@]}";
do
    if [ ${arr[$i]} -eq $search ]
    then
        idx=$i
    fi
done

# If valid index, then found else not
if [ $idx -ne -1 ]
then
    echo "Element $search found at index $idx."
else
    echo "Element not found."
fi