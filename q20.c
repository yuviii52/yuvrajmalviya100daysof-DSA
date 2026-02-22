#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int count = 0;
    int prefix = 0;

    int *freq = calloc(2*n + 1, sizeof(int));
    int offset = n; 

    freq[offset] = 1;

    for(int i = 0; i < n; i++) {
        prefix += arr[i];

        if(freq[prefix + offset] > 0)
            count += freq[prefix + offset];

        freq[prefix + offset]++;
    }

    printf("%d", count);

    free(freq);
    return 0;
}