#include<stdio.h>

int main() {
    int arr[100], n, i, min, pos;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Assume first element is smallest
    min = arr[0];
    pos = 0;

    // Compare with remaining elements
    for(i = 1; i < n; i++) {
        if(arr[i] < min) {
            min = arr[i];
            pos = i;
        }
    }

    printf("Smallest element = %d\n", min);
    printf("Position = %d", pos + 1);  // +1 for user-friendly position

    return 0;
}
