#include <iostream>
#include <cstdio>

using namespace std;

int abs(int x){ return (x < 0) ? -x : x; }
int allones(int n){ return (1 << n) - 1; }

int main(){
#ifdef ACM
	freopen("test.in", "r", stdin);
#endif

	int t; scanf("%d", &t);
	while(t-- > 0){
		int n; unsigned int a, b; scanf("%d %d %d", &n, &a, &b);

		int ca = __builtin_popcount(a);
		int cb = __builtin_popcount(b);

		if(ca + cb <= n){
			cout << (allones(ca+cb) << (n - ca - cb)) << endl;
		}else{
			cout << (allones(n) ^ (allones(ca + cb - n))) << endl;
		}
	}

	return 0;
}