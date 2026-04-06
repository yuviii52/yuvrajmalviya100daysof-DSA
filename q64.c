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

// BFS function
void bfs(int start, struct Node* adj[], int n) {
    int visited[n];
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    int queue[n];
    int front = 0, rear = 0;

    // start from source
    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int current = queue[front++];
        printf("%d ", current);

        struct Node* temp = adj[current];

        while (temp != NULL) {
            int next = temp->vertex;

            if (!visited[next]) {
                visited[next] = 1;
                queue[rear++] = next;
            }

            temp = temp->next;
        }
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Node* adj[n];

    // initialize
    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    // input edges (undirected)
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        addEdge(adj, u, v);
        addEdge(adj, v, u); // remove if directed
    }

    int s;
    scanf("%d", &s);

    bfs(s, adj, n);

    return 0;
}