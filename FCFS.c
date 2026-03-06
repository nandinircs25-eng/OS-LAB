/*Write a C program to simulate the following CPU scheduling
algorithm to find turnaround time and waiting time.

a) FCFS */

#include <stdio.h>

int main() {
    int n, i;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n], at[n], bt[n], ct[n], tat[n], wt[n];
    int current_time = 0;

    // Input
    for(i = 0; i < n; i++) {
        printf("\nEnter Process ID: ");
        scanf("%d", &pid[i]);

        printf("Enter Arrival Time: ");
        scanf("%d", &at[i]);

        printf("Enter Burst Time: ");
        scanf("%d", &bt[i]);
    }

    // FCFS Calculation
    for(i = 0; i < n; i++) {

        if(current_time < at[i])
            current_time = at[i];

        ct[i] = current_time + bt[i];
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        current_time = ct[i];
    }

    // Output
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
        pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    return 0;
}

/*OUTPUT
Enter number of processes: 3

Enter Process ID: 1
Enter Arrival Time: 4
Enter Burst Time: 6

Enter Process ID: 2
Enter Arrival Time: 5
Enter Burst Time: 6

Enter Process ID: 3
Enter Arrival Time: 5
Enter Burst Time: 6

PID     AT      BT      CT      TAT     WT
1       4       6       10      6       0
2       5       6       16      11      5
3       5       6       22      17      11

*/



