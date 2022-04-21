// Name: SABYASACHI SARKAR
// Roll No: 1901CS48

#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>

//declaring two semaphores
sem_t mutex, data;

//function A
void *A(void *arg) {
	sem_wait(&mutex);
	sem_wait(&data);
	printf("process A\n");
	sem_post(&data);
	sem_post(&mutex);
}

//function B
void *B(void *arg) {
	sem_wait(&mutex);
	sem_wait(&data);
	printf("process B\n");
	sem_post(&data);
	sem_post(&mutex);
}


int main(int argc, char **argv){
	//initialize the semaphores
	sem_init(&mutex, 0, 1);
	sem_init(&data, 0, 1);
	//stores thread ids
	pthread_t thread1, thread2;

	//creating 2 threads
	pthread_create(&thread1, NULL, A, NULL);
	pthread_create(&thread2, NULL, B, NULL);

	//waiting for all the threads to finish
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	return 0;
}