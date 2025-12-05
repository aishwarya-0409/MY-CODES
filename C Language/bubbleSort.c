 #include <stdio.h>
 void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void display(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
 }
 int main() {
     printf("Name: Rangu Aishwarya\n");
     printf("Reg No: 24MIP10141\n");
    int arr[] = {2, 8, 5, 3, 9, 4, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: ");
    display(arr, n);
    bubbleSort(arr, n);
    printf("\nSorted array: ");
    display(arr, n);
    return 0;
 }
