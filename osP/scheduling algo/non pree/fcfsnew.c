#include<stdio.h>
int a[10],b[10],t[10],p[10];
void swap(int a[],int i,int j)
{
	int temp;
	temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}
int main()
{
	int n,i,j;
	float awt,ata;
	float totwt=0,totta=0;
	printf("\n enter noof processsors");
	scanf("%d",&n);
	printf("\n enter processor numbers, arrival times&burst times");
	for(i=0;i<n;i++)
	{
		scanf("%d\t%d\t %d",&p[i],&a[i],&b[i]);
	}
	//sorting as per arrival times
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(a[j]>a[j+1])
			{
				swap(a,j,j+1);
				swap(b,j,j+1);
				swap(p,j,j+1);
			}
		}
	}
	printf("\n after sorting\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t%d\t %d\n",p[i],a[i],b[i]);
	}
	for(i=0;i<n;i++)
	{
		t[i]=0;
	}
	t[-1]=0;
	for(i=0;i<n;i++)
	{
		if(t[i]==0)
		{
		if(a[i]<=t[i-1])
		{
			if(a[i]==a[i+1])
			{
				t[i]=t[i-1]+b[i];
				t[i+1]=t[i]+b[i+1];
			}
			t[i]=t[i-1]+b[i];
		}
		else
		{
			t[i]=a[i]+b[i];
		}
	}
		
	}
	for(i=0; i<n; i++)
    {
    	totwt=totwt+((t[i]-a[i])-b[i]);
    	totta=totta+(t[i]-a[i]);
    }
	awt=(float)totwt/n;
    ata=(float)totta/n;
	printf("\npno\tat\tbt]tct\ttat\twt\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t%d\t%d\t%d\t%d\t%d\n",p[i],a[i],b[i],t[i],(t[i]-a[i]),((t[i]-a[i])-b[i]));
	}
	printf("\nAverage waiting time is:%f",awt);
    printf("\nAverage turnaroundtime is:%f",ata);	
	
}
