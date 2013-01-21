#include<stdio.h>

main()
{	int i,j,t;
	long long n,m,a,b,c,temp;
	scanf("%d",&t);
	while(t--)
	{	scanf("%lld %lld",&n,&m);
		
	for(i=1,a=0,b=1;i<=(2*n-1);i++)
	{	c=(a+b)%m;
		temp=b;
		a=b;
		b=c;
	}
	printf("%lld/%lld\n",(temp%m),c%m);
	}
	return 0;	
}
