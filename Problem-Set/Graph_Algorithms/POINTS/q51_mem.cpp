#include <stdio.h>
#include <math.h>

#define max(a,b) (a > b? a : b)
#define min(a,b) (a < b? a : b)

double dist(int x, int y, int a, int b)
{
	int ret;
	ret=(x-a)*(x-a)+(y-b)*(y-b);
	double p=sqrt(ret);
	return p;
}

int main(void)
{
	int t;
	scanf("%d",&t);
	double d=0.0;
	for(int i=0;i<t;i++)
	{
		d=0.0;
		int a[10001][2];
		int n;
		scanf("%d",&n);
		for(int j=0;j<10001;j++)
		{
			a[j][0]=10001;
			a[j][1]=-1;	
		}
		int x,y;
		for(int j=0;j<n;j++)
		{
			scanf("%d%d",&x,&y);
			a[x][0]=min(a[x][0],y);
			a[x][1]=max(a[x][1],y);
			//printf("%d,%d,%d\n",x,a[x][0],a[x][1]);
		}
		//printf("input done\n");
		int px=-1,py=-1;
		for(int j=0;j<10001;j++)
		{
			if(a[j][1]==-1)
				continue;
		
			if(px!=-1)
			{
				d+=dist(j,a[j][1],px,py);
//				printf("%.2finsside\n",d);
			}
			d+=a[j][1]-a[j][0];
	//		printf("%d%d\n",a[j][0],a[j][1]);
			px=j;
			py=a[j][0];
		//	printf("%.2f\n",d);
		}
		printf("%.2f \n",d);
	}
	return 0;
}