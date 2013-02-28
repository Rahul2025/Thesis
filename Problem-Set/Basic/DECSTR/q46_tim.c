#include<stdio.h>
int main()
{
int t,n,i,temp,m;
	scanf("%d",&t);
	while(t--)
	{	
		temp='a';
		scanf("%d",&n);
		m=n+(n-1)/25;
		for(i=0;i<=m;i++)
		printf("%c",temp+(m-i)%26);
		printf("\n");
	}
	return(0);
}