#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>


#define MSG_SZ (200)

struct my_msgbuf{
      long mtype;
      char mtext[MSG_SZ];
};

int main (int argv, char *argc[])
{
    struct my_msgbuf buf;
    int msqid;
    key_t key;

    if ((key= ftok("msg_send.c",'B')) == -1 ) {
            perror("ftok");
            exit(1);
    }

    if ((msqid = msgget(key, 0644 | IPC_CREAT)) == -1 ) {
          perror ("msgget");
          exit(1);
    }

    printf("Enter lines of text,^D to quit:\n");

    buf.mtype = 1;

    while(fgets(buf.mtext, sizeof buf.mtext, stdin) != NULL) {
          int len = strlen(buf.mtext);

          if (msgsnd(msqid, &buf, len , 0) == -1 )
                perror ("msgsnd");
    }

    if (msgctl(msqid, IPC_RMID, NULL) == -1 ){
          perror ("msgctl");
          exit(1);
    }

    return 0;
}


/* ipcs to view the message memory created
 * ipcrm to remove the message memory created 
 */
