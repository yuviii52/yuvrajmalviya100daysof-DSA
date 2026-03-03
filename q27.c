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
    while(temp->next!=NULL) temp=temp->next;
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

Node* getIntersection(Node* head1,Node* head2){
    int len1=getLength(head1);
    int len2=getLength(head2);
    int diff;

    Node* p1=head1;
    Node* p2=head2;

    if(len1>len2){
        diff=len1-len2;
        while(diff--) p1=p1->next;
    }else{
        diff=len2-len1;
        while(diff--) p2=p2->next;
    }

    while(p1 && p2){
        if(p1->data==p2->data) return p1;
        p1=p1->next;
        p2=p2->next;
    }
    return NULL;
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
    int n,m,val;
    Node* head1=NULL;
    Node* head2=NULL;

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&val);
        head1=insertAtEnd(head1,val);
    }

    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d",&val);
        head2=insertAtEnd(head2,val);
    }

    Node* intersection=getIntersection(head1,head2);

    if(intersection)
        printf("%d",intersection->data);
    else
        printf("No Intersection");

    freeList(head1);
    freeList(head2);
    return 0;
}