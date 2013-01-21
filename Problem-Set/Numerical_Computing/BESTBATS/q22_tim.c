#include<stdio.h>
#include<stdlib.h>
int factorial(int n);
int main()
{
	int t,i,k,j,countlow,temp,clselect,p;
	int score[11];
	scanf("%d",&t);
	while(t--)
	{
		for(i=0;i<11;i++)
		{
			scanf("%d",&score[i]);
		}
		
		//sorting the scores using insertion sort in increasing order
		for ( i = 1 ; i < 11 ; i++ )
		{
			for ( j = 0 ; j < i ; j++ )
			{
				if ( score[j] > score[i] )
				{
					temp = score[j] ;
					score[j] = score[i] ;

					for ( p = i ; p > j ; p-- )
						score[p] = score[p - 1] ;

					score[p + 1] = temp ;
				}
			}
		}
		scanf("%d",&k);
		countlow=1;
		for(i=12-k;i<11;i++)
		{
			if(score[i]==score[11-k])
			{
				countlow++;
			}
			/*else
			{
				break;
			}*/
		}
		clselect=countlow;
		for(i=10-k;i>=0;i--)
		{
			if(score[i]==score[11-k])
			{
				countlow++;
			}
		}
		printf("%d\n",(factorial(countlow))/(factorial(clselect)*factorial(countlow-clselect)));
	}
	return 0;
}

int factorial(int n)
{
	if(n==0)
		return 1;
	else
		return (n*factorial(n-1));
}