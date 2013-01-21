#include <stdio.h>
#include <math.h>
#define E 1e-7
 
int main()
{
int n, i, j, k;
long long x[2100], y[2100], z[2][3];
double t, d, m, h=1234267893, g=1987684321, p[5];
 
for(;;printf("%0.6lf\n",m))
	{
	if(!scanf("%d",&n)||!n)
		break;
	for(i=-1; ++i<n; scanf("%lld%lld",&x[i],&y[i]));
	for(;;h=p[2],g=p[3])
		{
		for(i=-!(p[0]=p[1]=t=0); ++i<n; p[4]=(sqrt((x[i]-h)*(x[i]-h)+(y[i]-g)*(y[i]-g))),p[0]+=x[i]*1.0/p[4],p[1]+=y[i]*1.0/p[4],t+=1.0/p[4]);
		p[2]=p[0]/t;
		p[3]=p[1]/t;
		if(fabs(p[2]-h)<E&&fabs(p[3]-g)<E)
			break;
		}
	for(z[1][2]=(z[1][1]=(z[1][(z[0][2]=(z[0][1]=(z[0][(int)(d=m=i=0)]=p[2]=h)+1)-2)*0]=p[3]=g)+1)-2; i<3; i++)
		for(j=-1; ++j<3; m=((!i&&!j)||(d<m))?d:m)
			for(k=-!(d=0); ++k<n; d+=sqrt(((x[k]-z[0][i])*(x[k]-z[0][i])+(y[k]-z[1][j])*(y[k]-z[1][j]))));
	}
 
return 0;
}