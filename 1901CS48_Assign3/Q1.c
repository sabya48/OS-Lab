#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

// When piping fails
void failPipe() {
	printf("ERROR: Pipe did not open as expected.");
    exit(2);
}

// When forking fails
void failFork() {
	printf("ERROR: Fork failed.");
    exit(3);
}

int main(int argc, char* argv[]) {
	if (argc != 3) {
		printf("Invalid number of arguments. \n");
		return 1;
	}

    int a, b;
    sscanf(argv[1], "%d", &a);
    sscanf(argv[2], "%d", &b);

    int fd1[2]; // File Descriptor for comm with Child 1
    int fd2[2]; // File Descriptor for comm with Child 2

    if (pipe(fd1) == -1 || pipe(fd2) == -1) failPipe();

    pid_t PID = fork();

    if (PID < 0) failFork();

    // Parent
    if (PID) {
    	int sum, product;
    	read(fd1[0], &sum, sizeof(int));
    	read(fd2[0], &product, sizeof(int));
    	printf("Division by Parent %d: %d\n", getpid(), product / sum);
    } 
    else {
    	PID = fork();
    	if (PID < 0) failFork();
    	// Child 1
    	if (PID) {
    		int res = a + b;
    		printf("Sum by Child %d: %d\n", getpid(), res);
    		write(fd1[1], &res, sizeof(int));
    	}
    	// Child 2
    	else {
    		int res = a * b;
    		printf("Multiplication by Child %d: %d\n", getpid(), res);
    		write(fd2[1], &res, sizeof(int));
    	}
    }
    return 0;
}
