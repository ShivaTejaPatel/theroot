#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>
int comparator(const void *p,const void *q)
{
	return(*(int *)p-*(int *)q);
}
int main()
{
	int t;
	printf("Enter total tracks");
	scanf("%d",&t);
	int n;
	printf("enter the no.of disk request:");
	scanf("%d",&n);
	int d[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&d[i]);
	}
	int head;
	scanf("%d",&head);
	int vis[n];
	qsort((void *)d,n,sizeof(int),comparator);
	int j;
	for(int i=0;i<n;i++)
	{
		if(d[i]>=head)
		{
			j=i;
			break;
		}
	}
	printf("%d ",head);
	for(int i=j;i<n;i++)
	{
		if(d[i]!=head)
		{
			printf("%d ",d[i]);
		}
	}
	if(d[n-1]!=t-1)
	{
		printf("%d ",t-1);
	}
	if(j!=0)
	{
		printf("0 ");
		for(int i=0;i<j;i++)
		{
			printf("%d ",d[i]);
		}
	}
	int sum=0;
	sum+=(t-1-head);
	if(j!=0)
	{
		sum+=d[j-1]+(t-1);
	}
	printf("\nTotal head movements:%d",sum);
}