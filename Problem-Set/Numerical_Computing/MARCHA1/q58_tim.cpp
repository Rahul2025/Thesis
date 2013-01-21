/*
 Petar 'PetarV' Velickovic
 Task: MARCHA1
*/

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;

int t, n, m;
int note[55];
bool done;

void solve(int i, int sum)
{
    if (sum == m)
    {
        done = true;
        return;
    }
    if (sum > m || i == n) return;
    solve(i+1,sum+note[i]);
    if (done) return;
    solve(i+1,sum);
}

int main()
{
    scanf("%d",&t);
    while (t--)
    {
        scanf("%d%d",&n,&m);
        for (int i=0;i<n;i++) scanf("%d",&note[i]);
        done = false;
        solve(0,0);
        if (done) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}