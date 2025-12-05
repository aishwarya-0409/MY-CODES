#include <stdio.h>

// Linear Search
int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

// Binary Search
int binarySearch(int arr[], int low, int high, int x) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (arr[mid] == x) {
            return mid;
        }
        if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x;
    
    printf("Enter element to search: ");
    scanf("%d", &x);
    
    // Linear Search
    int linearResult = linearSearch(arr, n, x);
    (linearResult == -1) ? printf("Linear Search: Element not found\n")
                         : printf("Linear Search: Element found at index %d\n", linearResult);
    
    // Binary Search
    int binaryResult = binarySearch(arr, 0, n - 1, x);
    (binaryResult == -1) ? printf("Binary Search: Element not found\n")
                         : printf("Binary Search: Element found at index %d\n", binaryResult);
    
    return 0;
}