#include<stdio.h>

unsigned long long int rev(unsigned long long int n)
{
    int x=0;
    while(n>0)
    {
        x=x*10+n%10;
        n=n/10;
    }
    return x;
}

int Pl(unsigned long long int x)
{
   unsigned long long int d;
   d=x-rev(x);
   if(d==0)
   return 1;
   else
   return 0;
}

int main()
{
    int t, count;
    unsigned long long a;
    scanf("%d", &t);
    while(t--)
    {
        int count=0;
        scanf("%lld", &a);
        while(Pl(a)!=1)
        {
            a=a+rev(a);
            count++;
        }
        printf("%d %d\n", count, a);
    }

    return 0;
}