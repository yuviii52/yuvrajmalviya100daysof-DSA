#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
}Node;

typedef struct{
    Node* front;
    Node* rear;
    int size;
}Deque;

Deque* createDeque(){
    Deque* dq=(Deque*)malloc(sizeof(Deque));
    dq->front=NULL;
    dq->rear=NULL;
    dq->size=0;
    return dq;
}

void push_front(Deque* dq,int val){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=val;
    newNode->prev=NULL;
    newNode->next=dq->front;

    if(dq->front)
        dq->front->prev=newNode;
    else
        dq->rear=newNode;

    dq->front=newNode;
    dq->size++;
}

void push_back(Deque* dq,int val){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=val;
    newNode->next=NULL;
    newNode->prev=dq->rear;

    if(dq->rear)
        dq->rear->next=newNode;
    else
        dq->front=newNode;

    dq->rear=newNode;
    dq->size++;
}

void pop_front(Deque* dq){
    if(dq->front==NULL) return;
    Node* temp=dq->front;
    dq->front=dq->front->next;

    if(dq->front)
        dq->front->prev=NULL;
    else
        dq->rear=NULL;

    free(temp);
    dq->size--;
}

void pop_back(Deque* dq){
    if(dq->rear==NULL) return;
    Node* temp=dq->rear;
    dq->rear=dq->rear->prev;

    if(dq->rear)
        dq->rear->next=NULL;
    else
        dq->front=NULL;

    free(temp);
    dq->size--;
}

int front(Deque* dq){
    if(dq->front==NULL) return -1;
    return dq->front->data;
}

int back(Deque* dq){
    if(dq->rear==NULL) return -1;
    return dq->rear->data;
}

int empty(Deque* dq){
    return dq->size==0;
}

int size(Deque* dq){
    return dq->size;
}

void clear(Deque* dq){
    while(dq->front)
        pop_front(dq);
}

void reverse(Deque* dq){
    Node* curr=dq->front;
    Node* temp=NULL;

    while(curr){
        temp=curr->prev;
        curr->prev=curr->next;
        curr->next=temp;
        curr=curr->prev;
    }

    temp=dq->front;
    dq->front=dq->rear;
    dq->rear=temp;
}

void display(Deque* dq){
    Node* temp=dq->front;
    while(temp){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main(){
    int n,val;
    char op[20];
    Deque* dq=createDeque();

    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%s",op);

        if(strcmp(op,"push_front")==0){
            scanf("%d",&val);
            push_front(dq,val);
        }
        else if(strcmp(op,"push_back")==0){
            scanf("%d",&val);
            push_back(dq,val);
        }
        else if(strcmp(op,"pop_front")==0){
            pop_front(dq);
        }
        else if(strcmp(op,"pop_back")==0){
            pop_back(dq);
        }
        else if(strcmp(op,"front")==0){
            printf("%d\n",front(dq));
        }
        else if(strcmp(op,"back")==0){
            printf("%d\n",back(dq));
        }
        else if(strcmp(op,"size")==0){
            printf("%d\n",size(dq));
        }
        else if(strcmp(op,"empty")==0){
            printf("%d\n",empty(dq));
        }
        else if(strcmp(op,"clear")==0){
            clear(dq);
        }
        else if(strcmp(op,"reverse")==0){
            reverse(dq);
        }
        else if(strcmp(op,"display")==0){
            display(dq);
        }
    }

    clear(dq);
    free(dq);
    return 0;
}