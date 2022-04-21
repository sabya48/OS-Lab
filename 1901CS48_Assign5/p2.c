#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  
#include <pthread.h>

char file_name [] = "Test.txt";
int max_lines = 100;
int num_char = 0;
int isPrime(int n)
{
    int divs = 0;
    int i;
    for(i=1;i<=n;i++)
    {
        if(n%i==0) divs++;
    }
    
    if(divs==2) return 1;
    else return 0;
}

void *write_composite_lines(void *param)
{
    FILE *fptr = fopen("file_name","w");
    int i;
    for(i=1;i<=max_lines;i++)
    {
        char line1[] = "Line added by composite\n";
        char line2[] = "\n";
        if(isPrime(i))
        {
            fprintf(fptr,line2);
            num_char += 16;
        }
        else
        {
            fprintf(fptr,line1);
        }
    }
    fclose(fptr);
}

void *write_prime_lines()
{
    FILE *fptr = fopen("file_name","w");
    int i;
    for(i=1;i<=max_lines;i++)
    {
        char line1[] = "Line added by Prime\n";
        char line2[] = "\n";
        if(!isPrime(i))
        {
            fprintf(fptr,line2);
            num_char += 14;
        }
        else
        {
            fprintf(fptr,line1);
        }
    }
    fclose(fptr);
}
   
int main()
{
    pthread_t thread_id1,thread_id2;
 
    pthread_create(&thread_id1, NULL, write_composite_lines, NULL);
    pthread_create(&thread_id2, NULL, write_prime_lines, NULL);
    pthread_join(thread_id1, NULL);
    pthread_join(thread_id2, NULL);
    fprintf(stderr,"Total Characters Printed: %d",num_char);
    return 0;
}