#include<stdio.h>
int main()
{
long int a,b,c,i,j,rem,d,temp,t;
char s[255];
scanf("%li",&t);
for(i=1;i<=t;i++)
{
scanf("%li %s",&a,s);
if(a==0)
{
printf("%s\n",s);
}
else
{
rem=0;
for(j=0;s[j]!='\0';j++)
{
d=s[j]-48;
c=10*rem+d;
rem=c%a;
}
b=rem;
if(b==0)
{
printf("%li\n",a);
}
else
{
while(a%b!=0)
{
temp=b;
b=a%b;
a=temp;
}
printf("%li\n",b);
}
}
}
return 0;
}





