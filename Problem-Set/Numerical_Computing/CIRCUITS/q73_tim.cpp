#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

int a[101][3];
int n;
double res[101];

double orf(double x,double y)
{return (x+y-x*y);
}

double andf(double x,double y)
{return (x*y);
}

double solve(double p)
{
int i=1;
for(;i<=n;i++)
{
if(a[i][0]==0)
res[i]=p;

if(a[i][0]==1)
{res[i]=orf(res[a[i][1]],res[a[i][2]]);
}

if(a[i][0]==2)
{res[i]=andf(res[a[i][1]],res[a[i][2]]);
}
}
i--;

return res[i];
}


int main()
{int tc;
scanf("%d",&tc);
while(tc--)
{
scanf("%d",&n);


for(int i=1;i<=n;i++)
{scanf("%d",&a[i][0]);
if(a[i][0]!=0)
{scanf("%d %d",&a[i][1],&a[i][2]);
}
}

//p

double hi=1.000000,lo=0.000000;
double mid,p;
double ans,midp;

for(int j=1;;j++)
{
mid=(hi+lo)/2;
ans=solve(mid);
if(ans==0.50000||((abs(midp-mid)<0.00000001)&&j!=1))
break;
else
{if(ans>0.5)
hi=mid;
if(ans<0.5)
lo=mid;
}
midp=mid;
}

printf("%.5lf\n",mid);
}
return 0;
}