#include<stdio.h>
int main()
{
    int t,n,a,b,i,x;
    scanf("%d",&t);
    while(t--)
    {
              scanf("%d%d%d",&n,&a,&b); 
              x=0;
              for(i=0;i<n;i++)
              {
                              if(a&1)
                                     x++;
                              if(b&1)
                                     x++;
                              a=a>>1;
                              b=b>>1;
              }
              a=0;
              //printf("%d",x);
              if(x>n)
                     x=2*n-x;
              for(i=1;i<=x;i++)
              {
                               a=a<<1;
                               a=a|1;
              }
              while(i<=n)
              {
                         a=a<<1;
                         i++;
              }
               
              printf("%d\n",a);     
    }
    return 0;
}
              