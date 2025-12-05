//NAME : Atkuri Yashvani
//REG.NO : 24MEI10027

#include <stdio.h>
#include <stdlib.h>

// FUNCTION PROTOTYPES
void printArray(int a[], int size);
void BubbleSort(int a[], int n);
void InsertionSort(int a[], int n);
void SelectionSort(int a[], int n);
void MergeSort(int a[], int left, int right);
void merge(int a[], int left, int mid, int right);
void QuickSort(int a[], int low, int high);
int partition(int a[], int low, int high);

// FUNCTION TO PRINT THE ELEMENTS OF THE ARRAY
void printArray(int a[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", a[i]);
        if (i < size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

// BUBBLE SORT
void BubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

// INSERTION SORT
void InsertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
}

// SELECTION SORT
void SelectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min_idx]) {
                min_idx = j;
            }
        }
        int temp = a[min_idx];
        a[min_idx] = a[i];
        a[i] = temp;
    }
}

// MERGE SORT
void MergeSort(int a[], int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = left + (right - left) / 2;
    MergeSort(a, left, mid);
    MergeSort(a, mid + 1, right);
    merge(a, left, mid, right);
}

// THIS FUNCTION MERGES TWO SORTED SUBARRAYS
void merge(int a[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    if (L == NULL || R == NULL) {
        if (L) free(L);
        if (R) free(R);
        return;
    }

    for (int i = 0; i < n1; ++i) {
        L[i] = a[left + i];
    }
    for (int j = 0; j < n2; ++j) {
        R[j] = a[mid + 1 + j];
    }
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            a[k] = L[i];
            i++;
        } else {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        a[k] = R[j];
        j++;
        k++;
    }
    free(L);
    free(R);
}

// QUICK SORT
void QuickSort(int a[], int low, int high) {
    if (low < high) {
        int pi = partition(a, low, high);
        QuickSort(a, low, pi - 1);
        QuickSort(a, pi + 1, high);
    }
}

// THIS FUNCTION CHOOSES THE PIVOT AND PARTITIONS THE ARRAY AND RETURNS INDEX OF THE PIVOT ELEMENT AFTER SORTING
int partition(int a[], int low, int high) {
    int pivot = a[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (a[j] < pivot) {
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    int temp = a[i + 1];
    a[i + 1] = a[high];
    a[high] = temp;
    return (i + 1);
}

// MAIN PROGRAM
int main() {
    int choice;
    int a[] = {40, 33, 2, 78, 10, 45, 32, 56, 11}; // ARRAY TO BE SORTED
    int size = sizeof(a) / sizeof(a[0]);

    printf("Name: Atkuri Yashvani\n");
    printf("Reg.no: 24MEI10027\n");

    while (1) {
        printf("\n--- Sorting Algorithms Menu ---\n");
        printf("1. Bubble Sort\n");
        printf("2. Insertion Sort\n");
        printf("3. Selection Sort\n");
        printf("4. Merge Sort\n");
        printf("5. Quick Sort\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            printf("Invalid choice. Please try again.\n");
            continue;
        }

        if (choice >= 1 && choice <= 5) {
            int *temp_a = (int *)malloc(size * sizeof(int));
            if (temp_a == NULL) {
                printf("Memory allocation failed.\n");
                return 1;
            }
            for (int i = 0; i < size; i++) {
                temp_a[i] = a[i];
            }
            printf("Original array: ");
            printArray(temp_a, size);
            
            switch (choice) {
                case 1:
                    BubbleSort(temp_a, size);
                    printf("Array after Bubble Sort: ");
                    printArray(temp_a, size);
                    break;
                case 2:
                    InsertionSort(temp_a, size);
                    printf("Array after Insertion Sort: ");
                    printArray(temp_a, size);
                    break;
                case 3:
                    SelectionSort(temp_a, size);
                    printf("Array after Selection Sort: ");
                    printArray(temp_a, size);
                    break;
                case 4:
                    MergeSort(temp_a, 0, size - 1);
                    printf("Array after Merge Sort: ");
                    printArray(temp_a, size);
                    break;
                case 5:
                    QuickSort(temp_a, 0, size - 1);
                    printf("Array after Quick Sort: ");
                    printArray(temp_a, size);
                    break;
            }
            free(temp_a);
        } else if (choice == 6) {
            printf("Exiting program.\n");
            break;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
