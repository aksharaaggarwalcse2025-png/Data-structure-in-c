#include <stdio.h>

int main() {
    int a[100], b[100], c[100];
    int n, i;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter elements of first array:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter elements of second array:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }

    // Addition of two arrays
    for(i = 0; i < n; i++) {
        c[i] = a[i] + b[i];
    }

    printf("Addition of two arrays:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", c[i]);
    }

    return 0;
}