#include <stdio.h>
#define MAX 1000

int heap[MAX];
int size=0;

void swap(int *a,int *b){
    int t=*a; *a=*b; *b=t;
}

void heapifyUp(int i){
    while(i>0){
        int p=(i-1)/2;
        if(heap[p]<=heap[i]) break;
        swap(&heap[p],&heap[i]);
        i=p;
    }
}

void heapifyDown(int i){
    while(1){
        int l=2*i+1,r=2*i+2,small=i;
        if(l<size && heap[l]<heap[small]) small=l;
        if(r<size && heap[r]<heap[small]) small=r;
        if(small==i) break;
        swap(&heap[i],&heap[small]);
        i=small;
    }
}

void insert(int x){
    heap[size]=x;
    heapifyUp(size);
    size++;
}

int extractMin(){
    if(size==0) return -1;
    int val=heap[0];
    heap[0]=heap[--size];
    heapifyDown(0);
    return val;
}

int peek(){
    if(size==0) return -1;
    return heap[0];
}

int main(){
    int n,x;
    char op[20];

    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%s",op);

        if(op[0]=='i'){
            scanf("%d",&x);
            insert(x);
        }
        else if(op[0]=='p'){
            printf("%d\n",peek());
        }
        else if(op[0]=='e'){
            printf("%d\n",extractMin());
        }
    }

    return 0;
}