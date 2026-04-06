#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ─── Data Structures ────────────────────────────────────────────

typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* newNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val  = val;
    node->left = node->right = NULL;
    return node;
}

// ─── Build Tree from Level-Order Input ──────────────────────────

TreeNode* buildTree(int* arr, int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    TreeNode** queue = (TreeNode**)malloc(n * sizeof(TreeNode*));
    int front = 0, back = 0;

    TreeNode* root = newNode(arr[0]);
    queue[back++] = root;
    int i = 1;

    while (front < back && i < n) {
        TreeNode* curr = queue[front++];

        // Left child
        if (i < n) {
            if (arr[i] != -1) {
                curr->left = newNode(arr[i]);
                queue[back++] = curr->left;
            }
            i++;
        }
        // Right child
        if (i < n) {
            if (arr[i] != -1) {
                curr->right = newNode(arr[i]);
                queue[back++] = curr->right;
            }
            i++;
        }
    }

    free(queue);
    return root;
}

// ─── Zigzag Traversal ───────────────────────────────────────────

void zigzagTraversal(TreeNode* root) {
    if (root == NULL) return;

    TreeNode** queue = (TreeNode**)malloc(10000 * sizeof(TreeNode*));
    int front = 0, back = 0;
    queue[back++] = root;

    int leftToRight = 1;
    int firstVal = 1;           // to handle space formatting

    while (front < back) {
        int levelSize = back - front;
        int* levelArr = (int*)malloc(levelSize * sizeof(int));

        for (int i = 0; i < levelSize; i++) {
            TreeNode* node = queue[front++];

            // Write index depends on direction
            if (leftToRight)
                levelArr[i] = node->val;
            else
                levelArr[levelSize - 1 - i] = node->val;

            if (node->left)  queue[back++] = node->left;
            if (node->right) queue[back++] = node->right;
        }

        // Print level
        for (int i = 0; i < levelSize; i++) {
            if (!firstVal) printf(" ");
            printf("%d", levelArr[i]);
            firstVal = 0;
        }

        free(levelArr);
        leftToRight = !leftToRight;
    }
    printf("\n");
    free(queue);
}


int main() {
    int n;
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    TreeNode* root = buildTree(arr, n);
    zigzagTraversal(root);

    free(arr);
    return 0;
}