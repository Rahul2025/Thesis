#include <cstdio>

typedef long long LL;

int main()
{
	int t, n, m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&m);
		LL a = 1, b = 1;
		while(--n)
		{
			a = (a+b)%m;
			b = (a+b)%m;
		}
		printf("%lld/%lld\n",a%m,b%m);
	}
	
	return 0;
}