// Name: SABYASACHI SARKAR
// Roll No: 1901CS48

### Compilation

```
gcc P1.c -o P1
```

### Execution Syntax

```
./P1
```

### Example 1:

```
./P1
```

```
Bankers Algorithm

Enter the number of processes
5
Enter the number of recources
3
Enter the allocated resources in matrix form.
A[i][j] will represent how much jth resource is allocated to ith process.
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2
Enter the maximum required resources in matrix form.
M[i][j] will represent maximum requirement of jth resource ith process.
7 5 3
3 2 2
9 0 2
2 2 2
4 3 3
Enter the available amount of every resource.
3
3
2


Number of safe sequences available is 16
The safe sequences are as follows

P2 P4 P1 P3 P5

P2 P4 P1 P5 P3

P2 P4 P3 P1 P5

P2 P4 P3 P5 P1

P2 P4 P5 P1 P3

P2 P4 P5 P3 P1

P2 P5 P4 P1 P3

P2 P5 P4 P3 P1

P4 P2 P1 P3 P5

P4 P2 P1 P5 P3

P4 P2 P3 P1 P5

P4 P2 P3 P5 P1

P4 P2 P5 P1 P3

P4 P2 P5 P3 P1

P4 P5 P2 P1 P3

P4 P5 P2 P3 P1
```
