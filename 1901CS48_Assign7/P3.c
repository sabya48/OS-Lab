// Name: SABYASACHI SARKAR
// Roll No: 1901CS48

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

int NUM_STUDENTS = 8;
int MAX_SLICES = 5;
int slices_left = 0;
sem_t order, deliver;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
int is_first = 1;
int has_pizza = 1;

void *student_thread(void *s_id)
{
    int *id = (int *)s_id;
    int student_id = *id;

    while (1)
    {
        pthread_mutex_lock(&lock);
        // fprintf(stderr,"Student ID %d\n",student_id);
        while (has_pizza == 0)
        {
            if (slices_left > 0)
            {
                slices_left--;
                fprintf(stderr, "Student %d ate a slice of pizza. %d Slices remain.\n", student_id, slices_left);
                has_pizza = 1;
            }
            else if (is_first)
            {
                fprintf(stderr, "Student %d saw that pizza is over. The pizza was ordered\n", student_id);
                sem_post(&order);
                is_first = 0;
            }
            else
            {
                sem_wait(&deliver);
            }
        }
        has_pizza = 0;
        pthread_mutex_unlock(&lock);
    }
}

void *delivery_thread()
{
    while (1)
    {
        pthread_mutex_lock(&lock);
        sem_wait(&order);
        slices_left = MAX_SLICES;
        is_first = 1;
        fprintf(stderr, "The pizza is was delivered.\n");
        sem_post(&deliver);
        pthread_mutex_unlock(&lock);
    }
}

int main()
{
    fprintf(stderr, "Enter number of Students.\n");
    scanf("%d", &NUM_STUDENTS);
    fprintf(stderr, "Enter number of slices.\n");
    scanf("%d", &MAX_SLICES);
    slices_left = MAX_SLICES;
    pthread_t student_threads[NUM_STUDENTS], del_thread;
    int student_id[NUM_STUDENTS];
    int i = 0;
    pthread_create(&del_thread, NULL, delivery_thread, NULL);
    for (i = 0; i < NUM_STUDENTS; i++)
    {
        student_id[i] = i + 1;
        pthread_create(&student_threads[i], NULL, student_thread, (void *)(student_id + i));
    }
    sleep(10);
    return 0;
}