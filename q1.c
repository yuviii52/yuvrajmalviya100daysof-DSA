#include <stdio.h>

int main() {
    int n, pos, x, i;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    int arr[n + 1];
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the position (1-based) to insert: ");
    scanf("%d", &pos);
    printf("Enter the element to insert: ");
    scanf("%d", &x);
    for (i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = x;
    printf("Updated array:\n");
    for (i = 0; i <= n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
