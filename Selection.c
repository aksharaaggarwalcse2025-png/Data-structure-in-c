#include <stdio.h>

int main() {
    int arr[100], n, i, j, min, temp;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Selection Sort
    for(i = 0; i < n - 1; i++) {

        min = i;

        for(j = i + 1; j < n; j++) {
            if(arr[j] < arr[min]) {
                min = j;
            }
        }

        // Swap
        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

    printf("Sorted Array:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}