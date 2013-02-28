#include <iostream>
#include<stdio.h>

using namespace std;

int main()
{
	int a;
	int b;
	int n1;
	int n2;
	int carries;

	while (scanf("%d %d", &a, &b) && !((a == 0) && (b == 0)))
	{
		n1 = a;
		n2 = b;
		carries = 0;

		while (!((n1 == 0) && (n2 == 0)))
		{
			if (((n1 % 10) + (n2 % 10)) >= 10)
			{
				carries++;
				n1 += 10;
			}

			n1 /= 10;
			n2 /= 10;
		}

		if (carries == 0)
		{
			printf("No carry operation.\n");
		}
		else if (carries == 1)
		{
			printf("1 carry operation.\n");
		}
		else
		{
			printf("%d carry operations.\n", carries);
		}
	}
}