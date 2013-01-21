#include <iostream>
#include <vector>
using namespace std;

typedef long long LL;

LL C (int n, int r)
{
    LL ans = 1;
    if(n - r < r)
	r = n - r;
    for (int i = 1; i <= r ; i++)
	ans = (ans * (n+1-i))/i;
    return ans;
}

int main()
{
    int n, k, N, R;
    int t;
    scanf("%d", &t);
    while(t--)
    {
	scanf("%d %d", &n, &k);
	N = k;
	R = n - k;
	LL ans = C(N + R - 1, R);
	printf("%lld\n", ans);
    }
    return 0;
}
