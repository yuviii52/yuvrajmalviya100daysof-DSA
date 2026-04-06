#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left, *right;
} TreeNode;

TreeNode* newNode(int val) {
    TreeNode* node = malloc(sizeof(TreeNode));
    node->val   = val;
    node->left  = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* searchBST(struct TreeNode* root, int val) {
    if (root == NULL || root->val == val)
        return root;
    if (val < root->val)
        return searchBST(root->left, val);
    return searchBST(root->right, val);
}

void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

int main() {
    TreeNode* root    = newNode(4);
    root->left        = newNode(2);
    root->right       = newNode(7);
    root->left->left  = newNode(1);
    root->left->right = newNode(3);

    int val = 2;
    TreeNode* result = searchBST(root, val);
    if (result) {
        printf("Subtree rooted at %d (inorder): ", val);
        inorder(result);
        printf("\n");
    } else {
        printf("Val %d not found. Return NULL.\n", val);
    }

    val = 5;
    result = searchBST(root, val);
    if (result) {
        printf("Subtree rooted at %d (inorder): ", val);
        inorder(result);
        printf("\n");
    } else {
        printf("Val %d not found. Return NULL.\n", val);
    }

    return 0;
}