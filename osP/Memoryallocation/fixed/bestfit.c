
#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
int p1[100];
int main()
{
    int n,m,i,flag,sum=0,j,in=0,ind=0,a,x=0,min;
    printf("enter number of processors");
    scanf("%d",&n);
    printf("enter number of  blocks");
    scanf("%d",&m);
    int p[n],b[m],vb[m];
    for(i=1;i<=n;i++)
    {
        scanf("%d",&p[i]);
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d",&b[i]);
    }
    for(i=1;i<=m;i++)
    {
        vb[i]=0;
    }
    for(i=1;i<=n;i++)
    {
    	min=INT_MAX;
    	for(j=1;j<=m;j++)
    	{
    		if(vb[j]==0 && p[i]<=b[j])
    		{
    			if(b[j]<min)
    			{
    				min=b[j];
    				ind=j;
				}
			}
		}	
		if(min!=INT_MAX)
		{
			vb[ind]=1;
			p1[i]=b[ind];
		}
		else
		{
			p1[i]=0;
			int sum=0;
			for(i=1;i<=m;i++)
			{
				if(vb[i]==0)
				{
					sum=sum+b[i];
				}
			}
			if(sum>=p[i])
			{
				printf("\n external fragmentation is %d=%d",i,sum);
			}
			
		}
	}
	printf("\nprocessor\t\tblock");
	for(i=1;i<=n;i++)
	{
		printf("%d\t\t%d\n",i,p1[i]);
	}
	for(i=1;i<=n;i++)
	{
		if(p1[i]!=0)
		{
			x=x+(p1[i]-p[i]);
		}
	}
	printf("\n internal fragmentation is %d",x);
}
