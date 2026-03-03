#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* createNode(int data){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

Node* insertAtEnd(Node* head,int data){
    Node* newNode=createNode(data);
    if(head==NULL){
        newNode->next=newNode;
        return newNode;
    }
    Node* temp=head;
    while(temp->next!=head)
        temp=temp->next;
    temp->next=newNode;
    newNode->next=head;
    return head;
}

void printCircular(Node* head){
    if(head==NULL) return;
    Node* temp=head;
    do{
        printf("%d ",temp->data);
        temp=temp->next;
    }while(temp!=head);
}

void freeList(Node* head){
    if(head==NULL) return;
    Node* temp=head->next;
    while(temp!=head){
        Node* next=temp->next;
        free(temp);
        temp=next;
    }
    free(head);
}

int main(){
    int n,val;
    Node* head=NULL;

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&val);
        head=insertAtEnd(head,val);
    }

    printCircular(head);
    freeList(head);
    return 0;
}