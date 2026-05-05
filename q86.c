#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    long low = 0, high = n;
    int ans = 0;

    while (low <= high) {
        long mid = (low + high) / 2;

        if (mid * mid == n) {
            ans = mid;
            break;
        }
        else if (mid * mid < n) {
            ans = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    printf("%d\n", ans);

    return 0;
}