#!/bin/bash
# Problem 2

# Function to find sum of prime less than or equal to a number
function PrimeNoLessThan() {
	if (($1 < 2))
	then
		echo 0
	else
		for((i=2;i<$1;i++))
		do
			if [[ $(($1 % $i)) -eq 0 ]]
			then
                # Not a prime number
				echo $(PrimeNoLessThan $(( $1 - 1)) )
				return
			fi
		done
        # Prime number, therefore add
		echo $(( $1 + $(PrimeNoLessThan $(( $1 - 1))) ))
	fi
}

# Recursive function to calculate factorial of a number
function fact() { 
    # Base case
    if (( $1 < 2 ))
    then
        echo 1
    else	
        # Recursive call
        echo $(( $1 * $(fact $(( $1 - 1 ))) ))
    fi
}

if [ $# -ne 1 ]
then
	echo "Error: Input format is incorrect"
	exit 1
fi

echo "The required answer is : $(( $(PrimeNoLessThan $1) * $(fact $1) ))"