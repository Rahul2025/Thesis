//Zac Friggstad
//O(n)

//#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

const int MOD = 1000000007;

struct Leg {
  int dist, ways;
  Leg (int d = 0, int w = 0) : dist(d), ways(w) {}
};

int main() {
  int n, m, mx = 0, ts[2], at = 0, hops = 0;
  //cin >> n >> m;
  scanf("%d %d\n", &n, &m);

  queue<Leg> q[2];
  for (int i = 0; i < n; ++i) {
    int a;

    //cin >> a;
    scanf("%d", &a);

    if (i == 0) {
      q[0].push(Leg(m+a,1));
      ts[0] = 1;
      ts[1] = 0;
    }
    else {
      while (!q[at].empty() && q[at].front().dist < a) {
	ts[at] = (MOD - q[at].front().ways + ts[at])%MOD;
	q[at].pop();
      }

      if (q[at].empty()) {
	at = 1-at;
	++hops;
      }

      //this might not be necessary... but it can't hurt!
      while (!q[at].empty() && q[at].front().dist < a) {
	ts[at] = (MOD - q[at].front().ways + ts[at])%MOD;
	q[at].pop();
      }

      q[1-at].push(Leg(a+m,ts[at]));
      ts[1-at] = (ts[at]+ts[1-at])%MOD;
    }
  }
  //cout << hops << ' ' << ts[at] << endl;
  printf("%d %d\n", hops, ts[at]);
}