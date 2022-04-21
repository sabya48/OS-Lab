#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    int n = 10;
    printf("Enter the number of orphan processes\n");
    scanf("%d", &n);
    int cntr = 0;
    int ifPrnt = 1;
    for(cntr = 0; cntr < n; cntr++)
    {
        if(fork() == 0)
        {
            // If current process is not a parent process
            // Do not fork further, proceed to sleep
            ifPrnt = 0;
            break;
        }
    }
    if(ifPrnt == 1)
    {
        fprintf(stderr, "Parent process terminated (Before Child Processes).\n");
    }
    else
    {
        sleep(100);
        // This won't print, since the parent process
        // has already terminated
        fprintf(stderr,"Child Process Terminating.\n");
    }
}