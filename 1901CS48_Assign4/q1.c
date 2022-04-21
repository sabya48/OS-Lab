#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    int n = 10;
    printf("Enter the value of n: \n");
    scanf("%d", &n);
    int cntr=0;
    int ifPrnt = 1;
    for(cntr = 0; cntr < n; cntr++)
    {
        if(fork() == 0)
        {
            // If current process is not the parent
            // do not fork further
            // Proceed to exit
            ifPrnt = 0;
            break;
        }
    }
    if(ifPrnt == 1)
    {
        sleep(60);
        fprintf(stderr,"\n\nExiting Parent process.\n");
    }
    else
    {
        fprintf(stderr,"Exiting child process - %d\n",getpid());
        exit(0);
    }
}