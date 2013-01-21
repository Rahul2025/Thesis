#include <cstdio>

main()
{
	int t;
	
	for(scanf("%d",&t);t;t--)
	{
		int n,c,count,temp;
		scanf("%d%d",&n,&c);
		count=0;
		for(n;n;n--)
		{
			scanf("%d",&temp);	
			count+=temp;
		}
		(count<=c)?printf("Yes\n"):printf("No\n");
	}
	return 0;
} 