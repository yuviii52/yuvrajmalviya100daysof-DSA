#include <stdio.h>

int main() {
    int m, n, i, j;
    printf("Enter rows and columns: ");
    scanf("%d %d", &m, &n);

    int matrix[m][n];

    printf("Enter matrix elements:\n");
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    if(m != n) {
        printf("Not a Symmetric Matrix\n");
        return 0;
    }

    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            if(matrix[i][j] != matrix[j][i]) {
                printf("Not a Symmetric Matrix\n");
                return 0;
            }
        }
    }

    printf("Symmetric Matrix\n");

    return 0;
}
