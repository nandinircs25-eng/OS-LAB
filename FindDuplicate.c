// Write a C program to find if there are duplicates in an array.

#include<stdio.h>

int main() {
    int arr[100], n, i, j, found = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Check duplicates
    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) {
            if(arr[i] == arr[j]) {
                found = 1;
                printf("Duplicate element found: %d\n", arr[i]);
                break;
            }
        }
    }

    if(found == 0)
        printf("No duplicates found");

    return 0;
}

// // #OUTPUT
// Enter number of elements: 3
// Enter elements:
// 56
// 34
// 56
// Duplicate element found: 56

// Process returned 0 (0x0)   execution time : 14.624 s
// Press any key to continue.
