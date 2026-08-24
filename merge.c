#include <stdio.h>

// Merge two sorted parts
void merge(int arr[], int low, int mid, int high) {
    int i = low;
    int j = mid + 1;
    int k = 0;
    int temp[100];

    while(i <= mid && j <= high) {
        if(arr[i] < arr[j]) {
            temp[k] = arr[i];
            i++;
        } else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of left part
    while(i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    // Copy remaining elements of right part
    while(j <= high) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    // Copy temp array back to original array
    for(i = low, k = 0; i <= high; i++, k++) {
        arr[i] = temp[k];
    }
}

// Merge Sort function
void mergeSort(int arr[], int low, int high) {
    if(low < high) {
        int mid = (low + high) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
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

    mergeSort(arr, 0, n - 1);

    printf("Sorted Array:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}