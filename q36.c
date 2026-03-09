#include <stdio.h>
#define MAX 1000

int queue[MAX];
int front=0,rear=0,size=0;

void enqueue(int x){
    queue[rear]=x;
    rear=(rear+1)%MAX;
    size++;
}

void dequeue(){
    if(size>0){
        front=(front+1)%MAX;
        size--;
    }
}

int main(){
    int n,m,x;

    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        enqueue(x);
    }

    scanf("%d",&m);
    for(int i=0;i<m;i++)
        dequeue();

    int idx=front;
    for(int i=0;i<size;i++){
        printf("%d ",queue[idx]);
        idx=(idx+1)%MAX;
    }

    return 0;
}