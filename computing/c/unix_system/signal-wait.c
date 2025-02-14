#define _POSIX_C_SOURCE 200809L

#include <signal.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

FILE* file;


void* threadA(void* argv){
    fprintf(file, "%ld\n", pthread_self());

    sigset_t m;
    sigemptyset(&m);
    sigaddset(&m, SIGUSR1);
    int signo;
    int err;

    // sigset_t q;
    // sigemptyset(&q);
    // pthread_sigmask(SIG_SETMASK, &q, NULL);
    // sleep(50);

    fprintf(file, "1\n");

    err = sigwait(&m, &signo);
    if (err != 0){
        fprintf(file, "sigwait error\n");
        exit(1);
    }

    switch (signo)
    {
    case SIGUSR1:
        fprintf(file, "SIGUSR1 received\n");
        break;

    default:
        fprintf(file, "?\n");
        break;
    }

    fprintf(file, "2\n");

    return 0;
}

void hello(int signo){
    fprintf(file, "%ld\n", pthread_self());
    fprintf(file, "hello\n");
}


int main(){
    file = fopen("daemon", "wb");

    setbuf(file, NULL);

#if 0
    struct sigaction sa;
    sigemptyset(&sa.sa_mask);
    sa.sa_handler = hello;
    sigaction(SIGUSR1, &sa, NULL);
#endif

    sigset_t n;
    sigemptyset(&n);
    sigaddset(&n, SIGUSR1);
    sigprocmask(SIG_BLOCK, &n, NULL);

    // pthread_sigmask(SIG_BLOCK, &n, NULL);

    pthread_t pid;
    int err;
    err = pthread_create(&pid, NULL, threadA, NULL);

    if(err != 0){
        fprintf(file, "create thread error\n");
        exit(1);
    }

    pause();

    fprintf(file, "after pause\n");
    fclose(file);
    return 0;

}
