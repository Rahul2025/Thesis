/*Lucky Driving*/

#include<stdio.h>
#include<string.h>

char S[10005];

int main()
{
	int count[10],used[10];
	int a,answer,b,c,d,i,j,length,sum,T;
	long long comb;
	gets(S);
	T=0;
	for(i=0;S[i]!='\0';i++)
		T=(T<<3)+(T<<1)+(S[i]-'0');
	while(T--)
	{
		gets(S);
		length=strlen(S);
		for(i=0;i<10;i++)
			count[i]=0;
		for(i=0;i<length;i++)
			count[S[i]-'0']++;
		answer=0;
		for(a=0;a<11;a++)
		{
			for(b=a;b<11;b++)
			{
				for(c=b;c<11;c++)
				{
					for(d=c;d<11;d++)
					{
						//if a or b or c or d is 10, then it is not used
						sum=0;
						for(i=0;i<10;i++)
							used[i]=0;
						if(a<10)
						{
							sum+=a;
							used[a]++;
						}
						if(b<10)
						{
							sum+=b;
							used[b]++;
						}
						if(c<10)
						{
							sum+=c;
							used[c]++;
						}
						if(d<10)
						{
							sum+=d;
							used[d]++;
						}
						if((sum==0) || (sum%9))
							continue;
						comb=1;
						for(i=0;i<10;i++)
							for(j=0;j<used[i];j++)
								comb=comb*(count[i]-j)/(j+1);
						answer=(answer+(comb%1000000007))%1000000007;
					}
				}
			}
		}
		printf("%d\n",answer);
	}
	return 0;
}