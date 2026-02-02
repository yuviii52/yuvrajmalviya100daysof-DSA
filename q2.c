#include <stdio.h>

int main() {
    int n, pos, i;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the position (1-based) to delete: ");
    scanf("%d", &pos);
    for (i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    printf("Updated array:\n");
    for (i = 0; i < n - 1; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
