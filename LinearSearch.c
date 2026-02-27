// Write a C program to perform the following a) Linear search b) Binary
// search.
// a) Linear Search

#include<stdio.h>

int main() {
    int arr[100], n, key, i, found = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    for(i = 0; i < n; i++) {
        if(arr[i] == key) {
            found = 1;
            printf("Element found at position %d", i+1);
            break;
        }
    }

    if(found == 0)
        printf("Element not found");

    return 0;
}

// OUTPUT

// Enter number of elements: 3
// Enter elements:
// 23
// 456
// 678
// Enter element to search: 23
// Element found at position 1
// Process returned 0 (0x0)   execution time : 13.173 s
// Press any key to continue.
