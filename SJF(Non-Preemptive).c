/*Write a C program to simulate the following CPU scheduling
algorithm to find turnaround time and waiting time.

b) SJF non preemptive*/
#include <stdio.h>

int main()
{
    int n, i, j;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n], at[n], bt[n], ct[n], tat[n], wt[n];
    int completed[n];

    for(i = 0; i < n; i++)
        completed[i] = 0;

    // Input
    for(i = 0; i < n; i++)
    {
        printf("\nEnter Process ID: ");
        scanf("%d", &pid[i]);

        printf("Enter Arrival Time: ");
        scanf("%d", &at[i]);

        printf("Enter Burst Time: ");
        scanf("%d", &bt[i]);
    }

    int current_time = 0, done = 0;

    while(done < n)
    {
        int idx = -1;
        int min_bt = 9999;

        // Find process with smallest burst time
        for(i = 0; i < n; i++)
        {
            if(at[i] <= current_time && completed[i] == 0)
            {
                if(bt[i] < min_bt)
                {
                    min_bt = bt[i];
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
            ct[idx] = current_time + bt[idx];
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];

            current_time = ct[idx];
            completed[idx] = 1;
            done++;
        }
    }

    // Output
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
Enter Arrival Time: 3
Enter Burst Time: 2

Enter Process ID: 2
Enter Arrival Time: 4
Enter Burst Time: 4

Enter Process ID: 3
Enter Arrival Time: 4
Enter Burst Time: 6

PID     AT      BT      CT      TAT     WT
1       3       2       5       2       0
2       4       4       9       5       1
3       4       6       15      11      5

*/
