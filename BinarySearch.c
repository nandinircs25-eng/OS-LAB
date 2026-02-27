// Write a C program to perform the following a) Linear search b) Binary
// search.

// b) Binary Search
#include<stdio.h>

int main() {
    int arr[100], n, key, low = 0, high, mid, found = 0, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter sorted elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    high = n - 1;

    while(low <= high) {
        mid = (low + high) / 2;

        if(arr[mid] == key) {
            found = 1;
            printf("Element found at position %d", mid+1);
            break;
        }
        else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    if(found == 0)
        printf("Element not found");

    return 0;
}

// #OUTPUT
// Enter number of elements: 3
// Enter sorted elements:
// 23
// 45
// 78
// Enter element to search: 78
// Element found at position 3
// Process returned 0 (0x0)   execution time : 14.171 s
// Press any key to continue.

