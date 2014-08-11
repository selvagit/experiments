#include <unistd.h> /* symbolic constansts*/ 
#include <sys/types.h> /* Primitive system data types */
#include <errno.h> 
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <semaphore.h>

void * handler(void *ptr);

sem_t mutex;
int counter ;

int main(int argv , char *argc[])
{
  int thrd_a_arg=1;
  int thrd_b_arg=2;

  pthread_t thr_a;
  pthread_t thr_b;

  sem_init(&mutex, 0 , 1); /* 0 - cannot be shared  across the process, 
                             1 is binary semaphore */

  pthread_create ((void *)&thr_a , NULL, &handler ,(void*)&thrd_a_arg ); 
  pthread_create ((void *)&thr_b , NULL, &handler ,(void*)&thrd_b_arg ); 

  pthread_join(thr_a,NULL);
  pthread_join(thr_b,NULL);

  sem_destroy(&mutex);

  exit(0);
}

void * handler (void *ptr)
{
  int thread_arg = *((int *)ptr);
  printf("waiting on the thread %d \n",thread_arg);

  sem_wait(&mutex);

  counter++;
  printf("print the counter %d %d\n",counter,thread_arg);

  sem_post(&mutex);

  //pthread_exit(0);

  return NULL;
}
 
