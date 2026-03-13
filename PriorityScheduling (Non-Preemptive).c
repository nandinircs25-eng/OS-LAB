/*Write a C program to simulate the following CPU scheduling
algorithm to find turnaround time and waiting time.

a) Priority Scheduling (Non-Preemptive)
*/
#include <stdio.h>

int main() {
    int n, i, j;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    int pid[n], at[n], bt[n], pr[n];
    int ct[n], tat[n], wt[n], rt[n];
    int completed[n];

    for(i=0;i<n;i++)
        completed[i]=0;

    printf("\nEnter Process ID:\n");
    for(i=0;i<n;i++)
        scanf("%d",&pid[i]);

    printf("Enter Arrival Time:\n");
    for(i=0;i<n;i++)
        scanf("%d",&at[i]);

    printf("Enter Burst Time:\n");
    for(i=0;i<n;i++)
        scanf("%d",&bt[i]);

    printf("Enter Priority (Lower number = Higher priority):\n");
    for(i=0;i<n;i++)
        scanf("%d",&pr[i]);

    int time=0, count=0;
    float total_tat=0, total_wt=0;

    while(count<n) {

        int idx=-1;
        int highest=999;

        for(i=0;i<n;i++) {
            if(at[i]<=time && completed[i]==0) {

                if(pr[i] < highest) {
                    highest = pr[i];
                    idx = i;
                }

                if(pr[i]==highest) {
                    if(at[i] < at[idx])
                        idx=i;
                }
            }
        }

        if(idx != -1) {

            int start = time;

            time += bt[idx];

            ct[idx] = time;
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];
            rt[idx] = start - at[idx];

            total_tat += tat[idx];
            total_wt += wt[idx];

            completed[idx] = 1;
            count++;

        }
        else {
            time++;
        }
    }

    printf("\nPriority Scheduling (Non-Preemptive)\n\n");
    printf("PID\tPR\tAT\tBT\tCT\tTAT\tWT\tRT\n");

    for(i=0;i<n;i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        pid[i],pr[i],at[i],bt[i],ct[i],tat[i],wt[i],rt[i]);
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
0 3 5 6 9
Enter Burst Time:
4 5 3 6 2
Enter Priority (Lower number = Higher priority):
3 4 2 1 5

Priority Scheduling (Non-Preemptive)

PID     PR      AT      BT      CT      TAT     WT      RT
1       3       0       4       4       4       0       0
2       4       3       5       9       6       1       1
3       2       5       3       18      13      10      10
4       1       6       6       15      9       3       3
5       5       9       2       20      11      9       9

Average Turnaround Time = 8.60
Average Waiting Time = 4.60

Process returned 0 (0x0)   execution time : 23.923 s
Press any key to continue.*/
