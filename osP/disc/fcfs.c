#include<stdio.h>
#include<stdlib.h>
void main()
{
	int n,i,a[30],head;
	printf("enter the number of tracks");
	scanf("%d",&n);
	printf("enter the order of request");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("enter the read/write head");
	scanf("%d",&head);
	int sum=0;
	for(i=0;i<n;i++)
	{
		if(i==0)
		{
			sum=sum+abs(a[i]-head);
		}
		else
		{
			sum=sum+abs(a[i]-a[i-1]);
		}
	}
	printf("total number of head movements %d",sum);
}
