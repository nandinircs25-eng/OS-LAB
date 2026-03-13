/*Write a C program to simulate the following CPU scheduling
algorithm to find turnaround time and waiting time.

b) Priority Scheduling (Preemptive)
*/
#include <stdio.h>
#include <limits.h>

int main()
{
    int n;
    printf("Enter number of processes: ");
    scanf("%d",&n);

    int pid[n], at[n], bt[n], pr[n];
    int ct[n], tat[n], wt[n], rt[n];
    int rem_bt[n], start[n];

    for(int i=0;i<n;i++)
        start[i] = -1;

    printf("Enter Process ID:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&pid[i]);

    printf("Enter Arrival Time:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&at[i]);

    printf("Enter Burst Time:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
        rem_bt[i] = bt[i];
    }

    printf("Enter Priority (Lower number = Higher priority):\n");
    for(int i=0;i<n;i++)
        scanf("%d",&pr[i]);

    int completed = 0;
    int time = 0;

    while(completed < n)
    {
        int idx = -1;
        int highest = INT_MAX;

        for(int i=0;i<n;i++)
        {
            if(at[i] <= time && rem_bt[i] > 0)
            {
                if(pr[i] < highest)
                {
                    highest = pr[i];
                    idx = i;
                }
                else if(pr[i] == highest)
                {
                    if(at[i] < at[idx])
                        idx = i;
                }
            }
        }

        if(idx != -1)
        {
            if(start[idx] == -1)
                start[idx] = time;

            rem_bt[idx]--;
            time++;

            if(rem_bt[idx] == 0)
            {
                ct[idx] = time;
                completed++;
            }
        }
        else
        {
            time++;
        }
    }

    float total_tat = 0, total_wt = 0;

    for(int i=0;i<n;i++)
    {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
        rt[i] = start[i] - at[i];

        total_tat += tat[i];
        total_wt += wt[i];
    }

    printf("\nPriority Scheduling (Preemptive)\n\n");
    printf("PID\tPR\tAT\tBT\tCT\tTAT\tWT\tRT\n");

    for(int i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        pid[i], pr[i], at[i], bt[i], ct[i], tat[i], wt[i], rt[i]);
    }

    printf("\nAverage Turnaround Time = %.2f", total_tat/n);
    printf("\nAverage Waiting Time = %.2f\n", total_wt/n);

    return 0;
}
/*
OUTPUT
Enter number of processes: 5
Enter Process ID:
1 2 3 4 5
Enter Arrival Time:
0 5 2 4 3
Enter Burst Time:
3 4 3 2 5
Enter Priority (Lower number = Higher priority):
5 3 2 4 1

Priority Scheduling (Preemptive)

PID     PR      AT      BT      CT      TAT     WT      RT
1       5       0       3       17      17      14      0
2       3       5       4       14      9       5       5
3       2       2       3       10      8       5       0
4       4       4       2       16      12      10      10
5       1       3       5       8       5       0       0

Average Turnaround Time = 10.20
Average Waiting Time = 6.80

Process returned 0 (0x0)   execution time : 27.334 s
Press any key to continue.*/
