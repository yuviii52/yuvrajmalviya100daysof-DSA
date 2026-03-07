#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* push(Node* top,int val){
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->data=val;
    newNode->next=top;
    return newNode;
}

Node* pop(Node* top,int* val){
    if(top==NULL) return NULL;
    Node* temp=top;
    *val=temp->data;
    top=top->next;
    free(temp);
    return top;
}

int main(){
    char expr[100];
    fgets(expr,sizeof(expr),stdin);

    Node* top=NULL;
    char* token=strtok(expr," \n");

    while(token){
        if(isdigit(token[0])){
            top=push(top,atoi(token));
        }else{
            int b,a;
            top=pop(top,&b);
            top=pop(top,&a);

            int res;
            if(token[0]=='+') res=a+b;
            else if(token[0]=='-') res=a-b;
            else if(token[0]=='*') res=a*b;
            else if(token[0]=='/') res=a/b;

            top=push(top,res);
        }
        token=strtok(NULL," \n");
    }

    int result;
    top=pop(top,&result);
    printf("%d",result);

    return 0;
}