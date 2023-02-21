#include<stdio.h>
int Positive(int val){
    if(val>=0){
        return val;
    }
    else{
        return val*(-1);
    }
}
void RequestAllocation(int Request[],int head,int n){
    printf("Request allocation order is:");
    printf("%d  ",head);
    int lastAllocated=head;
    int thm=0;
    int idx1,idx2;
    int isAllocate[100];
    for(int i=0;i<n;i++){
        int min=10000;
        for(int j=0;j<n;j++){
            if(isAllocate[j]!=1 && Positive(lastAllocated-Request[j])<min){
                min=Positive(lastAllocated-Request[j]);
                idx1=i;
                idx2=j;
            }
        }
        printf("%d ",Request[idx2]);
        isAllocate[idx2]=1;
        thm=thm+Positive(lastAllocated-Request[idx2]);
        lastAllocated=Request[idx2];
    }
    printf("\nthe total head movments is:%d",thm);
}
int main(){
    printf("enter the no of requested tracks");
    int n;
    scanf("%d",&n);
    int Request[n];
    for(int i=0;i<n;i++){
        scanf("%d",&Request[i]);
    }
    printf("enter the initially head at");
    int head;
    scanf("%d",&head);
    RequestAllocation(Request,head,n);
   // 95 180 34 119 11 123 62 64


return 0;
}