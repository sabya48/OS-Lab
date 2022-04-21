#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
	// We can build a tree which shows 9 nodes and 5 leafs for 
	// the process execution. 5 leafs means, 4 children and 1 parent
	// are there in the end.
	if (fork() || fork()) 
		fork();
	printf("Hello ");
	return 0;
}