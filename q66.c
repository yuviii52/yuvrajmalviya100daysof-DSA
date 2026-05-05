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
int dfs(int node, struct Node* adj[], int visited[], int recStack[]) {

    visited[node] = 1;
    recStack[node] = 1;

    struct Node* temp = adj[node];

    while (temp) {
        int neighbor = temp->data;

        if (!visited[neighbor]) {
            if (dfs(neighbor, adj, visited, recStack))
                return 1;
        }
        else if (recStack[neighbor]) {
            return 1; // cycle found
        }

        temp = temp->next;
    }

    recStack[node] = 0; // remove from recursion stack
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

    int visited[V], recStack[V];

    for (int i = 0; i < V; i++) {
        visited[i] = 0;
        recStack[i] = 0;
    }

    // check all components
    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, adj, visited, recStack)) {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");
    return 0;
}