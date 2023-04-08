#include <stdio.h>

int main()
{
    // Variable declarations
    int count, j, n, time, remain, flag = 0, time_quantum;
    int wait_time = 0, turnaround_time = 0, at[10], bt[10], rt[10];

    // Prompt user to enter the total number of processes
    printf("Enter Total Process:\t ");
    scanf("%d", &n);

    remain = n;

    // Prompt user to enter arrival time and burst time for each process
    for (count = 0; count < n; count++)
    {
        printf("Enter Arrival Time and Burst Time for Process Process Number %d :", count + 1);
        scanf("%d", &at[count]);
        scanf("%d", &bt[count]);
        rt[count] = bt[count];
    }

    // Prompt user to enter time quantum
    printf("Enter Time Quantum:\t");
    scanf("%d", &time_quantum);

    // Display header for output table
    printf("\n\nProcess\t|Turnaround Time|Waiting Time\n\n");

    // Initialize time to 0 and set the current process to 0
    for (time = 0, count = 0; remain != 0;)
    {
        if (rt[count] <= time_quantum && rt[count] > 0)
        {
            // If the remaining time of the current process is less than or equal to the time quantum
            // and greater than 0, execute the process until it finishes
            time += rt[count];
            rt[count] = 0;
            flag = 1; // Set the flag to 1 to indicate that a process has finished executing
        }
        else if (rt[count] > 0)
        {
            // If the remaining time of the current process is greater than the time quantum,
            // execute the process for the duration of the time quantum
            rt[count] -= time_quantum;
            time += time_quantum;
        }
        if (rt[count] == 0 && flag == 1)
        {
            // If the remaining time of the current process is 0 and a process has finished executing,
            // calculate and display its waiting time and turnaround time
            remain--;
            printf("P[%d]\t|\t%d\t|\t%d\n", count + 1, time - at[count], time - at[count] - bt[count]);
            wait_time += time - at[count] - bt[count];
            turnaround_time += time - at[count];
            flag = 0; // Set the flag back to 0
        }
        if (count == n - 1)
            count = 0;
        else if (at[count + 1] <= time)
            count++;
        else
            count = 0;
    }

    // Calculate and display the average waiting time and average turnaround time
    printf("\nAverage Waiting Time= %f\n", wait_time * 1.0 / n);
    printf("Avg Turnaround Time = %f", turnaround_time * 1.0 / n);

    return 0;
}
