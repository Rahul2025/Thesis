#include<stdio.h>
int main()
{
long long int temp1,temp2,temp3,temp4;
long long int n,m,p,q,max,min,a[2][2],b[2][2];
int t,i;
scanf("%d",&t);
for(i=1;i<=t;i++)
{
scanf("%lld %lld",&n,&m);
b[0][0]=1;
b[0][1]=0;
b[1][0]=0;
b[1][1]=1;
a[0][0]=1;
a[1][0]=1;
a[0][1]=1;
a[1][1]=0;
p=2*n-2;
while(p>0)
{
if(p%2!=0)
{
temp1=(b[0][0]*a[0][0])%m+(b[0][1]*a[1][0])%m;
temp2=(b[0][0]*a[0][1])%m+(b[0][1]*a[1][1])%m;
temp3=(b[1][0]*a[0][0])%m+(b[1][1]*a[1][0])%m;
temp4=(b[1][0]*a[0][1])%m+(b[1][1]*a[1][1])%m;
b[0][0]=temp1%m;
b[0][1]=temp2%m;
b[1][0]=temp3%m;
b[1][1]=temp4%m;
}
p=p/2;
temp1=(a[0][0]*a[0][0])%m+(a[0][1]*a[1][0])%m;
temp2=(a[0][0]*a[0][1])%m+(a[0][1]*a[1][1])%m;
temp3=(a[1][0]*a[0][0])%m+(a[1][1]*a[1][0])%m;
temp4=(a[1][0]*a[0][1])%m+(a[1][1]*a[1][1])%m;
a[0][0]=temp1%m;
a[0][1]=temp2%m;
a[1][0]=temp3%m;
a[1][1]=temp4%m;
}
if(n==1)
{
printf("%lld/%lld\n",1%m,1%m);
}
else
{
printf("%lld/%lld\n",(b[1][0]+b[1][1])%m,(b[0][0]+b[0][1])%m);
}
}
return 0;
}




