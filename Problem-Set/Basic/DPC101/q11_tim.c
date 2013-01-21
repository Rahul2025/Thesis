//CARRY

#include <stdio.h>

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	while (!(a==0 && b==0))
	{
		int ta, tb;
		ta=a; tb=b;
		int lta, ltb;
		int carry=0;
		int cntr=0;
		while (ta!=0 || tb!=0)
		{
			
			lta=ta%10; ltb=tb%10;
			ta=ta/10; tb=tb/10;
			int tr = lta+ltb+carry;
			if (tr>=10) 
			{
				cntr++;
				carry=1;
			}
			else carry=0;
		}
		if (cntr==0) printf("No carry operation.\n");
		else if (cntr==1) printf("1 carry operation.\n");
		else printf("%d carry operations.\n", cntr);
		scanf("%d %d", &a, &b);
	}
	return 0;
}