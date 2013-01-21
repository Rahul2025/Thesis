#include <stdio.h>
 
long long f(long long n)
{
                long long r;
                if(n<0)
                       return 0;
                r=((n+1)*(n+2)*(n+3));
                return r/6;
}
 main() 
{
                int t;
                  long long n,a,b,c,ct;
                scanf("%d",&t);
                while(t--){
              
                  scanf("%lld%lld%lld%lld",&n,&a,&b,&c);
                  ct=f(n)-f(n-a-1)-f(n-b-1)-f(n-c-1)+f(n-a-b-2)+f(n-b-c-2)+f(n-a-c-2)-f(n-a-b-c-3);
                  printf("%lld\n",ct);  
                  
                }
                return 0;
}