#include<stdio.h>

int main()
{
	int test;
	int n;
	scanf("%d",&test);
	fflush(stdin);
	while(test--)
	{
	scanf("%d",&n);
	fflush(stdin);
	if(n%4==1)
	printf("ALICE\n");
	else
	printf("BOB\n");
		
	}
	return 0;	
	}