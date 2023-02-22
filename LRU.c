#include<stdio.h>
#include<limits.h>

int main()
{
    int frame[20],pages[20],f,p,flag,idx=0,pf=0;
    int count[100];
    int c=0;

    printf("Enter number of frames:");
    scanf("%d",&f);
     printf("\nEnter number of pages:");
    scanf("%d",&p);
    printf("\nENter the sequence:");
    for(int i=0;i<p;i++)
    {
        scanf("%d",&pages[i]);
    }
    for(int i=0;i<f;i++)
    {
        frame[i]=-1;
    }
    for(int i=0;i<f;i++)
    {
        count[i]=0;
    }
    for(int i=0;i<p;i++)
    {
        int flag=0;
        for(int j=0;j<f;j++)
        {
            if(frame[j]==pages[i])
            {
                flag=1;
                c++;
                count[j]=c;

                break;
            }
        }
        if(flag==0)
        {
            int min=INT_MAX,l,k;
            for( k=0;k<f;k++)
            {
                if(count[k]<min)
                {
                    min=count[k];
                    l=k;
                }
            }
            frame[l]=pages[i];
            c++;
            count[l]=c;
            pf++;
        }
        for(int m=0;m<f;m++)
        {
            printf("%d\t",frame[m]);
        }
        printf("\n");
    }
    printf("%d",pf);
}