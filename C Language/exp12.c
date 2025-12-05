//Name : Atkuri Yashvani
//Reg.No : 24MEI10027

#include <stdio.h>
#include <stdlib.h>

// Function to perform Linear Search
// This function can work on an unsorted array.
int linearSearch(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i; // Return the index of the element
        }
    }
    return -1; // Return -1 if the element is not found
}

// Function to perform Binary Search (using Divide and Conquer)
// This function requires the array to be sorted.
int binarySearch(int arr[], int left, int right, int x) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

        // If the element is present at the middle itself
        if (arr[mid] == x) {
            return mid;
        }

        // If the element is smaller than mid, it must be in the left subarray
        if (arr[mid] > x) {
            return binarySearch(arr, left, mid - 1, x);
        }

        // Otherwise, the element must be in the right subarray
        return binarySearch(arr, mid + 1, right, x);
    }

    // Element is not present in the array
    return -1;
}

// Function to print the elements of an array
void printArray(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

int main() {
    // Note: Binary Search requires a sorted array.
    int sortedArray[] = {1, 4, 7, 12, 13, 27, 48, 65, 82, 94};
    int size = sizeof(sortedArray) / sizeof(sortedArray[0]);
    int choice, element, result;

    while (1) {
        printf("\n--- Menu Driven Searching Algorithms ---\n");
        printf("1. Linear Search\n");
        printf("2. Binary Search\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        if (choice == 3) {
            printf("Exiting program.\n");
            break;
        }

        printf("Enter the element to search for: ");
        if (scanf("%d", &element) != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Invalid input. Please enter a number.\n");
            continue;
        }
        
        printf("Array to search: ");
        printArray(sortedArray, size);

        switch (choice) {
            case 1:
                result = linearSearch(sortedArray, size, element);
                if (result != -1) {
                    printf("Element %d found at index %d using Linear Search.\n", element, result);
                } else {
                    printf("Element %d not found in the array.\n", element);
                }
                break;
            case 2:
                result = binarySearch(sortedArray, 0, size - 1, element);
                if (result != -1) {
                    printf("Element %d found at index %d using Binary Search.\n", element, result);
                } else {
                    printf("Element %d not found in the array.\n", element);
                }
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
    return 0;
}