#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
 
#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)
 
using namespace std;
 
char inp[10000000];
char *ptr;
int a[10000][2];
 
inline int SCAN_INT(void)
{
while(!(*ptr<='9' && *ptr>='0'))
ptr++;
int ret=0;
while(*ptr<='9' && *ptr>='0')
ret=ret*10+(*(ptr++))-'0';
return ret;
}
 
double dist(int x1,int y1,int x2,int y2)
{
double a,b;
a=x2-x1;
a=a*a;
b=y2-y1;
b=b*b;
return sqrt(double(a+b));
}
 
 
int main()
{
//freopen("input.txt","r", stdin);
fread(inp, sizeof(char), 10000000, stdin);
ptr = inp;
int t,n,x,y;
t=SCAN_INT();
while(t--){
for(int i=0;i<10000;i++){
a[i][0]=100000;
a[i][1]=-1;
}
n=SCAN_INT();
for(int i=0;i<n;i++){
x=SCAN_INT();
y=SCAN_INT();
a[x][0]=min(a[x][0],y);
//cout<<a[x][0]<<endl;
a[x][1]=max(a[x][1],y);
//cout<<a[x][1]<<endl;
}
double d=0;
int px=-1,py=-1;
for(int i=0;i<10000;i++){
if(a[i][1]==-1)
continue;
if(px!=-1)
d+=dist(px,py,i,a[i][1]);
d+=a[i][1]-a[i][0];
px=i;
py=a[i][0];
}
printf("%.2f\n",d);
}
}