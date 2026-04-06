#include<stdio.h>

// function to check min heap
int isMinHeap(int arr[], int n) {
    
    // check all non-leaf nodes
    for (int i = 0; i <= (n - 2) / 2; i++) {
        
        // left child
        if (2*i + 1 < n && arr[i] > arr[2*i + 1])
            return 0;
        
        // right child
        if (2*i + 2 < n && arr[i] > arr[2*i + 2])
            return 0;
    }
    
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    if (isMinHeap(arr, n))
        printf("YES");
    else
        printf("NO");

    return 0;
}