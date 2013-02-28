#include<stdio.h>

int a[2000];

int nc(int n)
{
int sum=0,i,j,key,low,high,start,mid;

for(i=0;i<n-2;i++)
{
start=i+2;
for(j=i+1;j<n-1;j++)
{
	
	key=a[i]+a[j];

	low=start;
	high=n-1;
	
	while(high-low>1)
	{
	mid=(low+high)/2;
	if(a[mid]>key)
	high=mid;
	else
	low=mid;
	}
	
	if(a[low]>key)
	start=low;
	else if(a[high]>key)
	start=high;
	else start=n;
	/*k=j+1;
	if(a[i]+a[j]>a[n-1])
	continue;
	while(k<n && a[i]+a[j]>=a[k])
	k++;
if(k<n)
sum+=n-k;
*/
	sum+=n-start;
}
}
return sum;
}

int main()
{

int n,i,key,j;

while(scanf("%d",&n) && n>0)
{
	for(i=0;i<n;i++)
	{
	scanf("%d",&key);
	for(j=i-1;j>=0 && a[j]>key;j--)
	a[j+1]=a[j];

	a[j+1]=key;
	}
printf("%d\n",nc(n));
}
return 0;
}