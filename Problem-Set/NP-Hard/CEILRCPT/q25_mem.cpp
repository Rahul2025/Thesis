#include<stdio.h>
using namespace std;
#define getCh getchar_unlocked

int inp()
{
int t=0;
char c;
c=getCh();
while(c>='0' && c<='9')
{
t=(t<<3)+(t<<1)+c-'0';
c=getCh();
}
return t;
}

int main()
{
int num;
short a,ind,count,mul;
char achc;
achc=getCh();
getCh();
a=achc-'0';
while(a--)
{
num=inp();
count=0;
ind=0;
mul=1;
while(num)
{
ind++;
if(num & 1)
count+=mul;
num>>=1;
if(ind>=12)
mul=mul*2;
}
printf("%d\n",count);
}
}