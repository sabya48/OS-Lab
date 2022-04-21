### Name: Sabyasachi Sarkar
### Roll Number: 1901CS48

## Adding permissions

To add executable permissions to the shell scripts, type the following commands:

sudo chmod a+rx Q1.sh
sudo chmod a+rx Q2.sh
sudo chmod a+rx Q3.sh
sudo chmod a+rx Q4.sh

## Problem 1:
Syntax:
./Q1.sh {Number of elements in array} {Array elements, space separated} {Number to be searched}

Examples of execution:

./Q1.sh 2 2 3 4
Output: 
Element not found.

./Q1.sh 10 1 2 3 4 5 6 7 8 9 10 9
Output: 
Element 9 found at index 8.

## Problem 2:

Syntax:
./Q2.sh {Input Number}

Examples of execution:

./Q2.sh 5
Output:
The required answer is : 1200

./Q2.sh 7
Output:
The required answer is : 85680


## Problem 3:

Syntax:
./Q3.sh {Input Number 1} {Input Number 2}

Examples of execution:

./Q3.sh 5 9
Output:
XOR Value = 12

./Q3.sh 500 900
Output:
XOR Value = 624

### Time Analysis vs C program

#### Shell Program
time ./Q3.sh 500 900
Output: 
XOR Value = 624

real    0m0.051s
user    0m0.003s
sys     0m0.000s

#### C Program
gcc Q3.c -o Q3
time ./Q3 500 900
Output:
XOR Value = 624

real    0m0.003s
user    0m0.002s
sys     0m0.000s

## Problem 4:
Syntax:
./Q4.sh {Password string within quotes}

Examples of execution:

./Q4.sh "abcd76f"

Password Entered: abcd76f
Length of Password: 7
<Invalid Password>

./Q4.sh "abcd76f/"
Output:
Password Entered: abcd76f/
Length of Password: 8
<Valid Password>





