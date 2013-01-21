#include<stdio.h>
#define mod 1000000007
/*unsigned long long int scan()
{unsigned long long int acc = 0;
register char buf;
buf = getchar_unlocked();
while(buf!=10&&buf<='9'&&buf>='0')
{     acc = acc * 10 + buf - '0';
buf = getchar_unlocked();
}
  acc=sign*acc;
 return(acc);
}
*/




int main()
{unsigned long long int a[2][2],b,t[2][2],ans[2][2],c[2][2];
int i,j,k,test;
int x,y,z,zz;
scanf("%d",&test);
while(test)
{test--;
for(i=0;i<2;i++)
for(j=0;j<2;j++)
a[i][j]=t[i][j]=ans[i][j]=1;
t[1][1]=a[1][1]=0;
ans[1][0]=ans[0][1]=0;
scanf("%llu",&b);

b*=2;
while(b>0)
{
    if(b%2)
 {
 x = (ans[0][0] * t[0][0] + ans[0][1] * t[1][0]) % mod;
 y = (ans[0][0] * t[0][1] + ans[0][1] * t[1][1]) % mod;
 z = (ans[1][0] * t[0][0] + ans[1][1] * t[1][0]) % mod;
 zz = (ans[1][0] * t[0][1] + ans[1][1] * t[1][1]) % mod;
 ans[0][0]=x;ans[0][1]=y;ans[1][0]=z;ans[1][1]=zz;

 }
 x = (t[0][0] * t[0][0] + t[0][1] * t[1][0]) % mod;
 y = (t[0][0] * t[0][1] + t[0][1] * t[1][1]) % mod;
 z = (t[1][0] * t[0][0] + t[1][1] * t[1][0]) % mod;
 zz = (t[1][0] * t[0][1] + t[1][1] * t[1][1]) % mod;
 t[0][0]=x;t[0][1]=y;t[1][0]=z;t[1][1]=zz;



b=b/2;
}
printf("%llu\n",(((ans[0][0]%mod)*(ans[0][1]%mod))%1000000007));
}
 return(0);

}