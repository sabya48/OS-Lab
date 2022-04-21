#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>

int n[20];
int q[20][10];
int m, l;

pthread_mutex_t var;

void *foo(void *arg){

        int num = ((int)arg);

        for(int i = 0;i < n[num] ; i++){
                pthread_mutex_lock( &var );
                if( l < q[i]){
                        printf( "Insufficient fuel for vehicle %d.\n" , i + 1);
                }

                else{
                        l -= q[num][i];
                }

                pthread_mutex_unlock( &var );
        }
}



int main(int argc,char* argv[]){

        printf("number of queue : ");
        scanf("%d" , &m );
        printf("capacity of the tanker : ");
        scanf("%d" , &l );
        
        for(int i = 0;i < m;i++){
                printf("enter size of queue %d and that many numbers: ", i + 1);
                scanf("%d" , &n[i]);                
                for(int j = 0;j < n[i]; j++){
                        scanf("%d" , &q[i][j]);
                }
        }

        pthread_t t[m];
        pthread_mutex_init( &var , NULL);


        for(int i = 0;i < m;i++){
                int *a = malloc(sizeof(int));
                *a = i;
                pthread_create( &t[i], NULL , *foo , a );
        }

        for(int i = 0;i < m;i++){
                pthread_join( t[i] , NULL );
        }
}