#include <vector>
#include <cassert>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <climits>
#include <fstream>
#include <sstream>
#include<ctype.h>
 
#define PI 3.1415926535897932384626433832795028841971693993751058209749Lf
#define INF 2000000000
#define INFI 1e37
#define pb push_back
#define PRINT(x)           cout << #x << "  " << x << endl
#define MAX ((int)1e6+10)
#define MOD 1000000007
#define BUF 4096
 
char ibuf[BUF];
int ipt = BUF;
 
int readInt() {
	while (ipt < BUF && ibuf[ipt] < '0') ipt++;
	if (ipt == BUF) {
		fread(ibuf, 1, BUF, stdin);
		ipt = 0;
		while (ipt < BUF && ibuf[ipt] < '0') ipt++;
	}
	int n = 0;
	while (ipt < BUF && ibuf[ipt] >= '0') n = (n*10)+(ibuf[ipt++]-'0');
	if (ipt == BUF) {
		fread(ibuf, 1, BUF, stdin);
		ipt = 0;
		while (ipt < BUF && ibuf[ipt] >= '0') n = (n*10)+(ibuf[ipt++]-'0');
	}
	return n;
}
 
using namespace std;
int ways[MAX];
int ans[MAX];
int a[MAX];
int main()
{
	int n,m,j;
	n=readInt();
	m=readInt();
	for(int i=0;i<n;i++)
	{
		a[i]=readInt();
	}
	ans[n-1]=0;
	ways[n-1]=1;
	int k=j=n-1;
	int sum=0,sumways=0;
	for(int i=n-2;i>=0;i--)
	{
		sum+=a[i+1]-a[i];
		while(sum>m)
		{
			sum-=a[j]-a[j-1];
			sumways-=ways[j];
			if(sumways<0)
				sumways+=MOD;
			--j;
		}
		ans[i]=ans[j]+1;
		while(ans[k]!=ans[i])
		{
			sumways+=ways[k];
			if(sumways>MOD)
				sumways-=MOD;
			k--;
		}
		ways[i]=sumways;
	}
	printf("%d %d\n",ans[0]-1,ways[0]);
 
 
	return 0;
}