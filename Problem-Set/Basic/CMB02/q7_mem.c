#include<stdio.h>
int palindrome(int num)
{
int digit,rev=0;
while(num)
{
digit=num%10;
rev=rev*10+digit;
num=num/10;
}
return rev;
}
int main()
{
int t,k,i,j;
scanf("%d",&t);
for(j=0;j<t;j++)
{
scanf("%d",&k);
for(i=k+1;;i++)
{
if(i==palindrome(i))
break;
}
printf("%d\n",i);
}
return 0;
} 