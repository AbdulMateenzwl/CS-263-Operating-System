#include <stdio.h>

int main()
{
    int bt[20], p[20], wt[20], tat[20], pr[20], i, j, n, total = 0, pos, temp, avg_wt, avg_tat;

    // Prompt user to enter number of processes
    printf("Enter Total Number of Processes: ");
    scanf("%d", &n);

    // Prompt user to enter burst time and priority for each process
    printf("\nEnter Burst Time and Priority\n");
    for (i = 0; i < n; i++)
    {
        printf("\nP[%d]\n", i + 1);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        printf("Priority: ");
        scanf("%d", &pr[i]);
        p[i] = i + 1; // Store process number in p array
    }

    // Sort processes based on their priority using selection sort
    for (i = 0; i < n; i++)
    {
        pos = i;
        for (j = i + 1; j < n; j++)
        {
            if (pr[j] < pr[pos])
                pos = j;
        }

        // Swap priority, burst time, and process number of processes
        temp = pr[i];
        pr[i] = pr[pos];
        pr[pos] = temp;

        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;

        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
    }

    wt[0] = 0; // Waiting time for first process is zero

    // Calculate waiting time for each process
    for (i = 1; i < n; i++)
    {
        wt[i] = 0;
        for (j = 0; j < i; j++)
            wt[i] += bt[j];

        total += wt[i];
    }

    avg_wt = total / n; // Calculate average waiting time
    total = 0;

    // Print process table with their burst time, waiting time, and turnaround time
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for (i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i]; // Calculate turnaround time for each process
        total += tat[i];
        printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d", p[i], bt[i], wt[i], tat[i]);
    }

    avg_tat = total / n; // Calculate average turnaround time for all processes

    // Print average waiting time and average turnaround time
    printf("\n\nAverage Waiting Time = %d", avg_wt);
    printf("\nAverage Turnaround Time = %d\n", avg_tat);

    return 0;
}
