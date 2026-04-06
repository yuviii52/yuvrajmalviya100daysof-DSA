#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left, *right;
} TreeNode;

TreeNode* newNode(int val) {
    TreeNode* node = malloc(sizeof(TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (!root) return newNode(val);
    if (val < root->val) root->left  = insertIntoBST(root->left,  val);
    else                 root->right = insertIntoBST(root->right, val);
    return root;
}

void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->val);
    inorder(root->right);
}

int main() {
    TreeNode* root = newNode(4);
    root->left       = newNode(2);
    root->right      = newNode(7);
    root->left->left = newNode(1);
    root->left->right= newNode(3);

    int val = 5;
    root = insertIntoBST(root, val);

    printf("Inorder after inserting %d: ", val);
    inorder(root);
    printf("\n");

    return 0;
}
