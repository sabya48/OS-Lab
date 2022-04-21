#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  
#include <pthread.h>
  
void *copyfile()
{
    FILE *ptr_2 = fopen("f2.txt","w");
    FILE *ptr_1 = fopen("main.c","r");
    
    char c = fgetc(ptr_1);
    while (c != EOF)
    {
        fputc(c, ptr_2);
        c = fgetc(ptr_1);
    }
    fclose(ptr_1);
    fclose(ptr_2);
    fprintf(stderr,"File copied\n\n\n");
}

void *printfile()
{
    FILE *ptr_1 = fopen("f2.txt","r");
    fprintf(stderr,"Printing file\n\n");
    char c = fgetc(ptr_1);
    while(c!=EOF)
    {
        fprintf(stderr,"%c",c);
        c = fgetc(ptr_1);
    }
    fprintf(stderr,"\n\n\nFile Printing complete\n");
}
   
void *delete_file()
{
    remove("f2.txt");
    fprintf(stderr,"File Deleted\n");
}

int main()
{
    pthread_t thread_id1, thread_id2, thread_id3;
    
    // Copy file
    pthread_create(&thread_id1, NULL, copyfile, NULL);
    pthread_join(thread_id1, NULL);
    
    // Print file
    pthread_create(&thread_id2, NULL, printfile, NULL);
    pthread_join(thread_id2, NULL);
    
    // Delete file
    pthread_create(&thread_id3, NULL, delete_file, NULL);
    pthread_join(thread_id3, NULL);
    
    return 0;
}