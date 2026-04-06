#include<stdio.h>
#include<stdlib.h>

// Node structure
struct Node {
    int vertex;
    struct Node* next;
};

// Create node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge
void addEdge(struct Node* adj[], int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;
}

// DFS function
void dfs(int v, struct Node* adj[], int visited[]) {
    visited[v] = 1;
    printf("%d ", v);

    struct Node* temp = adj[v];

    while (temp != NULL) {
        int next = temp->vertex;

        if (!visited[next]) {
            dfs(next, adj, visited);
        }

        temp = temp->next;
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[n];

    // initialize adjacency list
    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    // input edges (undirected)
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        addEdge(adj, u, v);
        addEdge(adj, v, u); // remove this line if directed
    }

    int visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    int s;
    scanf("%d", &s);

    dfs(s, adj, visited);

    return 0;
}