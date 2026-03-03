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
    if(head==NULL) return newNode;
    Node* temp=head;
    while(temp->next) temp=temp->next;
    temp->next=newNode;
    return head;
}

int getLength(Node* head){
    int len=0;
    while(head){
        len++;
        head=head->next;
    }
    return len;
}

Node* rotateRight(Node* head,int k){
    if(head==NULL || head->next==NULL || k==0) return head;

    int n=getLength(head);
    k=k%n;
    if(k==0) return head;

    Node* tail=head;
    while(tail->next) tail=tail->next;

    tail->next=head;

    int steps=n-k;
    Node* temp=head;
    for(int i=1;i<steps;i++)
        temp=temp->next;

    head=temp->next;
    temp->next=NULL;

    return head;
}

void printList(Node* head){
    while(head){
        printf("%d ",head->data);
        head=head->next;
    }
}

void freeList(Node* head){
    Node* temp;
    while(head){
        temp=head;
        head=head->next;
        free(temp);
    }
}

int main(){
    int n,k,val;
    Node* head=NULL;

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&val);
        head=insertAtEnd(head,val);
    }

    scanf("%d",&k);

    head=rotateRight(head,k);

    printList(head);
    freeList(head);
    return 0;
}