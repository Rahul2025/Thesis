#include<bitset>
#include<deque>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>
#include<algorithm>
#include<functional>
#include<iterator>
#include<locale>
#include<memory>
#include<stdexcept>
#include<utility>
#include<string>
#include<fstream>
#include<ios>
#include<iostream>
#include<iosfwd>
#include<iomanip>
#include<istream>
#include<ostream>
#include<sstream>
#include<streambuf>
#include<complex>
#include<numeric>
#include<valarray>
#include<exception>
#include<limits>
#include<new>
#include<typeinfo>
#include<cassert>
#include<cctype>
#include<cerrno>
#include<cfloat>
#include<climits>
#include<cmath>
#include<csetjmp>
#include<csignal>
#include<cstdlib>
#include<cstddef>
#include<cstdarg>
#include<cstdio>
#include<cstring>
#include<ctime>
#define vi vector<int>
#define vvi vector<vi>
#define all(c) c.begin(),c.end()
#define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); ++it)
#define MAX(x) numeric_limits<x>::max()
#define FOR(i,a,b) for(int i=(int)(a) ; i < (int)(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define SZ(c) (int)c.size()
#define INF MAX(int)
#define getint() ({int e=0;for(gets(q=s);*q;)e=(e<<3)+(e<<1)+*q++-48;e;})
#define putint(a) ({int tmp=a,tmp2;*(q=s+10)='\0';for(;;){tmp2=tmp/10;*--q=tmp-(tmp2<<3)-(tmp2<<1)+48;tmp=tmp2;if(!tmp)break;}puts(q);})
#define LL long long
#define ii pair<int,int>
#define ONLINE_JUDGE 0
#define MAXN 1000010
using namespace std;
inline void r( int &n )
{
	n=0;
	int ch=getchar_unlocked();
	while( ch < '0' || ch > '9' ) ch=getchar_unlocked();
	
	while(  ch >= '0' && ch <= '9' )
		n = (n<<3)+(n<<1) + ch-'0', ch=getchar_unlocked();
}
int main()
{
	int T,N,d;
	r(T);
	while(T--)
	{
		r(N);
		int a = 1;
		int f=0;
		FOR(i,0,N)
		{
			r(d);
			if(d > a)
			{
				f = 1;
				break;
			}
			a -= d;
			a <<= 1;
		}
		if(f||a)puts("No");
		else puts("Yes");
	}
}