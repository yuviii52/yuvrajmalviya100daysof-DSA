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

int countLeaves(Node* root) {
    if (root == NULL)
        return 0;

    // If leaf node
    if (root->left == NULL && root->right == NULL)
        return 1;

    return countLeaves(root->left) + countLeaves(root->right);
}

int main() {
    int N;
    scanf("%d", &N);

    int arr[N];
    for (int i = 0; i < N; i++)
        scanf("%d", &arr[i]);

    Node* nodes[N];

    // Create nodes
    for (int i = 0; i < N; i++) {
        if (arr[i] == -1)
            nodes[i] = NULL;
        else
            nodes[i] = createNode(arr[i]);
    }

    // Link nodes
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

    printf("%d", countLeaves(nodes[0]));

    return 0;
}