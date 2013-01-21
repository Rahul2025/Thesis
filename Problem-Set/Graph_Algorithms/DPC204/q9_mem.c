#include <stdio.h>
int main()	
{
	long long int a,b,c,n1=1,n2=1,count=0;
while(n1!=0&&n2!=0)
{	
	scanf("%ld %ld",&n1,&n2);
	a=1;
	b=2;
	while(1)
	{
		c=a+b;
		a=b;
		b=c;
		if(c>n1)
		{
			if(c<n2)
		//		printf("%lld\n",c);
				count++;		
			else
			{
				goto outer;
			}
		}
	}
outer:if(n1!=0||n2!=0)
	{
		printf("%ld\n",count);
	}
	count=0;
	
}
return 0;
}	