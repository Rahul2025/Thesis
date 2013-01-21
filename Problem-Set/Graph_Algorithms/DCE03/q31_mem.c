#include<stdio.h>
 int main()
{
        int t,n,j,i;
        scanf("%d",&t);
        while(t--)
        {
                long long int a[1001]={0};
        scanf("%d",&n);
        a[1]=1;
        for(i=2;i<=n;i++)
        {
                for(j=1;j<=i-1;j++)
                        a[i]+=a[j]*a[i-j];      
                a[i]%=10000;
        }
        printf("%lld\n",a[n]);
        }
return 0;
}