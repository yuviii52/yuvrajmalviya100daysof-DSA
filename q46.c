#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left, *right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int main() {
    int N;
    scanf("%d", &N);

    int arr[N];
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    Node* nodes[N];

    
    for (int i = 0; i < N; i++) {
        if (arr[i] == -1)
            nodes[i] = NULL;
        else
            nodes[i] = createNode(arr[i]);
    }

    
    for (int i = 0; i < N; i++) {
        if (nodes[i] != NULL) {
            int left = 2*i + 1;
            int right = 2*i + 2;

            if (left < N)
                nodes[i]->left = nodes[left];
            if (right < N)
                nodes[i]->right = nodes[right];
        }
    }

    
    Node* queue[10000];
    int front = 0, rear = 0;

    if (nodes[0] != NULL) {
        queue[rear++] = nodes[0];
    }

    
    while (front < rear) {
        Node* curr = queue[front++];
        printf("%d ", curr->data);

        if (curr->left)
            queue[rear++] = curr->left;

        if (curr->right)
            queue[rear++] = curr->right;
    }

    return 0;
}