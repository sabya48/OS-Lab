#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main()
{
    int n = 10;
    printf("Enter the length of lucas series\n");
    scanf("%d", &n);

    fflush(0);
    int temp = 0;

    // Create first child process
    if(fork() == 0)
    {
        fflush(stdout);

        // Calculate lucas series
        int lucas[n + 2];
        lucas[0] = 2;
        lucas[1] = 1;
        int i = 0;
        for(i = 2; i < n; i++)
        {
            lucas[i] = lucas[i - 1] + lucas[i - 2];
        }

        // Create file and store lucas series there
        FILE *fptr;
        fptr = fopen("lucas.txt", "w");
        rewind(fptr);
        for(i = 0; i < n; i++)
        {
            fprintf(fptr, "%d\n", lucas[i]);
        }
        fclose(fptr);
    }
    else 
    {
        fflush(stdout);

        // Wait for first child to finish
        while(wait(NULL) > 0);

        // Create second child process
        if(fork() == 0)
        {
            int i = 0;
            FILE *fptr;
            fptr = fopen("program.txt", "r+");
            rewind(fptr);

            // Print lucas series stored by first child
            for(i = 0; i < n; i++)
            {
                char ss[100];
                fgets(ss, 100, fptr);
                printf("%s", ss);
                fflush(stdout);
            }
            fclose(fptr);
        }
        while(wait(NULL) > 0);
        
    }
    while(wait(NULL) > 0);
    fflush(stdout);

    return 0;
}