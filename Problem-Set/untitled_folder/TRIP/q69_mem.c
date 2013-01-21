#include<stdio.h>
#include<stdlib.h>
#define MOD 1000000007

int arr[1000000];
int temp1[1000000];
int temp2[1000000];

int main()
{
	int m,n,i,j,min,k;
	long long count=0;

	scanf("%d%d",&n,&m);
	for(i=0;i<n;i++)
		scanf("%d",arr+i);

	temp2[0]=1;
	j=k=count=0;
	for(i=1;i<n;i++)
	{
		while(arr[i]-arr[j] > m)
			count-=temp2[j++];
		temp1[i]=temp1[j]+1;
		while(temp1[k]==temp1[j])
			count+=temp2[k++];
		temp2[i]=count%MOD;
	}
	printf("%d %d\n",temp1[n-1]-1,temp2[n-1]);
	return 0;
}