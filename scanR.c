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
		printf("%d ",d[i]);
	}
	if(d[n-1]!=t-1)
	{
		printf("%d ",t-1);
	}
	for(int i=j-1;i>=0;i--)
	{
		printf("%d ",d[i]);
	}
	int sum=0;
	sum+=abs(head-(t-1))+abs((t-1)-d[0]);
	printf("\nTotal head movements:%d",sum);
}