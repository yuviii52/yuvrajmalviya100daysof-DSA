#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val   = val;
    node->left  = NULL;
    node->right = NULL;
    return node;
}

struct QueueItem {
    struct TreeNode* node;
    int hd;
};

struct QueueItem bfsQueue[MAX];
int front = 0, rear = 0;

void enqueue(struct TreeNode* node, int hd) {
    bfsQueue[rear].node = node;
    bfsQueue[rear].hd   = hd;
    rear++;
}

struct QueueItem dequeue() {
    return bfsQueue[front++];
}

int isQueueEmpty() {
    return front == rear;
}

int hdMap[MAX][MAX];
int hdCount[MAX];
int hdKeys[MAX];
int hdSize = 0;

int getHDIndex(int hd) {
    for (int i = 0; i < hdSize; i++)
        if (hdKeys[i] == hd)
            return i;
    hdKeys[hdSize]  = hd;
    hdCount[hdSize] = 0;
    return hdSize++;
}

struct TreeNode* buildTree(int* arr, int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct TreeNode* root = newNode(arr[0]);
    struct TreeNode* q[MAX];
    int qf = 0, qr = 0;
    q[qr++] = root;
    int i = 1;

    while (qf < qr && i < n) {
        struct TreeNode* curr = q[qf++];

        if (i < n && arr[i] != -1) {
            curr->left = newNode(arr[i]);
            q[qr++]    = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = newNode(arr[i]);
            q[qr++]     = curr->right;
        }
        i++;
    }

    return root;
}

void verticalOrder(struct TreeNode* root) {
    if (!root) return;

    enqueue(root, 0);

    while (!isQueueEmpty()) {
        struct QueueItem item = dequeue();
        struct TreeNode* node = item.node;
        int hd = item.hd;

        int idx = getHDIndex(hd);
        hdMap[idx][hdCount[idx]++] = node->val;

        if (node->left)  enqueue(node->left,  hd - 1);
        if (node->right) enqueue(node->right, hd + 1);
    }

    for (int i = 0; i < hdSize - 1; i++) {
        for (int j = 0; j < hdSize - i - 1; j++) {
            if (hdKeys[j] > hdKeys[j + 1]) {
                int tmp       = hdKeys[j];
                hdKeys[j]     = hdKeys[j + 1];
                hdKeys[j + 1] = tmp;

                tmp            = hdCount[j];
                hdCount[j]     = hdCount[j + 1];
                hdCount[j + 1] = tmp;

                for (int k = 0; k < MAX; k++) {
                    tmp             = hdMap[j][k];
                    hdMap[j][k]     = hdMap[j + 1][k];
                    hdMap[j + 1][k] = tmp;
                }
            }
        }
    }

    for (int i = 0; i < hdSize; i++) {
        for (int j = 0; j < hdCount[i]; j++) {
            if (j > 0) printf(" ");
            printf("%d", hdMap[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[MAX];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct TreeNode* root = buildTree(arr, n);
    verticalOrder(root);

    return 0;
}