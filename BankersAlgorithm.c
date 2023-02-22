#include<stdio.h>
int main()
{
	int p,r,i,j,k;
	printf("Enter No of processes ");
	scanf("%d",&p);
	printf("Enter No. of type of Resources ");
	scanf("%d",&r);
	int allotted[p][r],max[p][r],need[p][r],avail[r],status[p],seq[p];
	printf("\nEnter No of Resources of each type allotted to each process\n");
	for(i=0;i<p;i++)
	{
		for(j=0;j<r;j++)
		{
			scanf("%d",&allotted[i][j]);
		}
		status[i]=0;
	}
	printf("\nEnter Maximum No of Resources of each type for each process\n");
	for(i=0;i<p;i++)
	{
		for(j=0;j<r;j++)
		{
			scanf("%d",&max[i][j]);
		}
	}
	printf("Enter No. of Resources of each type available\n");
	for(i=0;i<r;i++)
	{
		scanf("%d",&avail[i]);
	}
	for(i=0;i<p;i++)
	{
		for(j=0;j<r;j++)
		{
			need[i][j]=max[i][j]-allotted[i][j];
		}
	}
	int x=0,y=0,flag;
	for(i=0;i<p;i++)
	{
		for(j=0;j<p;j++)
		{
			if(status[j]==0)//process not completed
			{
				flag=0;
				for(k=0;k<r;k++)
				{
					if(need[j][k]>avail[k])
					{
						flag=1;
						break;
					}
				}
				if(flag==0)
				{
					seq[x++]=j; // jth process can be completed so added in sequence
					status[j]=1;// updating status of jth process
					for(y=0;y<r;y++)
					{
						avail[y]+=allotted[j][y]; //releasing resources which were alloted to jth process
					}
				}
			}
		}
	}
	flag=0;
	for(i=0;i<p;i++)
	{
		if(status[i]==0)
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
	{
		printf("The System is Not Safe\n");
	}
	else
	{
		printf("The safe sequence is\n");
		for(i=0;i<p;i++)
		{
			printf("P%d ",seq[i]);
		}
	}
}

//alloted
//0 1 0
//2 0 0
//3 0 2 
//2 1 1 
//0 0 2

//max needed
//7 5 3
//3 2 2
//9 0 2
//2 2 2
//4 3 3

//available
//3 3 2

//safe sequence
// P1 -> P3 -> P4 -> P0 -> P2