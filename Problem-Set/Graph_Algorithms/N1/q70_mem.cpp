#include <cstdio>
#include <cstring>
#include <algorithm>
 
using namespace std;
 
const int MAXNODE = 13;
char map[MAXNODE+2][MAXNODE+3];
int dist[MAXNODE+2][MAXNODE+2];
int pi[MAXNODE+2];
int pj[MAXNODE+2];
int qi[(MAXNODE+2) * (MAXNODE+2)];
int qj[(MAXNODE+2) * (MAXNODE+2)];
int ql[(MAXNODE+2) * (MAXNODE+2)];
int dp[1<<MAXNODE][MAXNODE+1];
bool done[MAXNODE+2][MAXNODE+2];
int T, N;
 
inline void push(int i, int j, int l, int &cnt)
{
qi[cnt] = i;
qj[cnt] = j;
ql[cnt++] = l;
done[i][j] = true;
}
 
int cal_dist(int s, int d)
{
int i, j, x, y, l, head, cnt;
for (i=0; i<MAXNODE+2; i++)
for(j=0; j<MAXNODE+2; j++)
done[i][j] = false;
i = pi[s], j = pj[s];
x = pi[d], y = pj[d];
head = l = 0;
cnt = 1;
done[i][j] = true;
qi[head] = i, qj[head] = j, ql[head]= l;
while(head<cnt && (qi[head]!=x||qj[head]!=y))
{
i = qi[head];
j = qj[head];
l = ql[head];
if(i-1>=0 && map[i-1][j] != '#' && !done[i-1][j])
push(i-1, j, l+1, cnt);
if(i+1<N && map[i+1][j] != '#' && !done[i+1][j])
push(i+1, j, l+1, cnt);
if(j-1>=0 && map[i][j-1] != '#' && !done[i][j-1])
push(i, j-1, l+1, cnt);
if(j+1<N && map[i][j+1] != '#' && !done[i][j+1])
push(i, j+1, l+1, cnt);
head +=1;
}
return (qi[head] == x && qj[head] == y)? ql[head] : -1;
}
 
int main()
{
int tr, opt, d;
scanf("%d", &T);
for(; T>0; T--)
{
scanf("%d", &N);
for(int i=0; i<N; i++)
scanf("%s", map[i]);
 
tr = 0;
pi[tr] = 0;
pj[tr++] = 0;
for(int i=0; i<N; i++)
for(int j=0; j<N; j++)
{
if (map[i][j] == '*')
{
pi[tr] = i;
pj[tr++] = j;
}
}
pi[tr] = pj[tr] = N - 1;
for(int i=0; i<=tr; i++)
{
dist[i][i] = 10000;
for(int j=i+1; j<=tr; j++)
{
if ((d=cal_dist(i, j)) < 0)
{
printf("-1\n");
goto next;
}
dist[i][j] = dist[j][i] = d;
}
}
tr -= 1;
memset(dp, 0x01, sizeof(dp));
for(int i=0; i<tr; i++)
dp[1<<i][i+1] = dist[0][i+1];
 
for(int i=1; i<(1<<tr); i++)
for(int j=0; j<tr; j++)
if ((1<<j)&i)
for(int k=0; k<tr; k++)
if(((1<<k)&i)==0)
dp[(1<<k)|i][k+1] = min(dp[(1<<k)|i][k+1],
dp[i][j+1] + dist[j+1][k+1]);
opt = 10000;
for(int i=1; i<=tr; i++)
opt = min(opt, dp[(1<<tr)-1][i] + dist[i][tr+1]);
printf("%d\n", opt);
next:;
}
return 0;
} 