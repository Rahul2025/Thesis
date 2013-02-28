#include<stdio.h>
int main()
{
 long long int a,b,p,q,r,count;
 
 while(1)
 {
  p=q=r=count=0;
  scanf("%lld%lld",&a,&b);
  if(a==0&&b==0)
   break;
   p=1;
  q=2;
  while(1)
  {
 
  r=p+q;
  p=q;
  q=r;
  if(r>=a&&r<=b)
   count++;
  else if(r>=b)
   break;
  }
  printf("%lld\n",count);
 }
 return 0;
} 