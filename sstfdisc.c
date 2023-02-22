#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

int main(){
         int n;
	scanf("%d",&n);
       int arr[n];
       for(int i=0;i<n;i++){
        	   scanf("%d",&arr[i]);
       }
       int head;
       printf("enter head");
       scanf("%d",&head);
       int sum=0;
       int vis[n];
       memset(vis,0,sizeof(vis));
       for(int i=0;i<n;i++){
           int min=INT_MAX;
           int index=0;
          for(int j=0;j<n;j++){
               if((abs(arr[j]-head)<=min)&&vis[j]==0){
                     min=abs(arr[j]-head);
                     index=j;

               }
          }
          printf("min:%d\n",min);
          sum=sum+min;
          head=arr[index];
          vis[index]=1;
       }
       printf("total head movements");
       printf("%d",sum);
       
}

