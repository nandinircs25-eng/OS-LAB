#include <stdio.h>

int main()
{
    int n, m, i, j, k;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources: ");
    scanf("%d", &m);
    int alloc[n][m], request[n][m], avail[m];
    // Allocation Matrix
    printf("Enter the allocation matrix:\n");
    for(i = 0; i < n; i++)
    {
        printf("Process %d: ", i);
        for(j = 0; j < m; j++)
        {
            scanf("%d", &alloc[i][j]);
        }
    }
    // Request Matrix
    printf("Enter the request matrix:\n");
    for(i = 0; i < n; i++)
    {
        printf("Process %d: ", i);
        for(j = 0; j < m; j++)
        {
            scanf("%d", &request[i][j]);
        }
    }
    // Available Resources
    printf("Enter the available resources: ");
    for(i = 0; i < m; i++)
    {
        scanf("%d", &avail[i]);
    }
    int finish[n], safeSeq[n];
    int work[m];
    // Initialize work
    for(i = 0; i < m; i++)
    {
        work[i] = avail[i];
    }
    // Initialize finish
    for(i = 0; i < n; i++)
    {
        int flag = 0;
        for(j = 0; j < m; j++)
        {
            if(alloc[i][j] != 0)
            {
                flag = 1;
                break;
            }
        }
        if(flag == 0)
            finish[i] = 1;
        else
            finish[i] = 0;
    }
    int count = 0;
    while(count < n)
    {
        int found = 0;
        for(i = 0; i < n; i++)
        {
            if(finish[i] == 0)
            {
                for(j = 0; j < m; j++)
                {
                    if(request[i][j] > work[j])
                        break;
                }
                if(j == m)
                {
                    for(k = 0; k < m; k++)
                    {
                        work[k] += alloc[i][k];
                    }

                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }
        if(found == 0)
            break;

    // Check deadlock
    int deadlock = 0;
    for(i = 0; i < n; i++)
    {
        if(finish[i] == 0)
        {
            deadlock = 1;
            printf("Process P%d is deadlocked\n", i);
        }
    }
    if(deadlock == 0)
    {
        printf("System is not in deadlock state.\n");

        printf("Safe Sequence is: ");
        for(i = 0; i < count; i++)
        {
            printf("P%d ", safeSeq[i]);
        }
    }
    return 0;
}
