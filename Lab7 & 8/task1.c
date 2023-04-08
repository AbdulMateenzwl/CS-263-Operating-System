#include <stdio.h>
// function to calculate waiting time for each process
int waitingtime(int proc[], int n, int burst_time[], int wait_time[])
{
    wait_time[0] = 0; // waiting time for first process is always 0
    for (int i = 1; i < n; i++)
        wait_time[i] = burst_time[i - 1] + wait_time[i - 1]; // calculate waiting time for remaining processes
    return 0;
}
// function to calculate turnaround time for each process
int turnaroundtime(int proc[], int n, int burst_time[], int wait_time[], int tat[])
{
    int i;
    for (i = 0; i < n; i++)
        tat[i] = burst_time[i] + wait_time[i]; // calculate turnaround time for each process
    return 0;
}
// function to calculate average waiting time and average turnaround time for all processes
int avgtime(int proc[], int n, int burst_time[])
{
    int wait_time[n], tat[n], total_wt = 0, total_tat = 0;
    int i;
    // calculate waiting time and turnaround time for each process
    waitingtime(proc, n, burst_time, wait_time);
    turnaroundtime(proc, n, burst_time, wait_time, tat);
    // print the table header
    printf("Processes  Burst   Waiting Turn around \n");
    // print the waiting time, turnaround time and burst time for each process
    for (i = 0; i < n; i++)
    {
        total_wt = total_wt + wait_time[i]; // calculate total waiting time
        total_tat = total_tat + tat[i]; // calculate total turnaround time
        printf(" %d\t  %d\t\t %d \t%d\n", i + 1, burst_time[i], wait_time[i], tat[i]);
    }
    // print the average waiting time and average turnaround time for all processes
    printf("\nAverage waiting time = %f", (float)total_wt / (float)n);
    printf("\nAverage turn around time = %f", (float)total_tat / (float)n);
    return 0;
}

// main function
int main()
{
    int proc[] = {1, 2, 3};
    int n = sizeof proc / sizeof proc[0]; // calculate number of processes
    int burst_time[] = {5, 8, 12};
    avgtime(proc, n, burst_time); // calculate average waiting time and average turnaround time for all processes
    return 0;
}