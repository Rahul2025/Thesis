#include<stdio.h>
int main()
{
    int t,n,i,j,sum=0;
    int w[30];
    int wl[30];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&w[i]);
        for(i=0;i<n;i++)
            scanf("%d",&wl[i]);
        for(i=0;i<n;i++)
        {
            for(j=0;j<i;j++)
            {
                if(wl[i]<wl[j])
                {
                    wl[i]=wl[i]+wl[j];
                    wl[j]=wl[i]-wl[j];
                    wl[i]=wl[i]-wl[j];
                }                  
                    
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(w[i]<=wl[j])
                {
                    wl[j]=0;
                    sum++;break;
                }
            }
        }
        printf("%d\n",sum);
        sum=0;
        
        
    }
    return 0;
}