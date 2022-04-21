## Name: Sabyasachi Sarkar

## Roll Number: 1901CS48

## Adding permissions

To add executable permissions to the shell scripts, type the following commands:

sudo chmod a+rx task1.sh
sudo chmod a+rx task2.sh

## Problem 1:

Compilation:
gcc Q1.c -o Q1

Syntax:
./Q1 {number 1} {number 2}

Examples of execution:

./Q1 8 8
Output:
Sum by Child 54631: 16
Multiplication by Child 54632: 64
Division by Parent 54630: 4

./Q1 2 2
Output:
Sum by Child 54680: 4
Multiplication by Child 54681: 4
Division by Parent 54679: 1

## Problem 2:

Compilation:
gcc Q2.c -o Q2

Syntax:
./Q2

Examples of execution:

./Q2
Output:
Hello Hello Hello Hello Hello

## Problem 3:

Compilation:
gcc Q3.c -o Q3

Syntax:
./Q2 {Script Name for task 1} {Task 1 arguments} {Script Name for task 2} {Task 2 arguments}

Examples of execution:

./Q3 task1.sh 3 1 2 3 2 task2.sh 5
Output:
Element 2 found at index 1.
The required answer is : 1200

./Q3 task1.sh 4 1 2 3 4 3 task2.sh 3
Output:
Element 3 found at index 2.
The required answer is : 30
