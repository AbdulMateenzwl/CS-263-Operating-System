#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    int pipefd[2];
    pid_t pid;
    char buf[20];
    if (pipe(pipefd) == -1)
    {
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (pid == 0)
    {
        close(pipefd[1]);        
        read(pipefd[0], buf, 20); 
        printf("Child: received %s\n", buf);
        close(pipefd[0]);
        exit(EXIT_SUCCESS);
    }
    else
    {
        close(pipefd[0]);                      
        write(pipefd[1], "Hello, child!", 13); 
        close(pipefd[1]);                      
        printf("Parent: sent message to child.\n");
    }

    return 0;
}
