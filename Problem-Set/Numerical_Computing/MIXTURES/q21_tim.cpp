/* mixtures.cpp */
#include<cstdio>
#define SIZE 100
int m[SIZE][SIZE],c[SIZE][SIZE];
int q[SIZE];

int main()
{
int n;

while(scanf("%d",&n)!=EOF)
	{
	int i,j,k,l,q1;
	for(i=0;i<n;i++) scanf("%d",&q[i]);
	for(i=0;i<n;i++) c[i][i]=q[i],m[i][i]=0;
	for(l=2;l<=n;l++)
		{
		for(i=0;i<=n-l;i++)
			{
			j=i+l-1;
			//printf("%d %d\n",i,j);
			m[i][j]=9999999;
			for(k=i;k<j;k++)
				{
				//printf("k %d\n",k);
				q1 = m[i][k] + m[k+1][j] + c[i][k] * c[k+1][j];
				if(q1<m[i][j]){m[i][j]=q1; c[i][j]=(c[i][k]+c[k+1][j])%100;}
				}
			}
		}
	printf("%d\n",m[0][n-1]);	
	}
return 0;
}