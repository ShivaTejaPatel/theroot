#include<stdio.h>
void sort(int *track,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n-1;j++){
            if(track[j]>track[j+1]){
                int temp=track[j];
                track[j]=track[j+1];
                track[j+1]=temp;
            }
        }
    }
}
void requestAllocation(int track[],int n,int head){
    printf("enter the direction to go 1 for + and -1 for -");
    int d;
    scanf("%d",&d);
    sort(track,n);
    int thm=0;
    
    if(d==1){
        //find head
        int idx;
        for(int i=0;i<n;i++){
            if(head==track[i]){
                 idx=i;
            }
        }
        
        for(int i=idx;i<n;i++){
            printf("%d  ",track[i]);
        }
        for(int i=0;i<idx;i++){
            printf("%d  ",track[i]);
        }
        printf("\nthe total head movements is =%d",track[n-1]-head+head-track[0]);
    }
    else if(d==-1){
        //find head
        int idx;
        for(int i=0;i<n;i++){
            if(head==track[i]){
                 idx=i;
            }
        }
        
       
        for(int i=idx;i>=0;i--){
            printf("%d  ",track[i]);
        }
         for(int i=n-1;i>idx;i--){
            printf("%d  ",track[i]);
        }
        printf("\nthe total head movements is =%d",track[n-1]-head+head-track[0]);
        
    }
}
void main(){
    printf("enter the no of requests");
    int n;
    scanf("%d",&n);
    int tracks[100];
    printf("enter the request tracks nos:");
    for(int i=0;i<n;i++){
        scanf("%d",&tracks[i]);
    }
    //tracks[n]=nt;//initial
    //tracks[n+1]=0;//final
    printf("enter the head position:");
    int head;
    scanf("%d",&head);
    int f=0;
    for(int i=0;i<n+2;i++){
        if(head==tracks[i]){
            f=1;
        }
    }

    

    if(f==1){
        requestAllocation(tracks,n,head);
    }
    else{
        tracks[n]=head;
        requestAllocation(tracks,n+1,head);
    }
}