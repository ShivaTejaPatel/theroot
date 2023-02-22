#include<stdio.h>
#include<stdlib.h>
void main()
{
	int n,i,a[30],head,j;
	printf("enter the number of tracks");
	scanf("%d",&n);
	printf("enter the order of request");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("enter the read/write head");
	scanf("%d",&head);
	a[n]=head;
	n++;
	for(i=0;i<n-1;i++)
	{
	    for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
			   int temp=a[j];
			   a[j]=a[j+1];
			   a[j+1]=temp;
			}
		}	
	}
	int sum=0,ind;
	for(i=0;i<n;i++)
	{
	   if(head==a[i])
	   {
	   	ind=i;
	   }
    }
	j=ind+1;
	i=ind-1;
	while(i>0||j<n)
	{
	   if(abs(a[ind]-a[i])<abs(a[ind]-a[j])&&i>=0)
	   {
	   	sum=sum+abs(a[ind]-a[i]);
	   	ind=i;
	   	i=ind-1;
	   }
	   else
	   {
	   	sum=sum+abs(a[ind]-a[j]);
	   	ind=j;
	   	j=ind+1;
	   }
	}
	printf("\n\ntotal number of head movements %d",sum);
}
