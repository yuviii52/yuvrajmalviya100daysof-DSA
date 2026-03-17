#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue(int x) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;

    if (rear == NULL) {
        front = rear = newNode;
        return;
    }

    rear->next = newNode;
    rear = newNode;
}

int dequeue() {
    if (front == NULL)
        return -1;

    struct Node* temp = front;
    int val = temp->data;
    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
    return val;
}

int main() {
    int N;
    scanf("%d", &N);

    while (N--) {
        int op;
        scanf("%d", &op);

        if (op == 1) {
            int x;
            scanf("%d", &x);
            enqueue(x);
        } else if (op == 2) {
            printf("%d\n", dequeue());
        }
    }

    return 0;
}