/*Write a C program to simulate Real-Time CPU Scheduling algorithms: (Any
one) a) Rate- Monotonic*/
#include <stdio.h>
#include <math.h>

#define MAX 10

// GCD
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

// LCM
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

// LCM of all
int find_lcm(int arr[], int n) {
    int res = arr[0];
    for (int i = 1; i < n; i++) {
        res = lcm(res, arr[i]);
    }
    return res;
}

int main() {
    int n, burst[MAX], period[MAX];

    printf("Enter the number of processes:");
    scanf("%d", &n);

    printf("Enter the CPU burst times:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &burst[i]);

    printf("Enter the time periods:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &period[i]);

    int hyper = find_lcm(period, n);
    printf("LCM=%d\n\n", hyper);

    // Display table
    printf("Rate Monotone Scheduling:\n");
    printf("PID\tBurst\tPeriod\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\n", i + 1, burst[i], period[i]);
    }

    // Utilization
    double U = 0;
    for (int i = 0; i < n; i++) {
        U += (double)burst[i] / period[i];
    }

    double bound = n * (pow(2, (double)1 / n) - 1);

    printf("\n%f <= %f => %s\n", U, bound, (U <= bound) ? "true" : "false");

    printf("Scheduling occurs for %d ms\n\n", hyper);

    // Scheduling simulation
    int time = 0;
    int remaining[MAX] = {0};

    while (time < hyper) {

        // release tasks
        for (int i = 0; i < n; i++) {
            if (time % period[i] == 0) {
                remaining[i] = burst[i];
            }
        }

        int selected = -1;

        // select highest priority (smallest period)
        for (int i = 0; i < n; i++) {
            if (remaining[i] > 0) {
                if (selected == -1 || period[i] < period[selected]) {
                    selected = i;
                }
            }
        }

        if (selected != -1) {
            printf("%dms onwards: Process %d running\n", time, selected + 1);
            remaining[selected]--;

            // run until preemption or finish
            int next = time + 1;
            while (next < hyper) {

                int preempt = 0;

                for (int i = 0; i < n; i++) {
                    if (next % period[i] == 0 && period[i] < period[selected]) {
                        preempt = 1;
                    }
                }

                if (remaining[selected] == 0 || preempt)
                    break;

                remaining[selected]--;
                next++;
            }

            time = next;
        } else {
            printf("%dms onwards: CPU is idle\n", time);
            time++;
        }
    }

    return 0;
}

/*OUTPUT

Enter the number of processes:2
Enter the CPU burst times:
20 35
Enter the time periods:
50 100
LCM=100

Rate Monotone Scheduling:
PID     Burst   Period
1       20      50
2       35      100

0.750000 <= 0.828427 => true
Scheduling occurs for 100 ms

0ms onwards: Process 1 running
20ms onwards: Process 2 running
50ms onwards: Process 1 running
70ms onwards: Process 2 running
75ms onwards: CPU is idle
76ms onwards: CPU is idle
77ms onwards: CPU is idle
78ms onwards: CPU is idle
79ms onwards: CPU is idle
80ms onwards: CPU is idle
81ms onwards: CPU is idle
82ms onwards: CPU is idle
83ms onwards: CPU is idle
84ms onwards: CPU is idle
85ms onwards: CPU is idle
86ms onwards: CPU is idle
87ms onwards: CPU is idle
88ms onwards: CPU is idle
89ms onwards: CPU is idle
90ms onwards: CPU is idle
91ms onwards: CPU is idle
92ms onwards: CPU is idle
93ms onwards: CPU is idle
94ms onwards: CPU is idle
95ms onwards: CPU is idle
96ms onwards: CPU is idle
97ms onwards: CPU is idle
98ms onwards: CPU is idle
99ms onwards: CPU is idle*/
