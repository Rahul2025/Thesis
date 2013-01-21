#include<stdio.h>
int main()
{
int t,i;
long int n,u,value,a;
scanf("%d",&t);
for(i=1;i<=t;i++)
{
scanf("%li",&n);
value=1;
u=2;
a=n;
n=n-1;
while(n>0)
{
if(n%2!=0)
{
value=(value*u)%8388608;
}
n=n/2;
u=(u*u)%8388608;
}
n=a;
u=(((n-1)%8388608*(n%8388608))%8388608+2)%8388608;
value=(u*value)%8388608;
if(value!=0)
{printf("%li\n",value-1);}
else
{printf("8388607\n");}
}
return 0;
}




