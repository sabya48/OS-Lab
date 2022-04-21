#### Name: Sabyasachi Sarkar

#### Roll No: 1901CS48

NOTE: Commands are typed like

```
command
```

## Problem 1

### Compilation

```
g++ P1.cpp -o P1
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
3
4 7 6 1 7 6 1 2 7 2

F1		F2		F3
X		X		X		at time 0
4		X		X		at time 1
4		7		X		at time 2
4		7		6		at time 3
1		7		6		at time 4
1		7		6		at time 5
1		7		6		at time 6
1		7		6		at time 7
2		7		6		at time 8
2		7		6		at time 9
2		7		6		at time 10
#Page Faults: 5
```

## Problem 2

### Compilation

```
g++ P2.cpp -o P2
```

### Execution Syntax

```
./P2
```

### Example 1:

```
./P2
```

```
6
1 2 3 4 2 7 5 1 1 6 4 7 2 1 2 5

F1		F2		F3		F4		F5		F6
X		X		X		X		X		X		at time 0
1		X		X		X		X		X		at time 1
1		2		X		X		X		X		at time 2
1		2		3		X		X		X		at time 3
1		2		3		4		X		X		at time 4
1		2		3		4		X		X		at time 5
1		2		3		4		7		X		at time 6
1		2		3		4		7		5		at time 7
1		2		3		4		7		5		at time 8
1		2		3		4		7		5		at time 9
1		2		6		4		7		5		at time 10
1		2		6		4		7		5		at time 11
1		2		6		4		7		5		at time 12
1		2		6		4		7		5		at time 13
1		2		6		4		7		5		at time 14
1		2		6		4		7		5		at time 15
1		2		6		4		7		5		at time 16
#Page Faults: 7
```
