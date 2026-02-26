#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

Node* createNode(int data){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=data;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}

Node* insertAtEnd(Node* head,int data){
    Node* newNode=createNode(data);
    if(head==NULL) return newNode;
    Node* temp=head;
    while(temp->next!=NULL) temp=temp->next;
    temp->next=newNode;
    newNode->prev=temp;
    return head;
}

void printForward(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

void freeList(Node* head){
    Node* temp;
    while(head!=NULL){
        temp=head;
        head=head->next;
        free(temp);
    }
}

int main(){
    int n,value;
    scanf("%d",&n);
    Node* head=NULL;
    for(int i=0;i<n;i++){
        scanf("%d",&value);
        head=insertAtEnd(head,value);
    }
    printForward(head);
    freeList(head);
    return 0;
}