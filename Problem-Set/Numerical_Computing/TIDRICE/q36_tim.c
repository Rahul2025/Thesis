#include <stdio.h>
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,sum=0,i,j;
        char a[111][22],vote[111];
        scanf("%d",&n);
        for(i=0;i<n;i++)
        scanf("%s %s",&a[i],&vote[i]);
        for(i=0;i<n;i++)
        {
            if(vote[i]=='+')
            {
                for(j=i-1;j>=0;j--)
                if(strcmp(a[i],a[j])==0)
                {
                    if(vote[j]=='-')
                    sum=sum+2;
                    break;
                }
                if(j==-1)
                sum++;
            }
             else if(vote[i]=='-')
            {
                for(j=i-1;j>=0;j--)
                if(strcmp(a[i],a[j])==0)
                {
                    if(vote[j]=='+')
                    sum=sum-2;
                    break;
                }
                if(j==-1)
                sum--;
            }
        }
        printf("%d\n",sum);

    }
    return 0;
}