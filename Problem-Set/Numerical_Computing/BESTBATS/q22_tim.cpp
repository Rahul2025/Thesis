/*----------Author- Akshit Gaur-------------*/


#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>
#include<string>
#include<cstring>
#include<cmath>
#include<ctime>
#include<list>
#include<stack>
#include<cstdlib>
#include<set>
#include<map>
#include<queue>
#include<fstream>
#include<deque>
#include<numeric>

#define forn(i,n) for(i=0;i<n;i++)
#define forn1(i,n) for(i=1;i<=n;i++)
#define sf scanf
#define pf printf
#define LL 11111111

int a[12];

using namespace std;

inline int fact(int n)
{
int i,prod=1;
for(i=1;i<=n;i++)
prod*=i;
return prod;
}

int main()
{
   // freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);

	//calc();
	int t,i,k,rep,s,j,count1,count;
	sf("%d",&t);
	while(t--)
	{
		count=0;count1=0;
		forn(i,11)
		{
			sf("%d",&a[i]);
			//b[i]=a[i];
		}
		sf("%d",&k);
		sort(a,a+11);
		reverse(a,a+11);
		rep=a[k-1];
		for(i=0;i<11;i++)
        if(rep==a[i])
			count++;

        for(j=0;j<k;j++)

				if(rep==a[j])
				count1++;

		int n1=fact(count);
		int n2=fact(count1);
		int n3=fact(count-count1);
		pf("%d\n",n1/(n2*n3));
	}
	//fclose(stdin); 1 1 1 2 2 2 2 4 5 5  6
	//fclose(stdout);
	return 0;
}


