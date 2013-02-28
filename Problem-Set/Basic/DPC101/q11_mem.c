#include<stdio.h>
int main()
{
	int a,b,num1,num2,sum;
	while(1)
	{
		int carcnt=0,cf=0;
		scanf("%d%d",&a,&b);
		if(a==0&&b==0)
   			break;
		while(a!=0||b!=0)
		{
			num1=a%10;	num2=b%10;	sum=cf+num1+num2;
			if(sum>=10)
			{
				carcnt++;
				cf=1;
			}
			else
				cf=0;
			a/=10;
			b/=10;
		}
		if(carcnt==0)
		printf("No carry operation.\n");
		else if(carcnt==1)
		printf("1 carry operation.\n");
		else
		printf("%d carry operations.\n",carcnt);
	}
	return 0;
}