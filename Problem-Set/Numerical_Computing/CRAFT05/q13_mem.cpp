#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
int x,y,z,test,n;
int i,j;

scanf("%d",&test);
while(test--)
{
scanf("%d",&n);
scanf("%d%d%d",&x,&y,&z);

int max=0,amt,a,b;
for(i=1;i<=9;i++)
{
    for(j=0;j<=9;j++)
    {
        amt=i*10000 + x*1000 + y*100 + z*10 + j;
        if(amt%n==0)
        {
            if(amt>max)
            {
            max=amt;
            a=i;
            b=j;
            }
        }
    }
}
if(max/n!=0)
printf("%d %d %d\n",a,b,max/n);
else
printf("0\n");
}
return 0;
}