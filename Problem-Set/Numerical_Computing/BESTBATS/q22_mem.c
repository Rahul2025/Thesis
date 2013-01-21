#include<stdio.h>
long int ncr(int n,int r)
{
	long int prod=1;
	int i,j;
	for(i=n;i>n-r;i--)
		prod*=i;
	for(i=1;i<=r;i++)
		prod/=i;
	return prod;
}
int main()
{
	static int t,a[11],k,i,temp,j,b[11],n;
	scanf("%d",&t);
	while(t>0)
	{
		for(i=0;i<11;i++)
			scanf("%d",&a[i]);
		for(i=0;i<11;i++)
			for(j=i+1;j<11;j++)
			{
				if(a[i]<a[j])
				{
					temp=a[i];
					a[i]=a[j];
					a[j]=temp;
				}
			}
		scanf("%d",&k);
		b[0]=1;
		j=0;
		temp=a[0];
		for(i=1;i<11;i++)
		{
			if(temp==a[i])
				b[j]++;
			else
			{	temp=a[i];
				b[++j]=1;
			}
		}
		n=j+1;
		for(i=0,j=0;i< k;i+=b[j++])
			;
		i-=b[j-1];
		temp=j-1;
		printf("%ld\n",ncr(b[temp],k-i));
		--t;
	}
	return 0;
}