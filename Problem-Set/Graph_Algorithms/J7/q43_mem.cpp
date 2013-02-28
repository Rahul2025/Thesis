#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<iostream.h>
int main()
{
	int cases;
	float a,b,m,n,r,s,mul1,mul2;
	scanf("%d",&cases);
	
	while(cases--) 
	{
		scanf("%f %f",&a,&b);
		m= (a+ sqrt(a*a - 24*b)) / 12.0;
		n= (a- sqrt(a*a - 24*b)) / 12.0;
		r= a/4 - 2*m;
		s= a/4 - 2*n;
		mul1= m*m*r;
		mul2= n*n*s;

		if(mul1 > mul2)
			printf("%0.2f\n",mul1);
		else
			printf("%0.2f\n",mul2);

	}
	return 0;
} 