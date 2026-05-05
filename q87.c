#include <stdio.h>

void sort(int arr[], int n) {
    for(int i=0;i<n-1;i++) {
        for(int j=0;j<n-i-1;j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}


int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n-1;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}

int main() {
    int n, key;
    scanf("%d", &n);

    int arr[100];

    for(int i=0;i<n;i++)
        scanf("%d", &arr[i]);

    sort(arr, n);

    // print sorted array
    for(int i=0;i<n;i++)
        printf("%d ", arr[i]);

    printf("\n");

    // optional: search element
    scanf("%d", &key);
    int result = binarySearch(arr, n, key);

    if(result != -1)
        printf("Found at index %d\n", result);
    else
        printf("Not Found\n");

    return 0;
}