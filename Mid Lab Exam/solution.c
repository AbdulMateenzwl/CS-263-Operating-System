#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main() 
{
    int fd[2], num, fact = 1; // declare variables for pipe, number, and factorial
    pid_t pid; // declare variable for process ID
    if (pipe(fd) == -1) // Creating pipe, if an error occurs, print an error message and exit the program
    { 
        perror("pipe");
        exit(EXIT_FAILURE);
    }
    pid = fork(); // Creating child process using fork()
    if (pid < 0) // if fork() fails, print an error message and exit the program
    { 
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (pid > 0) // Parent process
    { 
        printf("Enter any number: "); // Prompt the user to enter a number
        scanf("%d", &num); // Read the number entered by the user
        close(fd[0]); // Close the read end of the pipe, since the parent process will be writing to the pipe
        write(fd[1], &num, sizeof(num)); // Write the number to the write end of the pipe using write()
        close(fd[1]); // Close the write end of the pipe, since the parent process has finished writing to the pipe
    }
    else // Child process
    { 
        close(fd[1]); // Close the write end of the pipe, since the child process will be reading from the pipe
        read(fd[0], &num, sizeof(num)); // Read the number from the read end of the pipe using read()
        for (int i = 1; i <= num; i++) // Calculate the factorial of the number
        { 
            fact *= i;
        }
        printf("Factorial Of '%d' is '%d'\n", num, fact); // Print the factorial to the console
        close(fd[0]); // Close the read end of the pipe, since the child process has finished reading from the pipe
    }
    return 0; // Return 0 to indicate successful program completion
}
