//BEGIN_CUT
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <cstdlib>
#include <numeric>
#include <bitset>
#include <cstring>
#include <sstream>
#include <utility>
#include <queue>
#include <cassert>
using namespace std;

#define X first
#define Y second
#define FI first
#define SE second
#define ST first
#define ND second
#define MP make_pair
#define PB push_back
typedef long long LL;
typedef double D;
typedef long double LD;
typedef vector<int> VI;
typedef pair<int,int> PII;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(VAR(i,a);i<=(b);++i)
#define FORD(i,a,b) for(VAR(i,a);i>=(b);--i)
#define FORE(a,b) for(VAR(a,(b).begin());a!=(b).end();++a)
#define VAR(a,b) __typeof(b) a=(b)
#define SIZE(a) ((int)((a).size()))
#define ALL(x) (x).begin(),(x).end()
#define CLR(x,a) memset(x,a,sizeof(x))
int cond = 1;
#define db(x) {if(cond){cerr << __LINE__ << " " << #x << " " << x << endl; } }
#define dbv(x) {if(cond){cerr << __LINE__ << " " << #x << ": "; FORE(__i,x) cerr << *__i << " "; cerr << endl;} }
//END_CUT

const int MD = int(1e9 + 7);

int t[100005];

int n, m;

void alg() {
	scanf("%d %d", &n, &m);
	int sum = 0;
	for (int i = 1; i <= n; ++i) {
		if (i - m - 1 >= 1) {
			sum -= t[i - m - 1];
			if (sum < 0) {
				sum += MD;
			}
		}
		t[i] = sum + max(m + 1 - i, 0);
		if (t[i] >= MD) {
			t[i] -= MD;
		}
		if (i < n - m) {
			sum += t[i];
		}
		if (sum >= MD) {
			sum -= MD;
		}
	}
	int result = 0;
	for (int i = n - m; i < n; ++i) {
		result += t[i];
		if (result >= MD) {
			result -= MD;
		}
	}
	for (int i = 1; i <= m; ++i) {
		result = (result * (LL) i) % MD;
	}
	printf("%d\n", result);
}

int main() {
	int d;
	scanf("%d", &d);
	while (d--) {
		alg();
	}

    return 0;
}