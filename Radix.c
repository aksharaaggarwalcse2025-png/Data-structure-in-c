#include <stdio.h>

// Get maximum element
int getMax(int arr[], int n) {
    int max = arr[0];

    for(int i = 1; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }

    return max;
}

// Counting sort according to digit
void countingSort(int arr[], int n, int exp) {
    int output[100];
    int count[10] = {0};
    int i;

    // Count occurrences of digits
    for(i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Calculate positions
    for(i = 1; i < 10; i++) {
        count[i] = count[i] + count[i - 1];
    }

    // Build output array
    for(i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy output to original array
    for(i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Radix Sort
void radixSort(int arr[], int n) {
    int max = getMax(arr, n);

    // Sort according to each digit
    for(int exp = 1; max / exp > 0; exp *= 10) {
        countingSort(arr, n, exp);
    }
}

int main() {
    int arr[100], n, i;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    radixSort(arr, n);

    printf("Sorted Array:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}