#include<iostream>
#include<stdio.h>
#include<algorithm>
typedef long long lint;
using namespace std;
lint f(lint k)
{
	if(k>=0)
		return ((k+1)*(k+2))/2;
	return 0;
}
int main()
{
	lint A,B,C,N,i,j,k,t,ans;
	cin>>t;
	while(t--)
	{
		ans=1;
		cin>>N>>A>>B>>C;
		++A;++B;++C;
		for(i=1;i<=N;++i)
		{
			ans+=f(i)-f(i-A)-f(i-B)-f(i-C)+f(i-A-B)+f(i-B-C)+f(i-A-C)-f(i-A-B-C);
			//cout<<ans<<" ";
		}
		cout<<ans<<endl;
	}
	return 0;
}