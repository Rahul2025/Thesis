#include<iostream>
#include<stdio.h>

//unsigned long long gcd ( unsigned long long a, unsigned long long b )
int gcd ( int a, int b )
{
	//printf ( "%llu %llu\n",a,b );
	if (a<b)
	{
		b = a+b -(a=b);
	}
	//printf ( "%llu %llu\n",a,b );
	int temp;
	while ( b!=0 )
	{
		temp = a;
		a = b;
		b = temp%a;
	}
	return a;
}

int main ( void ) {
	int testCases, num_sel, num_mar, count, gcd_store;
	long long int answer;
	scanf ( "%d",&testCases );
	while ( testCases-- )
	{
		count = answer = 1;
		scanf ( "%d%d", &num_sel, &num_mar);
		//printf ( "%llu\n", gcd(num_sel, num_mar) );
		if ( num_mar > (num_sel-num_mar) )
		{
			num_mar = num_sel-num_mar;
		}
		else
		{
			--num_mar;
		}
		--num_sel;
		//--num_mar;
		while ( count <= num_mar )
		{
			//printf ("answer\t");
			//gcd_store = gcd( answer, count );
			//printf ("%d\t", gcd_store);
			//answer /= gcd_store;
			//answer = (answer*num_sel--)/count++;
			answer *= num_sel--;
			//printf ("%d\t", answer);
			answer /= count++;
			//answer /= (count++/gcd_store);
			//printf ("%d\n", answer);
		}
		//printf ("%d\n",sizeof(unsigned long long));
		printf ("%lld\n",answer);
		//printf ("%d\n",answer);
	}
	return 0;
}