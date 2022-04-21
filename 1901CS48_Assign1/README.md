To add executable permissions to the shell scripts, type the following commands:

sudo chmod a+rx P1.sh
sudo chmod a+rx P2.sh
sudo chmod a+rx P3.sh
sudo chmod a+rx P4.sh

Problem 1:
Run and test using the following commands

./P1.sh 234
Output: 432

./P1.sh 15
Output: 51

./P1.sh -59
Output: -95

./P1.sh -10
Output: -1


Problem 2:

./P2.sh
Input:
15
19
Output:
15 16 17 18 19

./P2.sh
Input:
21
20
Output:
Error: Invalid Order of Input.


Problem 3:

./P3.sh a.txt
Output: 
Error: Invalid number of arguments.

./P3.sh a.txt 2
Number of lines in file: 1
Therefore, deleting...

Problem 4:
./P4.sh 
Input:
Enter directory_path: /home/abhayiitp/Desktop/Test
Enter filename_pattern: abcd
Enter the new_filename: lda

Due to this filenames with subsequences abcd present are changed to lda_1, lda_2....





