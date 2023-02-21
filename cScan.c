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
    printf("enter the end track no Or total no of tracks");
    int nt;
    scanf("%d",&nt);
    tracks[n]=nt;//initial
    tracks[n+1]=0;//final
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
        requestAllocation(tracks,n+2,head);
    }
    else{
        tracks[n+2]=head;
        requestAllocation(tracks,n+3,head);
    }
}