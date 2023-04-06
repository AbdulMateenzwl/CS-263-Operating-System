#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
typedef struct msgbuf 
{
    long mtype;
    char mtext[MSGSZ];
} 
message_buf;
int main() 
{
    key_t key;
    int msgid;
    message_buf msg;
    key = ftok("progfile", 65);
    msgid = msgget(key, 0666 | IPC_CREAT);
    msg.mtype = 1;
    printf("Enter a message: ");
    fgets(msg.mtext, MSGSZ, stdin);
    if (msgsnd(msgid, &msg, strlen(msg.mtext)+1, 0) != -1) 
    {
        printf("Message sent: %s", msg.mtext);
    } 
    else 
    {
	    printf("Error: Message not sent.\n");
        exit(1);
    }
    if (msgrcv(msgid, &msg, MSGSZ, 1, 0) != -1) 
    {
        printf("Message received: %s", msg.mtext);
    } 
    else 
    {
	    printf("Error: Message not received.\n");
        exit(1);
    }
    if (msgctl(msgid, IPC_RMID, NULL) != -1) 
    {
        printf("Message queue removed.\n");
    } 
    else 
    {
        printf("Message queue removed.\n");
	    printf("Error: Message queue not removed.\n");
        exit(1);
    }
    return 0;
}