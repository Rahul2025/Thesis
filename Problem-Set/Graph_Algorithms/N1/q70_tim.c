#
#include<stdio.h>
#
#define MIN(A,B) (A)<(B)?(A):(B)
#
 
#
int board[20][20];
#
int dist[20][20];
#
int status[20][20];
#
int count[14][1<<14];
#
 
#
struct cell
#
{
#
int x,y,distance;
#
};
#
#
struct cell queue[200];
#
int front,rear;
#
 
#
void clearboard(int size)
#
{
#
int i,j;
#
for(i=0;i<size;i++)
#
{
#
for(j=0;j<size;j++)
#
{
#
status[i][j] = 0;
#
}
#
}
#
}
#
 
#
void bfs(int i,int j,int size)
#
{
#
front = 0;
#
rear = 0;
#
queue[rear].x = i;
#
queue[rear].y = j;
#
queue[rear++].distance = 0;
#
status[i][j] = 1;
#
#
while(front!=rear)
#
{
#
struct cell c1 = queue[front++];
#
int x = c1.x;
#
int y = c1.y;
#
if(x>0)
#
{
#
if(status[x-1][y]==0)
#
{
#
status[x-1][y]=1;
#
if(board[x-1][y]>=0)
#
{
#
dist[board[i][j]][board[x-1][y]] = c1.distance+1;
#
}
#
if(board[x-1][y]!=-2)
#
{
#
queue[rear].x = x-1;
#
queue[rear].y = y;
#
queue[rear++].distance = c1.distance+1;
#
}
#
}
#
}
#
if(y>0)
#
{
#
if(status[x][y-1]==0)
#
{
#
status[x][y-1]=1;
#
if(board[x][y-1]>=0)
#
{
#
dist[board[i][j]][board[x][y-1]] = c1.distance+1;
#
}
#
#
if(board[x][y-1]!=-2)
#
{
#
queue[rear].x = x;
#
queue[rear].y = y-1;
#
queue[rear++].distance = c1.distance+1;
#
}
#
}
#
}
#
if(x<size-1)
#
{
#
if(status[x+1][y]==0)
#
{
#
status[x+1][y]=1;
#
if(board[x+1][y]>=0)
#
{
#
dist[board[i][j]][board[x+1][y]] = c1.distance+1;
#
}
#
#
if(board[x+1][y]!=-2)
#
{
#
queue[rear].x = x+1;
#
queue[rear].y = y;
#
queue[rear++].distance = c1.distance+1;
#
}
#
}
#
}
#
if(y<size-1)
#
{
#
if(status[x][y+1]==0)
#
{
#
status[x][y+1]=1;
#
if(board[x][y+1]>=0)
#
{
#
dist[board[i][j]][board[x][y+1]] = c1.distance+1;
#
}
#
if(board[x][y+1]!=-2)
#
{
#
queue[rear].x = x;
#
queue[rear].y = y+1;
#
queue[rear++].distance = c1.distance+1;
#
}
#
}
#
}
#
}
#
#
}
#
 
#
#
int main()
#
{
#
int testCases;
#
int size,i,j,k,notr;
#
char str[14];
#
scanf("%d",&testCases);
#
{
#
while(testCases--)
#
{
#
scanf("%d",&size);
#
if(size==1)
#
{
#
scanf("%s",str);
#
printf("0\n");
#
continue;
#
}
#
k = 0;
#
for(i=0;i<size;i++)
#
{
#
scanf("%s",str);
#
for(j=0;j<size;j++)
#
{
#
if(str[j]=='.')
#
{
#
board[i][j] = -1;
#
}
#
else if(str[j]=='*')
#
{
#
board[i][j] = k++;
#
}
#
else if(str[j]=='#')
#
{
#
board[i][j] = -2;
#
}
#
}
#
}
#
#
board[0][0] = k + 1;
#
board[size-1][size-1] = k;
#
notr = k;
#
#
for(i=1;i<=k+1;i++)
#
{
#
dist[0][i] = 0;
#
}
#
#
for(i=0;i<size;i++)
#
{
#
for(j=0;j<size;j++)
#
{
#
if(board[i][j]>=0)
#
{
#
clearboard(size);
#
bfs(i,j,size);
#
}
#
}
#
}
#
#
int flag = 0;
#
for(i=1;i<=k+1;i++)
#
{
#
if(dist[0][i]==0)
#
{
#
printf("-1\n");
#
flag = 1;
#
break;
#
}
#
}
#
if(flag==1)
#
{
#
continue;
#
}
#
for(i=1; i < (1<<notr);i++)
#
{
#
//printf("%d-- ",i);
#
for(j=notr-1;j>=0;j--)
#
{
#
if((i & (1 << j))>0)
#
{
#
int t1 = i ^ (1 << j);
#
//printf("%d$%d ",j,t1);
#
count[j][t1] = 1000000007;
#
int m,t2=0;
#
for(m=notr-1;m>=0;m--)
#
{
#
if((t1 & (1 << m))>0)
#
{
#
t2 = 1;
#
//printf("%d$%d$%d ",count[j][t1],dist[j][m],count[m][t1^(1<<m)]);
#
count[j][t1] = MIN(count[j][t1],dist[j][m] + count[m][t1^(1<<m)]);
#
}
#
}
#
if(t2==0)
#
{
#
count[j][t1] = dist[j][k];
#
}
#
}
#
}
#
//printf("\n");
#
}
#
#
int min1 = 1000000007;
#
int temp = 0;
#
for(i=0;i<notr;i++)
#
{
#
temp+= 1<<i;
#
}
#
for(i = 0;i < notr;i++)
#
{
#
min1 = MIN(min1,dist[k+1][i] + count[i][temp^(1<<i)]);
#
}
#
printf("%d\n",min1);
#
}
#
}
#
return 0;
#
} 