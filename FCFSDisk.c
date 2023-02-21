#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n;
	printf("enter the no.of disk request:");
	scanf("%d",&n);
	int d[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&d[i]);
	}
	int head;
	int sum=0;
	scanf("%d",&head);
	printf("%d ",head);
	for(int i=0;i<n;i++)
	{
		int k=head-d[i];
		sum+=abs(k);
		head=d[i];
		printf("%d ",head);

	}
	printf("\n%d",sum);
}