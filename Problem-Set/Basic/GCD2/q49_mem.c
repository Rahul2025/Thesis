#include <stdio.h>
int gcd(int a,int b)
{
if (b==0)
return a;
else
return gcd(b,a%b);
}
int main()
{	
int t,i,num,rem,a,b;
char array[300];
scanf("%d",&t);
for(;t>0;t--)
{		
scanf("%d",&a);
scanf("%s",array);
rem=0;
if(a==0)
printf("%s\n",array);
else
{for(i=0;array[i]!='\0';i++)
{	
num=rem*10+(array[i]-'0');
rem=num%a;
}
b=rem;
i=gcd(a,b);
printf("%d\n",i);
}
}
return 0;
} 