#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct {
    int arr[MAX];
    int top;
} Stack;

typedef struct {
    int arr[MAX];
    int front, rear;
} Queue;

void push(Stack *s, int x) {
    s->arr[++s->top] = x;
}

int pop(Stack *s) {
    return s->arr[s->top--];
}

void enqueue(Queue *q, int x) {
    q->arr[++q->rear] = x;
}

int dequeue(Queue *q) {
    return q->arr[q->front++];
}

int main() {
    int N, x;
    scanf("%d", &N);

    Stack s;
    Queue q;
    s.top = -1;
    q.front = 0;
    q.rear = -1;

    for (int i = 0; i < N; i++) {
        scanf("%d", &x);
        enqueue(&q, x);
    }

    for (int i = 0; i < N; i++) {
        push(&s, dequeue(&q));
    }

    for (int i = 0; i < N; i++) {
        enqueue(&q, pop(&s));
    }

    for (int i = q.front; i <= q.rear; i++) {
        printf("%d ", q.arr[i]);
    }

    return 0;
}