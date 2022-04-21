#!/bin/bash
# Problem 4
if [ $# -ne 1 ]; 
then
	echo "Error: Missing / Invalid arguments"
	echo "Note: Enter the password in double quotes as input. Or escape special characters if any."
	exit 1
fi

# Storing password and length
password=$1
length=${#password}
echo "Password Entered: $1"
echo "Length of Password: $length"

# Characters for matching
alpha="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
numbers="0123456789"
special="/()<>?"

# A function to check if one of the characters from a set of characters is present in passwors string
function findPresence() {
	# $1 is basically the set of characters whose presence is to be checked
	set=$1
	for ((i = 0; i < $length; ++i))
    do
		for ((j = 0; j < ${#set}; ++j))
        do
			if [ ${password:i:1} == ${set:j:1} ]; 
			then
				echo 1
				return
			fi
		done
	done
	echo 0
    return					
}

# Validating presence of characters as per problem statement
if [ $length -ge 7 ] && [ $(findPresence "$alpha") -eq 1 ]  && [ $(findPresence "$numbers") -eq 1 ] && [ $(findPresence "$special") -eq 1 ]; then
	echo "<Valid Password>"
else
	echo "<Invalid Password>"
fi