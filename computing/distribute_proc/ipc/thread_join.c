#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *functionC();
pthread_mutex_t mutex1 = PTHREAD_MUTEX_INITIALIZER;

int counter = 0;
const int NTHREADS = 5;
int main ( int agrc , char *agrv[])
{
    int rc1;
    pthread_t thread1[NTHREADS];

    for ( int i = 0 ; i < NTHREADS ; i++ ) {
        if ( ( rc1 = pthread_create(&thread1[i],NULL,&functionC,NULL))){
            printf("Thread creation failed: %d\n",rc1);
        }
    }

    for ( int i = 0 ; i < NTHREADS ; i++ ) {
        pthread_join(thread1[i],NULL);
    }

    printf("Counter value = %d \n",counter);
    exit(EXIT_SUCCESS);
}

void *functionC(void)
{
    printf("Thread number %ld\n", pthread_self());

    pthread_mutex_lock(&mutex1);
    counter++;
    pthread_mutex_unlock(&mutex1);

    return NULL;
}



