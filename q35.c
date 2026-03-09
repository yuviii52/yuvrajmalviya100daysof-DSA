#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* front=NULL;
Node* rear=NULL;

void enqueue(int val){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=val;
    newNode->next=NULL;

    if(rear==NULL){
        front=rear=newNode;
        return;
    }

    rear->next=newNode;
    rear=newNode;
}

void display(){
    Node* temp=front;
    while(temp){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

int main(){
    int n,x;
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&x);
        enqueue(x);
    }

    display();
    return 0;
}