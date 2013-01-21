#include <stdio.h>
#define max(a,b) (((a)>(b))?(a):(b))
 
char board[1000][1000];
int res[1000][1000];
 
int main()
{
    int t, n, r; 
    int i, j;
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d\n",&n);
        for(i=0;i<n;i++) gets(board[i]);
        for(j=n-1;j>=0;j--)
        {
            for(i=0;i<n;i++)
            {
                r=0;
                if(j+1<n && i+2< n)r=max(r,res[i+2][j+1]);
                if(j+1<n && i-2>=0)r=max(r,res[i-2][j+1]);
                if(j+2<n && i+1< n)r=max(r,res[i+1][j+2]);
                if(j+2<n && i-1>=0)r=max(r,res[i-1][j+2]);
                res[i][j]=r+(board[i][j]=='P'?1:0);
                if(board[i][j]=='K')break;
            }
            if(i<n) break ;
        }
        printf("%d\n", res[i][j]);
    }
    return 0;
}
 