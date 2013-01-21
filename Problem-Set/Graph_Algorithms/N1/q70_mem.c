#define MIN(x,y) (((x)<(y))?(x):(y))
#include<assert.h>
char maze[15][15];
int n;
int dp[1<<13][15];
int c;
int loc[15][2],vis[15][15],dis[15][15][15][15];
int queue[1000][2];
int moves[][2]={{0,1},{0,-1},{1,0},{-1,0}};
int front,rear;
const int INF = 1<<25;
void init(){
    front = rear = -1;
}
void push(int eleX,int eleY){
    if(front==-1){
        front = rear = 0;
        queue[rear][0] = eleX;
        queue[rear][1] = eleY;
    }
    else{
        ++rear;
        queue[rear][0] = eleX;
        queue[rear][1] = eleY;
    }
}
void pop(){
    front++;
}
int isEmpty(){
    return front>rear || (front == -1 && rear == -1);
}
int validBfs(int X,int Y){
    return X>=0  && X<n && Y>=0  && Y<n && maze[X][Y]!='#' && !vis[X][Y];
}
int main(){
    int T,i,j,k;
    scanf("%d",&T);
    while(T--){
        c = 0;
        scanf("%d",&n);
        if(n == 1){
            puts("0");
            continue;
        }
        for(i=0;i<n;i++){
            scanf("%s",maze[i]);
            for(j=0;j<n;j++){
                if(maze[i][j] == '*'){
                    loc[c][0]=i;loc[c][1]=j;
                    ++c;
                }
            }
        }
        for(i=0;i<=0;i++){
            init();
            int x = 0;
            int y = 0;
            for(j=0;j<n;j++){
                for(k=0;k<n;k++){
                    vis[j][k]=0;
                    dis[x][y][j][k]=INF;
                }
            }
            dis[x][y][x][y]=0;
            push(x,y);vis[x][y]=1;
            int sx,sy,tx,ty;
            ///BFS
            while(!isEmpty()){
                sx = queue[front][0];sy = queue[front][1];
                pop();
                for(j=0;j<4;j++){
                    tx = sx+moves[j][0];
                    ty = sy+moves[j][1];
                    if(validBfs(tx,ty)){
                        vis[tx][ty]=1;
                        dis[x][y][tx][ty]=dis[x][y][sx][sy]+1;
                        push(tx,ty);
                    }
                }
            }
        }
        for(i=0;i<c;i++){
            init();
            int x = loc[i][0];
            int y = loc[i][1];
            assert(x>=0 && x<n && y>=0 && y<n);
            for(j=0;j<n;j++){
                for(k=0;k<n;k++){
                    vis[j][k]=0;
                    dis[x][y][j][k]=INF;
                }
            }
            dis[x][y][x][y]=0;
            push(x,y);vis[x][y]=1;
            int sx,sy,tx,ty;
            ///BFS
            while(!isEmpty()){
                sx = queue[front][0];sy = queue[front][1];
                pop();
                for(j=0;j<4;j++){
                    tx = sx+moves[j][0];
                    ty = sy+moves[j][1];
                    if(validBfs(tx,ty)){
                        vis[tx][ty]=1;
                        dis[x][y][tx][ty]=dis[x][y][sx][sy]+1;
                        push(tx,ty);
                    }
                }
            }
        }
        int t1,t2;
        for(i=1;i<(1<<c);i++){
            for(j=0;j<c;j++){
                dp[i][j]=INF;
                if(i&(1<<j)){
                    t1=i^(1<<j);
                    if(t1==0){
                        dp[i][j] = dis[0][0][loc[j][0]][loc[j][1]];
                        break;
                    }
                    for(k=0;k<c;k++){
                        if(t1&(1<<k)){
                            dp[i][j]=MIN(dp[i][j],dp[t1][k]+dis[loc[k][0]][loc[k][1]][loc[j][0]][loc[j][1]]);
                        }
                    }
                }
            }
        }
        int mask=(1<<c)-1;
        int ans = INF;
        for(i=0;i<c;i++){
            ans=MIN(ans,dp[mask][i]+dis[loc[i][0]][loc[i][1]][n-1][n-1]);
        }
        if(ans>=INF) puts("-1");
        else printf("%d\n",ans);
    }
    return 0;
}