#include<stdio.h>
#include<stdlib.h>

#define MAX 1000

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// create node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = v;
    newNode->next = NULL;
    return newNode;
}

// add edge (directed)
void addEdge(struct Node* adj[], int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;
}

// DFS function
void dfs(int node, struct Node* adj[], int visited[], int stack[], int* top) {
    visited[node] = 1;

    struct Node* temp = adj[node];

    while (temp) {
        int neighbor = temp->data;

        if (!visited[neighbor]) {
            dfs(neighbor, adj, visited, stack, top);
        }

        temp = temp->next;
    }

    // push into stack after visiting all neighbors
    stack[++(*top)] = node;
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

    int stack[MAX];
    int top = -1;

    // run DFS for all components
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited, stack, &top);
        }
    }

    // print topological order
    while (top != -1) {
        printf("%d ", stack[top--]);
    }

    return 0;
}