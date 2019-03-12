#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define MSG_SZ (200)

struct my_msgbuf{
      long mtype;
      char mtext[MSG_SZ];
};

int main ( int argv, char * argc[])
{
    struct my_msgbuf buf;
    int msqid;
    key_t key;

    if ((key = ftok("msg_send.c",'B')) == -1 ){
          perror("ftok");
          exit(1);
    }

    if ((msqid = msgget(key,0644)) == -1 ) {
          perror ("msgget");
          exit(1);
    }

    printf("ready to receive messages\n");

    for(;;){
          if ( msgrcv(msqid,&buf,sizeof(buf.mtext),0,0 ) == -1){
                perror("msgrcv");
                exit(1);
          }
          printf("%s\n",buf.mtext);
    }

    return 0;

}
