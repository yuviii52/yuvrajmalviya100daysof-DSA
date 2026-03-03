#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int coeff;
    int exp;
    struct Node* next;
}Node;

Node* createNode(int coeff,int exp){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->coeff=coeff;
    newNode->exp=exp;
    newNode->next=NULL;
    return newNode;
}

Node* insertAtEnd(Node* head,int coeff,int exp){
    Node* newNode=createNode(coeff,exp);
    if(head==NULL) return newNode;
    Node* temp=head;
    while(temp->next) temp=temp->next;
    temp->next=newNode;
    return head;
}

void printPolynomial(Node* head){
    Node* temp=head;
    while(temp){
        if(temp->exp==0)
            printf("%d",temp->coeff);
        else if(temp->exp==1)
            printf("%dx",temp->coeff);
        else
            printf("%dx^%d",temp->coeff,temp->exp);

        if(temp->next)
            printf(" + ");
        temp=temp->next;
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
    int n,coeff,exp;
    Node* head=NULL;

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %d",&coeff,&exp);
        head=insertAtEnd(head,coeff,exp);
    }

    printPolynomial(head);
    freeList(head);
    return 0;
}