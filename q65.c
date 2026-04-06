#include<stdio.h>
#include<stdlib.h>

#define MAX 1000

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Create node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

// Add edge (undirected)
void addEdge(struct Node* adj[], int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = createNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;
}

// DFS function
int dfs(int node, int parent, struct Node* adj[], int visited[]) {
    visited[node] = 1;

    struct Node* temp = adj[node];

    while (temp) {
        int neighbor = temp->data;

        if (!visited[neighbor]) {
            if (dfs(neighbor, node, adj, visited))
                return 1;
        }
        else if (neighbor != parent) {
            return 1; // cycle found
        }

        temp = temp->next;
    }

    return 0;
}

int main() {
    int V, E;
    scanf("%d %d", &V, &E);

    struct Node* adj[V];

    // initialize
    for (int i = 0; i < V; i++)
        adj[i] = NULL;

    // input edges
    for (int i = 0; i < E; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    int visited[V];
    for (int i = 0; i < V; i++)
        visited[i] = 0;

    // check all components
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, -1, adj, visited)) {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");
    return 0;
}