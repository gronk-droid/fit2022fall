/*
 * message_rec.c -- Reads the message from the queue.
 * 
 * source: http://www.cs.cf.ac.uk/Dave/C/node25.html#SECTION002560000000000000000

   The essential points to note here are:

   - The Message queue is opened with msgget (message flag 0666) 
   and the same key as message_send.c.

   - A message of the same type 1 is received from the queue (stored in rbuf.mtext).

 */
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>


#define MSGSZ     128


/*xs
 * Declare the message structure.
 */

typedef struct msgbuf {
    long    mtype;
    char    mtext[MSGSZ];
} message_buf;


int main()
{
    int msqid;
    key_t key;
    message_buf  rbuf;

    /*
     * Get the message queue id for the
     * "name" 1234, which was created by
     * the server.
     */
    key = 1234;

    if ((msqid = msgget(key, 0666)) < 0) {
        perror("msgget");
        exit(1);
    }

    
    /*
     * Receive an answer of message type 1.
     */
    if (msgrcv(msqid, &rbuf, MSGSZ, 1, 0) < 0) {
        perror("msgrcv");
        exit(1);
    }

    /*
     * Print the answer.
     */
    printf("%s\n", rbuf.mtext);
    exit(0);
}
