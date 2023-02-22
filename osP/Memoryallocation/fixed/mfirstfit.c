#include<stdio.h>
#include<stdlib.h>
int p1[100];
int main()
{
    int n,m,i,flag,sum=0,j,in=0,ind=0,a,x=0;
    printf("enter number of processors");
    scanf("%d",&n);
    printf("enter number of  blocks");
    scanf("%d",&m);
    int p[n],b[m],vb[m];
    printf("\n enter proccess sizes and blocks");
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
    	for(j=1;j<=m;j++)
    	{
    		if(vb[j]==0 && p[i]<=b[j])
    		{
    			p1[i]=b[j];
    			vb[j]=1;
    			break;
			}
		}
		if(j>m)
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
	printf("\nprocessor\t\tblock\n");
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
