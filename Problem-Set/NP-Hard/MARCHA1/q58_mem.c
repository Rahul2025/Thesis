#include <stdio.h>
#include <math.h>

int PayBinary(int *banknote, int n, int m)
{
	int i, j, sum;
	for(i=0; i<(int)pow(2, (float)n); i++)
	{
		for(j=0, sum=0; j<n; j++)
			if(i&(1<<j))
				sum+=banknote[j];

		if(sum==m)
			return 1;
	}
	return 0;
}

int main(void)
{
	int T;
	int n, m, i;
	int banknote[21];
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d %d", &n, &m);
		for(i=0; i<n; i++)
			scanf("%d", &banknote[i]);
		
		if(PayBinary(banknote, n, m))
			printf("Yes\n");
		else
			printf("No\n");
	}
	
	return 0;
}