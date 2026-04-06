#include<stdio.h>
#include<stdlib.h>

// Node of linked list
struct Node {
    int vertex;
    struct Node* next;
};

// Graph structure
struct Graph {
    int numVertices;
    struct Node** adjLists;
};

// Create node
struct Node* createNode(int v) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Create graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = (struct Node**)malloc(vertices * sizeof(struct Node*));

    for (int i = 0; i < vertices; i++)
        graph->adjLists[i] = NULL;

    return graph;
}

// Add edge
void addEdge(struct Graph* graph, int src, int dest, int type) {
    // add edge src → dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    // if undirected, add dest → src
    if (type == 0) {
        newNode = createNode(src);
        newNode->next = graph->adjLists[dest];
        graph->adjLists[dest] = newNode;
    }
}

// Print graph
void printGraph(struct Graph* graph) {
    for (int i = 0; i < graph->numVertices; i++) {
        struct Node* temp = graph->adjLists[i];
        printf("%d: ", i);

        while (temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    struct Graph* graph = createGraph(n);

    int type;
    printf("Enter 0 for Undirected, 1 for Directed: ");
    scanf("%d", &type);

    // input edges
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(graph, u, v, type);
    }

    printGraph(graph);

    return 0;
}