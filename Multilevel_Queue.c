/*Write a C program to simulate multi-level queue scheduling
algorithm considering the following scenario. All the
processes in the system are divided into two categories –
system processes and user processes. System processes are
to be given higher priority than user processes. Use FCFS
scheduling for the processes in each queue.
*/
#include <stdio.h>

#define MAX 20
#define TQ 2

typedef struct {
    int pid, at, bt, rt;
    int ct, tat, wt;
    int type; // 1-System, 2-User
    int done;
} Process;

int main() {
    int n;
    Process p[MAX];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        p[i].pid = i + 1;

        printf("\nProcess %d\n", i+1);
        printf("Arrival Time: ");
        scanf("%d", &p[i].at);

        printf("Burst Time: ");
        scanf("%d", &p[i].bt);

        printf("Type (1-System, 2-User): ");
        scanf("%d", &p[i].type);

        p[i].rt = p[i].bt;
        p[i].done = 0;
    }

    int time = 0, completed = 0;

    while(completed < n) {

        int executed = 0;

        // 1. System Queue (Round Robin with preemption)
        for(int i = 0; i < n; i++) {
            if(p[i].type == 1 && p[i].rt > 0 && p[i].at <= time) {

                int exec = (p[i].rt > TQ) ? TQ : p[i].rt;

                p[i].rt -= exec;
                time += exec;

                // Check if finished
                if(p[i].rt == 0) {
                    p[i].ct = time;
                    p[i].done = 1;
                    completed++;
                }

                executed = 1;
            }
        }

        if(executed) continue;

        // 2. User Queue (FCFS but PREEMPT if system arrives)
        for(int i = 0; i < n; i++) {
            if(p[i].type == 2 && p[i].rt > 0 && p[i].at <= time) {

                // execute 1 unit at a time to allow preemption
                p[i].rt--;
                time++;

                // Check completion
                if(p[i].rt == 0) {
                    p[i].ct = time;
                    p[i].done = 1;
                    completed++;
                }

                executed = 1;
                break; // FCFS
            }
        }

        // If nothing executed → jump time forward
        if(!executed) {
            time++;
        }
    }

    // Calculate TAT & WT
    float total_tat = 0, total_wt = 0;

    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");

    for(int i = 0; i < n; i++) {
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;

        total_tat += p[i].tat;
        total_wt += p[i].wt;

        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].at, p[i].bt,
               p[i].ct, p[i].tat, p[i].wt);
    }

    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);
    printf("Average Waiting Time = %.2f\n", total_wt / n);

    return 0;
}

/*OUTPUT

Enter number of processes: 4

Process 1
Arrival Time: 0
Burst Time: 4
Type (1-System, 2-User): 1

Process 2
Arrival Time: 0
Burst Time: 3
Type (1-System, 2-User): 1

Process 3
Arrival Time: 0
Burst Time: 8
Type (1-System, 2-User): 2

Process 4
Arrival Time: 10
Burst Time: 5
Type (1-System, 2-User): 1

PID     AT      BT      CT      TAT     WT
P1      0       4       6       6       2
P2      0       3       7       7       4
P3      0       8       20      20      12
P4      10      5       15      5       0

Average Turnaround Time = 9.50
Average Waiting Time = 4.50*/
