#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

#define ep 1e-8

int main()
{
	int m, n, p, q, tc, mx, mn;
	scanf("%d",&tc);
	while(tc--)
	{
			  scanf("%d%d%d%d",&m,&n,&p,&q);
			  m -= p;
			  n -= q;
     		  mx = max(m, n);
			  mn = min(m, n);
			  int k = mn - (int)((mx - mn) * (1 + sqrt(5.0)) / 2 + ep);
			  if(k)puts("Alice");
			  else puts("Bob");
	}
	return 0;
}