#include<stdio.h>
int Positive(int val){
    if(val>=0){
        return val;
    }
    else{
        return val*(-1);
    }
}
void sort(int *Request,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(Request[j]>Request[j+1]){
                int temp=Request[j];
                Request[j]=Request[j+1];
                Request[j+1]=temp;
            }
        }
    }
}
void RequestAllocationMovingTowordsLessFisrt(int Request[],int head,int n){

    /* sort(Request,n);
    for(int i=0;i<n;i++){
        printf("%d ",Request[i]);
    } */
    printf("\n");
     int all[n+1];//0 is also includes 
    int j,k;
    for(int i=0;i<n;i++){
        if(head==Request[i]){
            j=i;
            k=i;
            break;
        }
    }
    int idx=0;
    while(j>=0){
        all[idx]=Request[j];
        j--;
        idx++;
    }
    all[idx]=0;
    k++;
    
   while(k!=n){
        all[++idx]=Request[k];
        k++;
    } 
    printf("the Allocation of disk order");
    for(int i=0;i<n+1;i++){
        printf("%d ",all[i]);
    }
    int Thm=(head-0)+(Request[n-1]-0);
    printf("\nthe total head movements is =%d",Thm);

} 
void RequestAllocationMovingTowordsGreaterFisrt(int Request[],int head,int n){

    sort(Request,n);
    /* for(int i=0;i<n;i++){
        printf("%d ",Request[i]);
    } */
    printf("\n");
     int all[n+1];//0 is also includes 
    int j,k;
    for(int i=0;i<n;i++){
        if(head==Request[i]){
            j=i;
            k=i;
            break;
        }
    }
    int idx=0;
   
   while(k!=n){
        all[idx++]=Request[k];
        k++;
    }
    j--;
     while(j>=0){
        all[idx]=Request[j];
        j--;
        idx++;
    }
    all[idx]=0;
     
    printf("the Allocation of disk order");
    for(int i=0;i<n+1;i++){
        printf("%d ",all[i]);
    }
    int Thm=(Request[n-1]-0)+(Request[n-1]-head);
    printf("\nthe total head movements is =%d",Thm);

} 

int main(){
    printf("enter the no of requested tracks");
    int n;
    scanf("%d",&n);
    int Request[n+1];
    int i;
    for(i=0;i<n;i++){
        scanf("%d",&Request[i]);
    }
    printf("enter the initially head at");
    int head;
    scanf("%d",&head);
    Request[n]=head;
    n++;//one element is incresed 
    //RequestAllocationMovingTowordsLessFisrt(Request,head,n);
    RequestAllocationMovingTowordsGreaterFisrt(Request,head,n);
   // 95 180 34 119 11 123 62 64


return 0;
}
