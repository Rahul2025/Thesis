//DS includes
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<bitset>
#include<complex>

//Other Includes
#include<sstream>
#include<fstream>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>



#define oo 					(int)13e7
#define s(n)					scanf("%d",&n)
#define sl(n) 					scanf("%lld",&n)
#define sf(n) 					scanf("%lf",&n)
#define fill(a,v) 				memset(a, v, sizeof a)
#define ull 					unsigned long long
#define ll 						long long
#define bitcount 			__builtin_popcount
#define all(x) 				x.begin(), x.end()
#define pb( z ) 				push_back( z )
#define gcd					__gcd
using namespace std;

int n;
//prev = 0 not connected left thing
//prev = 1 connected left thing
ull dp[64][2];
int vis[64][2], vid;
ull solve( int p, int prev )
{
	//cout<< n << " " << p << " " << prev << endl;
	if( p==n-1 )
	{
		if( prev == 0 )
			return 1LL;
		return 2LL;
	}
	ull &d = dp[p][prev];
	int& v = vis[p][prev];
	if( v == vid )
		return d;
	ll ret = 0; v = vid;
	if( prev == 0 )
	{
		ret = solve( p+1, 1 ) + solve( p+1, 0 );
	}
	else 
	{
		ret = 2*solve( p+1, 1 ) + solve( p+1, 0 );
	}
	return d=ret;
}

int main()
{
	
	while( cin>>n )
	{
		if( !n ) break;
		fill( dp, -1 );
		++vid;
		cout<< solve( 0, 0 ) << endl;
	}
	return 0;
}