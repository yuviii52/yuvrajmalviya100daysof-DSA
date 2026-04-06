#include<stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int adj[n][n];

    // initialize matrix with 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    int type;
    printf("Enter 0 for Undirected, 1 for Directed: ");
    scanf("%d", &type);

    // input edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        adj[u][v] = 1;

        if (type == 0) {
            adj[v][u] = 1; // undirected
        }
    }

    // print adjacency matrix
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    return 0;
}