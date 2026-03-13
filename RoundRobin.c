/*Write a C program to simulate the following CPU scheduling
algorithm to find turnaround time and waiting time.

c) RoundRobin
*/
#include <stdio.h>

int main()
{
    int n, tq;
    printf("Enter number of processes: ");
    scanf("%d",&n);

    int pid[n], at[n], bt[n];
    int ct[n], tat[n], wt[n], rt[n];
    int rem_bt[n], start[n];

    int queue[100], front=0, rear=0;
    int visited[n];

    for(int i=0;i<n;i++)
    {
        start[i] = -1;
        visited[i] = 0;
    }

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

    printf("Enter Time Quantum: ");
    scanf("%d",&tq);

    int time = 0, completed = 0;

    while(completed < n)
    {
        for(int i=0;i<n;i++)
        {
            if(at[i] <= time && visited[i]==0)
            {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }

        if(front == rear)
        {
            time++;
            continue;
        }

        int idx = queue[front++];

        if(start[idx] == -1)
            start[idx] = time;

        if(rem_bt[idx] > tq)
        {
            time += tq;
            rem_bt[idx] -= tq;
        }
        else
        {
            time += rem_bt[idx];
            rem_bt[idx] = 0;
            ct[idx] = time;
            completed++;
        }

        for(int i=0;i<n;i++)
        {
            if(at[i] <= time && visited[i]==0)
            {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }

        if(rem_bt[idx] > 0)
            queue[rear++] = idx;
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

    printf("\nRound Robin Scheduling\n\n");
    printf("PID\tAT\tBT\tCT\tTAT\tWT\tRT\n");

    for(int i=0;i<n;i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        pid[i],at[i],bt[i],ct[i],tat[i],wt[i],rt[i]);
    }

    printf("\nAverage Turnaround Time = %.2f", total_tat/n);
    printf("\nAverage Waiting Time = %.2f\n", total_wt/n);

    return 0;
}
/* OUTPUT
Enter number of processes: 5
Enter Process ID:
1 2 3 4 5
Enter Arrival Time:
0 3 2 4 5
Enter Burst Time:
5 3 6 3 1
Enter Time Quantum: 2

Round Robin Scheduling

PID     AT      BT      CT      TAT     WT      RT
1       0       5       14      14      9       0
2       3       3       15      12      9       3
3       2       6       18      16      10      0
4       4       3       16      12      9       4
5       5       1       13      8       7       7

Average Turnaround Time = 12.40
Average Waiting Time = 8.80

Process returned 0 (0x0)   execution time : 18.973 s
Press any key to continue.*/
