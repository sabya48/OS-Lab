#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
// Argument Format:
// script1_name N n1 n2 n3 ... nN S script2_name N
int main(int argc, char* argv[]) {
	pid_t PID = fork();
	// Parent: Task 2
	if (PID) {
		// Parsing arguments and separating them out
		char *argv_t2[3];
		argv_t2[0] = argv[argc - 2];
		argv_t2[1] = argv[argc - 1];
		argv_t2[2] = NULL;
		char *script = argv[argc - 2];
		execv(script, argv_t2);
		printf("ERROR: execv() did not execute properly.");
	}
	// Child: Task 1
	else {
		// Parsing arguments and separating them out
		char* argv_t1[argc - 2];
		argv_t1[0] = argv[1];
		for (int i = 1; i < argc - 3; i++) {
			argv_t1[i] = argv[i + 1];
		}
		argv_t1[argc - 3] = NULL;
		char *script = argv[1];
		execv(script, argv_t1);
		printf("ERROR: execv() did not execute properly.");
	}
	return 0;
}