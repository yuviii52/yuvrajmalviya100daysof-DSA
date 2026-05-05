#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

// Structure for adjacency list node
struct Node {
    int vertex;
    int weight;
    struct Node* next;
};

// Create new node
struct Node* newNode(int v, int w) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->vertex = v;
    temp->weight = w;
    temp->next = NULL;
    return temp;
}

// Adjacency list
struct Node* adj[MAX];

// -------- Min Heap --------
struct HeapNode {
    int vertex;
    int dist;
};

struct HeapNode heap[MAX];
int heapSize = 0;

// Swap
void swap(struct HeapNode* a, struct HeapNode* b) {
    struct HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up
void heapifyUp(int i) {
    while (i && heap[(i - 1) / 2].dist > heap[i].dist) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

// Heapify down
void heapifyDown(int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < heapSize && heap[left].dist < heap[smallest].dist)
        smallest = left;

    if (right < heapSize && heap[right].dist < heap[smallest].dist)
        smallest = right;

    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        heapifyDown(smallest);
    }
}

// Insert into heap
void push(int v, int dist) {
    heap[heapSize].vertex = v;
    heap[heapSize].dist = dist;
    heapifyUp(heapSize);
    heapSize++;
}

// Extract min
struct HeapNode pop() {
    struct HeapNode root = heap[0];
    heap[0] = heap[--heapSize];
    heapifyDown(0);
    return root;
}

int isEmpty() {
    return heapSize == 0;
}

// -------- Dijkstra --------
void dijkstra(int V, int src) {
    int dist[MAX];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;
    push(src, 0);

    while (!isEmpty()) {
        struct HeapNode top = pop();
        int u = top.vertex;

        struct Node* temp = adj[u];
        while (temp) {
            int v = temp->vertex;
            int w = temp->weight;

            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(v, dist[v]);
            }
            temp = temp->next;
        }
    }

    // Print result
    printf("Shortest distances from source %d:\n", src);
    for (int i = 0; i < V; i++) {
        printf("To %d = %d\n", i, dist[i]);
    }
}

// -------- Main --------
int main() {
    int V = 5;

    // Initialize adjacency list
    for (int i = 0; i < V; i++)
        adj[i] = NULL;

    // Add edges (u -> v, weight)
    adj[0] = newNode(1, 2);
    adj[0]->next = newNode(4, 1);

    adj[1] = newNode(2, 3);

    adj[2] = newNode(3, 6);

    adj[4] = newNode(2, 2);
    adj[4]->next = newNode(3, 4);

    // Run Dijkstra
    dijkstra(V, 0);

    return 0;
}