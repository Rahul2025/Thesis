#include<iostream>
int main()
{
	int t,a[1000],num[1000],n,f,c,v,i;
	std::cin>>t;
	while(t--)
	{
		i=0;
		std::cin>>n;
		for(int k=0;k<n;k++)
		{
			f=0;
			num[k]=0;
			std::cin>>a[i];
			for(int j=0;j<i;j++)
			{
				if(a[i]==a[j])
				{
					f=1;
					num[j]++;
					break;
				}
			}
			if(f!=1)
			num[i++]++;
		}
		c=0;
		v=10001;
		for(int j=0;j<i;j++)
		{
			if( (c<num[j]) || (c==num[j] && v>a[j]) )
			{
				v=a[j];
				c=num[j];
			}
		}
		std::cout<<v<<" "<<c<<"\n";
	}
}