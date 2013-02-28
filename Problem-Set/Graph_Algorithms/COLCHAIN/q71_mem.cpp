#include <set>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
#include <string>
#include <cstdio>
#include <vector>
#include <utility>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#define INF 1e9
#define pb push_back
#define mp make_pair
#define forn(i,n) for (int i = 0; i < n; i++)
#define MAXN 322222
#define MAXM 322222
#define ADD  122222

using namespace std;

typedef long long ll;

const ll MOD = INF + 7;

vector <ll> dp(MAXN, -1), p(MAXN);
int t;
ll n, m;

void init();
ll ways(int k);

ll mod(ll a)
{
    return (a % MOD + MOD) % MOD;
}

void init()
{

    ll st = 0, sum = m;
    for (int i = ADD; i < MAXN; i++)
    {
        dp[i] = sum;
        sum -= dp[i - m];
        sum += dp[i];
        sum = mod(sum);
    }
}

ll ways(int k)
{
    return dp[k + ADD - 1];
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> t;
    p[0] = 1;
    for (ll i = 1; i <= MAXM; i++)
    {
        p[i] = mod(p[i - 1] * i);
    }
    for (int i = 0; i < ADD; i++)
    {
        dp[i] = 1;
    }
    while (t--)
    {
        cin >> n >> m;
        init();
        ll ans = 0;
        for (ll i = 0; i < m; i++)
        {
            ans = mod(ans + ((m - i)) * ways(n - m - i - 1));
        }
        cout << mod(ans * p[m]) << endl;
    }
    return 0;
}