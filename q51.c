#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

/* ── BST insert ─────────────────────────────────────── */
TreeNode* newNode(int val) {
    TreeNode* n = (TreeNode*)malloc(sizeof(TreeNode));
    n->val = val; n->left = n->right = NULL;
    return n;
}

TreeNode* insert(TreeNode* root, int val) {
    if (!root) return newNode(val);
    if (val < root->val) root->left  = insert(root->left,  val);
    else if (val > root->val) root->right = insert(root->right, val);
    return root;
}

/* ── LCA using BST property ──────────────────────────── */
TreeNode* lca(TreeNode* root, int p, int q) {
    while (root) {
        if (p < root->val && q < root->val)
            root = root->left;
        else if (p > root->val && q > root->val)
            root = root->right;
        else
            return root;          /* split point → LCA */
    }
    return NULL;
}

int main(void) {
    int n;
    scanf("%d", &n);

    TreeNode* root = NULL;
    for (int i = 0; i < n; i++) {
        int v; scanf("%d", &v);
        root = insert(root, v);
    }

    int p, q;
    scanf("%d %d", &p, &q);

    TreeNode* result = lca(root, p, q);
    if (result) printf("%d\n", result->val);

    return 0;
}