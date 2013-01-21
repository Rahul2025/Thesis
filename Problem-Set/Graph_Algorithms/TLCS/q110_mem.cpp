#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <iterator>
#include <map>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <cassert>
#include <deque>
#include <stack>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <string>
#include <cmath>
#include <ctime>
 
using namespace std;
 
#define LET(x,a)        __typeof(a) x(a) 
#define IFOR(i,a,b)     for(LET(i,a);i!=(b);++i) 
#define EACH(it,v)      IFOR(it,v.begin(),v.end()) 
#define FOR(i,a,b)      for(int i=(int)(a) ; i < (int)(b);i++) 
#define REP(i,n)        FOR(i,0,n) 
#define SZ              size() 
#define PB              push_back 
#define PF              push_front 
#define V(x)            vector< x > 
#define two(X)          (1<<(X))
#define twoL(X)         (((int64)(1))<<(X))
#define contain(S,X)    (((S)&two(X))!=0)
#define containL(S,X)   (((S)&twoL(X))!=0
#define swap(x,y)       x ^=y ^= x^=y
 
const double pi=acos(-1.0);
const double eps=1e-11;
template<class T> inline void checkmin(T &a,T b){if(b<a) a=b;}
template<class T> inline void checkmax(T &a,T b){if(b>a) a=b;}
template<class T> inline T sqr(T x){return x*x;}
typedef pair<int,int> ipair;
template<class T> inline T lowbit(T n){return (n^(n-1))&n;}
template<class T> inline int countbit(T n){return (n==0)?0:(1+countbit(n&(n-1)));}
 
typedef long long       ll;
typedef V(int)          VI;
typedef V(VI)           VII;
typedef V(string)       VS;
typedef long long       LL;
typedef long double     LD;
typedef pair<int,int>   PI;
 
/*
inline void btrack(char s[],char t[],int i,int j)
{
	if(i==0 || j==0) return ;
	else {
		if(s[i]==t[j]) { btrack(s,t,i-1,j-1); printf("%c %d %d\n",s[i],i,j); }
		else {
			lcs[i-1][j] > lcs[i][j-1] ?btrack(s,t,i-1,j):btrack(s,t,i,j-1);
		}
	}	
}
*/
int main()
{
	int lcs[1001][1001];
	int test;scanf("%d",&test);
	REP(cas,test) {
		int m,n;//char s[1001],t[1001];
		char ss[1001],tt[1001];
		scanf("%d%s",&m,ss);
		scanf("%d%s",&n,tt);
		char s[1001],t[1001];
		strcpy(s,"$");
		strcpy(t,"$");
		strcat(s,ss);
		strcat(t,tt);
		int i,j;
		if(n*m>130000) printf("case %d N\n",cas+1) ;
		else {
			//memset(lcs,0,sizeof(lcs));
			for(i=0;i<=m;++i) {
				for(j=0;j<=n;j++) {
					if(i==0||j==0) { lcs[i][j]=0; }
					else { 
						if(s[i]==t[j]) { 
							lcs[i][j] = lcs[i-1][j-1]+1;
						} else {
							lcs[i][j] = max(lcs[i-1][j],lcs[i][j-1]);
						}
					}	
				}
			}
			printf("case %d Y\n%d\n",cas+1,lcs[m][n]);
			char c[1001];int ind1[1001],ind2[1001];
			int k=0;i=m,j=n;
			while(lcs[m][j]==lcs[m][j-1]) --j;
			while(lcs[i][j]==lcs[i-1][j]) --i;
			while(i>0 && j>0)
			{
				if(s[i]==t[j])  { c[k]=s[i],ind1[k]=i,ind2[k++]=j;i-=1;j-=1; }
				else {
					if(lcs[i-1][j]>lcs[i][j-1]) {
						i-=1;
					} else { j-=1; }
				}
			} 
			for(int k1=k-1;k1>=0;k1--) printf("%c %d %d\n",c[k1],ind1[k1],ind2[k1]);
		}
	}
	return 0;
}