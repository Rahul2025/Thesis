#include<stdio.h>
#include<string.h>
inline int inp( )
{
int n=0;
int ch=getchar_unlocked();
while( ch <48 )ch=getchar_unlocked();
while( ch >47 )
n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
return n;
}
int main()
{
    int a[1001],i,n,k,j,t,m;
    t=inp();
    while(t--)
    {
        n=inp();
        k=inp();
        memset(a,0,sizeof(a));
        a[0]=1;
        for(i=0;i<n;i++)
        {
            m=inp();
            if(m<1000)
            for(j=k-m;j>=0&&a[k]==0;j--)
            if(a[j]==1)
            a[j+m]=1;
        }
        printf("%d\n",a[k]);
    }
    return 0;
}