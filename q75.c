#include <stdio.h>

#define SIZE 1000

int main() {
    int n;
    scanf("%d", &n);

    int arr[SIZE];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int prefixSum = 0, maxLen = 0;

    // simple hashmap using arrays (for beginners)
    int sum[SIZE];
    int index[SIZE];
    int size = 0;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];

        // case 1: sum = 0
        if (prefixSum == 0) {
            maxLen = i + 1;
        }

        // check if prefixSum seen before
        int found = -1;
        for (int j = 0; j < size; j++) {
            if (sum[j] == prefixSum) {
                found = index[j];
                break;
            }
        }

        if (found != -1) {
            int len = i - found;
            if (len > maxLen) {
                maxLen = len;
            }
        } else {
            sum[size] = prefixSum;
            index[size] = i;
            size++;
        }
    }

    printf("%d\n", maxLen);

    return 0;
}