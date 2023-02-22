/*#include <stdio.h> 
#define MAX 20 

  
int main() 
{ 
    int frame[MAX], pages[MAX], m, n, s, pf = 0,c=0; 
  
    
    printf("Enter number of frames: "); 
    scanf("%d", &m); 
  
    
    printf("Enter number of pages: "); 
    scanf("%d", &n); 
  
    
    printf("Enter the reference string: "); 
    for(int i = 0; i < n; i++) 
        scanf("%d", &pages[i]); 
  
    
    for(int i = 0; i < m; i++) 
        frame[i] = -1; 
  
    for(int i = 0; i < n; i++) 
    { 
        s = 0; 
        for(int j = 0; j < m; j++) 
        { 
            if(frame[j] == pages[i]) 
            { 
                s = 1; 
                break; 
            } 
        } 
        if(s == 0) 
        { 
            frame[pf] = pages[i]; 
            pf = (pf + 1) % m; 
            c++;
        } 
        printf("\n"); 
        for(int j = 0; j < m; j++) 
            printf("%d\t", frame[j]); 
    } 
    printf("\npagefaults:%d",c);
    return 0; 
}
*/
#include<stdio.h>

int main()
{
    int frame[20],pages[20],f,p,flag,idx=0,pf=0;

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

    for(int i=0;i<p;i++)
    {
        flag=0;
        for(int j=0;j<f;j++)
        {
            if(frame[j]==pages[i])
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            frame[idx]=pages[i];
            idx=(idx+1)%f;
            pf++;
        }
        for(int i=0;i<f;i++)
        {
            printf("%d\t",frame[i]);
        }
    }
    printf("%d",pf);

}