#include <stdio.h>
int main(void)
{
	int i,j,t,k,l,n,flag;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d",&k);
		l=1;
		flag = 1;
		for(j=0;j<k;j++)
		{
			scanf("%d",&n);
			if(n<=l)
			{
				l -= n;
				l <<= 1; 
			}
			else
			{
				printf("No\n");
				flag = 0;
				break;
			}
		}
		if(flag)
		{
			if(!l)
				printf("Yes\n");
			else
				printf("No\n");	
		}
	}
	return 0;
}
