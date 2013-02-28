#include<stdio.h>
#include<string.h>
void print_lcs(char b[][1010],char x[],int i,int j)
{
if(i==0 || j==0)
return;
if(b[i][j]=='c')
{
print_lcs(b,x,i-1,j-1);
printf("%c %d %d\n",x[i-1],(i-0),(j-0));
}
else if(b[i][j]=='u')
print_lcs(b,x,i-1,j);
else
print_lcs(b,x,i,j-1);
}
void lcs_length(char x[],char y[],int testcase)
{
int m,n,i,j,c[1010][1010];
char b[1010][1010];
m=strlen(x);
n=strlen(y);
if(n*m>350000){
 printf("case %d N\n",testcase);
 return;
}
for(i=0;i<=m;i++)
c[i][0]=0;
for(i=0;i<=n;i++)
c[0][i]=0;
for(i=1;i<=m;i++)
for(j=1;j<=n;j++)
{
if(x[i-1]==y[j-1])
{
c[i][j]=c[i-1][j-1]+1;
b[i][j]='c';
}
else if(c[i-1][j]>c[i][j-1])
{
c[i][j]=c[i-1][j];
b[i][j]='u';
}
else
{
c[i][j]=c[i][j-1];
b[i][j]='l';
}
}
if(c[m][n]<=1) { printf("case %d N\n",testcase);}
else { printf("case %d Y\n%d\n",testcase,c[m][n]); print_lcs(b,x,m,n); }
}
void lcs(int testcase)
{
int i,j,garb;
char x[1010],y[1010];
scanf("%d",&garb); scanf("%s",x); 
scanf("%d",&garb); scanf("%s",y); 
lcs_length(x,y,testcase);
}
int main()
{
int testcase,arun;
scanf("%d",&testcase);
for(arun=0;arun<testcase;arun++){
lcs((arun+1));
}
return 0;
} 