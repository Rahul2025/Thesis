#include<stdio.h>
int main()
{
	int n,*a,cnt=0,i,j;
	scanf("%d",&n);
	a=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

	for(i=0;i<n-1;i++)
	{
		for(j=i;j>=0;j--)
		{
			if(a[j]>a[i+1])
				cnt++;
			else if(cnt==0)
					break;
		}
	}
	printf("%d\n",cnt);
	return 0;
 
} 