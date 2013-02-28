#include<stdio.h>
int main()
{
    long long int t,n,c,a[101],i,j,sum;
    scanf("%lld",&t);
    for(i=1;i<=t;i++)
    {
                     scanf("%lld",&n);
                     scanf("%lld",&c);
                     sum=0;
                     for(j=1;j<=n;j++)
                     {
                                      scanf("%lld",&a[j]);
                                      sum=sum+a[j];
                     }
                     if(sum<=c)
                     printf("Yes\n");
                     else
                     printf("No\n");
    }
    return 0;
}