#include<stdio.h>
int main()
{
int n,k,x,y;
scanf("%d%d",&n,&k);
int a[n*n][n*n];
int i,j;
for(i=1;i<=k;i++)
{
scanf("%d%d",&x,&y);
scanf("%d",&a[x-1][y-1]);
}
for(i=0;i<n*n;i++)
{
for(j=0;j<n*n;j++)
{
if(a[i][j]<=n*n && a[i][j]>0)                  
printf("%d ",a[i][j]);
else
printf("1 ");
}
printf("\n");
}
return(0);
}                                                    