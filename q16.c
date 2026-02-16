#include <stdio.h>

int main() {
    int n;
    scanf("%d",&n);
    int arr[n],count[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
        count[i]=0;
    }
    for(int i=0;i<n;i++){
        if(count[i]!=-1){
            int c=1;
            for(int j=i+1;j<n;j++){
                if(arr[i]==arr[j]){
                    c++;
                    count[j]=-1;
                }
            }
            count[i]=c;
        }
    }
    for(int i=0;i<n;i++){
        if(count[i]>0)
            printf("%d:%d ",arr[i],count[i]);
    }
    return 0;
}
