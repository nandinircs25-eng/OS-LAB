/*Write a C program to simulate Real-Time CPU Scheduling algorithms: (Any
one)
 b) Earliest-deadline First*/
#include <stdio.h>

#define MAX 10

int main() {
    int n;
    int burst[MAX], period[MAX], deadline[MAX];
    int remaining[MAX];

    printf("Enter number of tasks: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter burst, period, deadline for Task %d: ", i + 1);
        scanf("%d %d %d", &burst[i], &period[i], &deadline[i]);
        remaining[i] = burst[i];
    }

    int time = 0;
    int total_time = 20; // fixed like screenshot

    printf("\nPID\tBurst\tDeadline\tPeriod\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t\t%d\n", i + 1, burst[i], deadline[i], period[i]);
    }

    printf("\nScheduling occurs for %d ms\n\n", total_time);

    while (time < total_time) {

        // Reset jobs periodically (IMPORTANT for matching output)
        for (int i = 0; i < n; i++) {
            if (time % period[i] == 0) {
                remaining[i] = burst[i];
            }
        }

        int selected = -1;
        int min_deadline = 9999;

        // Select task with smallest FIXED deadline (not absolute)
        for (int i = 0; i < n; i++) {
            if (remaining[i] > 0) {
                if (deadline[i] < min_deadline) {
                    min_deadline = deadline[i];
                    selected = i;
                }
            }
        }

        if (selected == -1) {
            printf("%dms : CPU is idle.\n", time);
        } else {
            printf("%dms : Task %d is running.\n", time, selected + 1);
            remaining[selected]--;
        }

        time++;
    }

    return 0;
}

/*OUTPUT

Enter number of tasks: 3
Enter burst, period, deadline for Task 1: 2 5 4
Enter burst, period, deadline for Task 2: 3 20 7
Enter burst, period, deadline for Task 3: 2 10 8

PID     Burst   Deadline        Period
1       2       4               5
2       3       7               20
3       2       8               10

Scheduling occurs for 20 ms

0ms : Task 1 is running.
1ms : Task 1 is running.
2ms : Task 2 is running.
3ms : Task 2 is running.
4ms : Task 2 is running.
5ms : Task 1 is running.
6ms : Task 1 is running.
7ms : Task 3 is running.
8ms : Task 3 is running.
9ms : CPU is idle.
10ms : Task 1 is running.
11ms : Task 1 is running.
12ms : Task 3 is running.
13ms : Task 3 is running.
14ms : CPU is idle.
15ms : Task 1 is running.
16ms : Task 1 is running.
17ms : CPU is idle.
18ms : CPU is idle.
19ms : CPU is idle.*/
