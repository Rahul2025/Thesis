#include<cstdio>
#include<algorithm>
using namespace std;

int main()
{
    long int a[2000+20];
	int n,first,last,mid ;
	long long ans=0;
	
	scanf("%d",&n);
	while(n!=0)
	{
	    ans=0;
	    for(int i=1;i<=n;i++)
		    scanf("%d",&a[i]);
		sort(a+1,a+n+1);
		for(int i=1;i<=n-2;i++)
		{
		    for(int j=i+1;j<=n-1;j++)
			{
			  first=i+1;
			  last=n;
			  mid=(first+last)/2;
			    while(1)
				{
				    if(a[i]+a[j]<a[mid]) last=mid; 
                    else first=mid;
					if(last-first<=1)
					{
					    if(a[last]>a[i]+a[j]) ans+=n-last+1;
						break;
					}
					mid=(first+last)/2;
				}
			}
		}
		printf("%lld\n",ans);
	    scanf("%d",&n);
	}
	
	return 0;
}