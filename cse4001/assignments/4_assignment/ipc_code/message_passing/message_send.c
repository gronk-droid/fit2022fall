/*
 * message_send.c -- creating and sending to a simple message queue.
 * 
 * source: http://www.cs.cf.ac.uk/Dave/C/node25.html#SECTION002560000000000000000

   The essential points to note here are:

   - The Message queue is created with a basic key and message 
   flag msgflg = IPC_CREAT | 0666 -- create queue and make it read 
   and appendable by all.

   - A message of type (sbuf.mtype) 1 is sent to the queue.  

 */
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MSGSZ     128


/*
 * Declare the message structure.
 */
typedef struct msgbuf {
         long    mtype;
         char    mtext[MSGSZ];
         } message_buf;

int main()
{
    int msqid;
    int msgflg = IPC_CREAT | 0666;
    key_t key;
    message_buf sbuf;
    size_t buf_length;

    /*
     * Get the message queue id for the
     * "name" 1234, which was created by
     * the server.
     */
    key = 1234;

    fprintf(stderr, "\nmsgget: Calling msgget(%#lx,%#o)\n",(unsigned long) key, msgflg);

    if ((msqid = msgget(key, msgflg )) < 0) {
        perror("msgget");
        exit(1);
    }
    else 
       fprintf(stderr,"msgget: msgget succeeded: msqid = %d\n", msqid);


    /*
     * We'll send message type 1
     */
     
    sbuf.mtype = 1;
    
    fprintf(stderr,"msgget: msgget succeeded: msqid = %d\n", msqid);
    
    strcpy(sbuf.mtext, "Hi Receiver process!");
    
    fprintf(stderr,"msgget: msgget succeeded: msqid = %d\n", msqid);
    
    buf_length = strlen(sbuf.mtext) + 1 ;
    
    

    /*
     * Send a message.
     */
    if (msgsnd(msqid, &sbuf, buf_length, IPC_NOWAIT) < 0) {
        printf ("%d, %d, %s, %d\n", msqid, (int) sbuf.mtype, sbuf.mtext, (int) buf_length);
        perror("msgsnd");
        exit(1);
    }

   else 
      printf("Message: \"%s\" Sent\n", sbuf.mtext);
      
    exit(0);
}
