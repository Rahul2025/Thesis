#include<stdio.h>
main()
{	int t,k,n,i;
	long long int a;
	scanf("%d",&t);
	while(t--)
	{	scanf("%d %d",&n,&k);
		a=1ll;n--;k--;
		if(k>n/2) k=n-k;
		for(i=1;i<=k;i++)
		{	a=a*(n-i+1)/i;
			
		}
		printf("%lld\n",a);
	}
	return 0;
}