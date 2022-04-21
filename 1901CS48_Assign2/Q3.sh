#!/bin/bash
# Problem 3
# We define a function to find and print XOR value
xor () {
    a=$1
    b=$2
    res=0
    pw=1
    # Take the numbers bit by bit
    while [[ a -gt 0 ]] || [[ b -gt 0 ]]
    do
        a_bin=$(($a % 2))
        b_bin=$(($b % 2))
        xr=$(($a_bin * !$b_bin + !$a_bin * $b_bin))
        # Keep adding in the result
        res=$(($res + $xr * $pw))
        a=$(($a / 2))
        b=$(($b / 2))
        pw=$(($pw * 2))
    done
    echo "XOR Value = $res"
}
if [[ $# -ne 2 ]]
then
    echo "Error: Please enter 2 integers as arguments."
    exit 1
else
    xor $1 $2
fi

