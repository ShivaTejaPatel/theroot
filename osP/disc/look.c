#include<stdio.h>
#include<stdlib.h>
void main()
{
	int n,i,a[30],head,tt;
	printf("enter the number of tracks");
	scanf("%d",&n);
	printf("enter the order of request");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("enter the read/write head");
	scanf("%d",&head);
	printf("enter the total number of tracks");
	scanf("%d",&tt);
	int min=INT_MAX,max=INT_MIN;
	for(i=0;i<n;i++)
	{
		if(max<a[i])
		{
			max=a[i];
		}
		if(min>a[i])
		{
			min=a[i];
		}
	}
	int ch,sum=0;
	printf("enter direction");
	printf("enter 1 if towards larger enter 0 if towards smaller");
	scanf("%d",&ch);
	if(ch==1)
	{
		sum=abs(max-head)+abs(max-min);
	}
	else
	{
		sum=abs(min-head)+abs(min-max);
	}
	printf("total number of head movements %d",sum);
}
