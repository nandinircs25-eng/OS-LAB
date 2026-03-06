/*Write a C program to simulate the following CPU scheduling
algorithm to find turnaround time and waiting time.

c) SJF preemptive*/

#include <stdio.h>

int main()
{
    int n, i;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n], at[n], bt[n], rt[n];
    int ct[n], tat[n], wt[n];

    // Input
    for(i = 0; i < n; i++)
    {
        printf("\nEnter Process ID: ");
        scanf("%d", &pid[i]);

        printf("Enter Arrival Time: ");
        scanf("%d", &at[i]);

        printf("Enter Burst Time: ");
        scanf("%d", &bt[i]);

        rt[i] = bt[i]; // remaining time = burst time
    }

    int completed = 0, current_time = 0;

    while(completed < n)
    {
        int idx = -1;
        int min_rt = 9999;

        // find process with smallest remaining time
        for(i = 0; i < n; i++)
        {
            if(at[i] <= current_time && rt[i] > 0)
            {
                if(rt[i] < min_rt)
                {
                    min_rt = rt[i];
                    idx = i;
                }
            }
        }

        if(idx == -1)
        {
            current_time++;
        }
        else
        {
            rt[idx]--;        // execute for 1 unit
            current_time++;

            if(rt[idx] == 0)
            {
                ct[idx] = current_time;
                tat[idx] = ct[idx] - at[idx];
                wt[idx] = tat[idx] - bt[idx];
                completed++;
            }
        }
    }

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
        pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    return 0;
}


/*OUTPUT
Enter number of processes: 3

Enter Process ID: 1
Enter Arrival Time: 0
Enter Burst Time: 5

Enter Process ID: 2
Enter Arrival Time: 2
Enter Burst Time: 4

Enter Process ID: 3
Enter Arrival Time: 5
Enter Burst Time: 6

PID     AT      BT      CT      TAT     WT
1       0       5       5       5       0
2       2       4       9       7       3
3       5       6       15      10      4
*/

