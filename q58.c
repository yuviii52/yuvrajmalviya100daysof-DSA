#include <stdio.h>
#include <stdlib.h>

// Tree Node
struct TreeNode {
    int val;
    struct TreeNode *left, *right;
};

// Create node
struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Build tree
struct TreeNode* build(int* preorder, int preStart, int preEnd,
                       int* inorder, int inStart, int inEnd) {
    if (preStart > preEnd || inStart > inEnd) return NULL;

    int rootVal = preorder[preStart];
    struct TreeNode* root = newNode(rootVal);

    int k = inStart;
    while (inorder[k] != rootVal) k++;

    int leftSize = k - inStart;

    root->left = build(preorder, preStart + 1, preStart + leftSize,
                       inorder, inStart, k - 1);

    root->right = build(preorder, preStart + leftSize + 1, preEnd,
                        inorder, k + 1, inEnd);

    return root;
}

// Postorder traversal
void postorder(struct TreeNode* root) {
    if (!root) return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->val);
}

int main() {
    int n;
    scanf("%d", &n);

    int preorder[n], inorder[n];

    for (int i = 0; i < n; i++) scanf("%d", &preorder[i]);
    for (int i = 0; i < n; i++) scanf("%d", &inorder[i]);

    struct TreeNode* root = build(preorder, 0, n - 1, inorder, 0, n - 1);

    postorder(root);

    return 0;
}