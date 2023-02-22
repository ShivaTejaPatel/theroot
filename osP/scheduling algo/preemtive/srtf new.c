#include<stdio.h>
#include<limits.h>
int a[20],b[20],p,visit[20],sec=0,temp[20],t[20];
int findmin()
{
	int i,v=0,k=0,process=0, min=INT_MAX,bmin=INT_MAX;
	for(i=0;i<p;i++)
	{
		if(a[i]<=sec && visit[i]!=1)
		{
			v++;
		}
	}
	
	if(v==0)						//for idle time
	{
		for(i=0;i<p;i++)
		{
			if(visit[i]!=1 && a[i]<min)
			{
				k=i;
				min=a[i];	
			}
			else if(visit[i]!=1 && a[i]==min)
			{
				if(b[i]<b[k])
				{
					min=a[i];
					k=i;
				}
			}
		}
		return k;
	}
	else
	{
		for(i=0;i<p;i++)
		{
			if(visit[i]!=1 && b[i]<bmin && a[i]<=sec)
			{
				process=i;
				bmin=b[i];
			}
			else if(visit[i]!=1 && b[i]==bmin && a[i]<=sec)
			{
				if(a[i]<a[process])
				{
					process=i;
					bmin=b[i];
				}
			}
		}
	}
	return process;
}
int SRTF()
{
	int i=0,x,k=0,TAT[10],WT[10],totwt=0,totta=0,y=0,c[10];
	float awt,ata;
	while(i!=p)
	{
		x=findmin();
		if(a[x]>sec)
		{
			temp[k++]=100;
			sec=sec+1;
		}
		temp[k++]=x+1;
		b[x]=b[x]-1;
		sec=sec+1;
		if(b[x]==0)
		{
			visit[x]=1;
			c[x]=sec;
			i++;
		}
	}
	for(i=0;i<p;i++)
	{
		TAT[i]=c[i]-a[i];
		WT[i]=TAT[i]-t[i];
	}
	printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
	for(i=0;i<p;i++)
	{
		printf("\n%d\t%d\t%d\t%d\t%d\t%d",i+1,a[i],t[i],c[i],TAT[i],WT[i]);
	}
	printf("\n gun chatt is");
	for(i=0;i<k;i++)
	{
		printf("%d ",temp[i]);
	}
	for(i=0; i<p; i++)
    {
    	totwt=totwt+WT[i];
    	totta=totta+TAT[i];
    }
	awt=(float)totwt/p;
    ata=(float)totta/p;
	printf("\nAverage waiting time is:%f",awt);
    printf("\nAverage turnaroundtime is:%f",ata);	
}
void main()
{
	int i;
	printf("Enter no.of processes: ");
	scanf("%d",&p);
	printf("Enter Arrival times(AT) and Burst times(BT) of processes\n");
	for(i=0;i<p;i++)
	{
		scanf("%d %d",&a[i],&b[i]);
	}
	for(i=0;i<p;i++)
	{
		visit[i]=0;
	}
	for(i=0;i<p;i++)
	{
		t[i]=b[i];
	}
	printf("your input values are: \n");
	printf("AT\tBT\n");
	for(i=0;i<p;i++)
	{
		printf("\n%d\t%d",a[i],b[i]);
	}
	SRTF();
}
