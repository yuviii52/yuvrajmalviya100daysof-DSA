#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

/* ── Build tree from level-order input (-1 = NULL) ── */
TreeNode* newNode(int val) {
    TreeNode* n = (TreeNode*)malloc(sizeof(TreeNode));
    n->val = val; n->left = n->right = NULL;
    return n;
}

TreeNode* buildTree(int* arr, int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    TreeNode** queue = (TreeNode**)malloc(n * sizeof(TreeNode*));
    int front = 0, back = 0;

    TreeNode* root = newNode(arr[0]);
    queue[back++] = root;
    int i = 1;

    while (front < back && i < n) {
        TreeNode* curr = queue[front++];

        if (i < n) {                              /* left child */
            if (arr[i] != -1) {
                curr->left = newNode(arr[i]);
                queue[back++] = curr->left;
            }
            i++;
        }
        if (i < n) {                              /* right child */
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

/* ── LCA via post-order DFS ── */
TreeNode* lca(TreeNode* root, int p, int q) {
    if (root == NULL)                     return NULL;
    if (root->val == p || root->val == q) return root;

    TreeNode* left  = lca(root->left,  p, q);
    TreeNode* right = lca(root->right, p, q);

    if (left && right) return root;       /* split point → LCA */
    return left ? left : right;           /* bubble up the find */
}

int main(void) {
    int n;
    scanf("%d", &n);

    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    int p, q;
    scanf("%d %d", &p, &q);

    TreeNode* root = buildTree(arr, n);
    TreeNode* result = lca(root, p, q);
    if (result) printf("%d\n", result->val);

    free(arr);
    return 0;
}