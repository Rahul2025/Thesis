// filename :: q1_mem.c


#include<stdio.h>
s[1000]={0};
long long int byte(long long int a)
{
if(a<=11)
return a;
if(a<1000)
{
if(s[a]==0)

s[a]=byte(a/2)+byte(a/3)+byte(a/4); return s[a];
}
else
return(byte(a/2)+byte(a/3)+byte(a/4));
}
int main()
{
long long int n;
while((scanf("%lld",&n))>0)
{
printf("%lld\n",byte(n));
}
return 0;
}