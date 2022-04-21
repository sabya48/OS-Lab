#include <stdio.h>
#include <pthread.h>

void *func(void *arg)
{
    int *idx = (int *)arg;

    if (*idx == 9)
    {
        pthread_cancel(pthread_self());
    }

    printf("Thread %d : Hello World!\n", *idx);

    return (void *)idx;
}

int main()
{
    int idx[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    pthread_t t[10];

    for (int i = 0; i < 10; i++)
    {
        pthread_create(&t[i], NULL, func, idx + i);
    }

    for (int i = 0; i < 10; i++)
    {
        int *status;
        if (!pthread_join(t[i], (void **)&status))
        {
            if (status == PTHREAD_CANCELED)
            {
                printf("i = %d, status = CANCELED\n", i);
            }
            else
            {
                printf("i = %d, status = THREAD %d\n", i, *status);
            }
        }
    }
    return 0;
}