#include <stdio.h>

#define siz 1000
#define MOD 1000000080798150871
#define LL long long
void S(int a, int *b){if(a)(*b)++;}

int main()
{
int fall, N, M, L, K, i=0, j, k, ar[siz][3], c[3];
LL sol=0, C[siz+1][siz+1];
char st[10];

for(c[0]=c[1]=c[2]=i; i<=siz; i++)
	for(j=0; j++<=i; C[i][j-1]=(!(j-1)||(j-1)==i)?1:(C[i-1][j-2]+C[i-1][j-1]),C[i][j-1]-=(C[i][j-1]>=MOD)?MOD:0);
for(scanf("%d",&fall); fall--; printf("%llu\n",sol))
	{
	for(i=sol=c[0]=c[1]=c[2]=!scanf("%d %d %d %d",&N,&M,&L,&K); i<N; i++)
		for(j=0; j<3; ar[i][j++]=0);
	for(i=0; i<N; i++)
		for(j=!scanf("%s",st); j++<M; ar[i][j-1]=st[j-1]-48);
	if(K==1)
		{
		for(i=-1; ++i<N; S(ar[i][0],&c[0]),S(ar[i][1],&c[1]),S(ar[i][2],&c[2]));
		sol=(C[c[0]][L]+C[c[1]][L]+C[c[2]][L])%MOD;
		}
	if(K==3)
		{
		for(i=-1; ++i<N; S(ar[i][0]&&ar[i][1]&&ar[i][2],&c[0]));
		sol=C[c[0]][L];
		}
	if(K==2)
		{
		for(i=-1; ++i<N; S(ar[i][0]&&ar[i][1],&c[0]),S(ar[i][0]&&ar[i][2],&c[1]),S(ar[i][1]&&ar[i][2],&c[2]));
		sol=(C[c[0]][L]+C[c[1]][L]+C[c[2]][L])%MOD;
		}
	}

return 0;
}