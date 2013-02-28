#include <iostream>
#include <math.h>
#include <list>
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include <memory.h>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <stdio.h>
#include <assert.h>
 
using namespace std;
#define SET(a,n) memset(a,n,sizeof(a));
#define FOR(a,b,c) for(int a=b;a<c;++a)
#define GN(a) scanf("%d",&a)
 
typedef long long int LL;
typedef vector<int> VI;
 
using namespace std;
 
const LL MOD = 1000000080798150871LL;
 
char win[1002][4];
int L,K;
LL nck[1002][1002];
 
 
LL get(int N,int M)
{
    int colsum[4];
 
    FOR(i,0,M) {
        colsum[i]=0;
        FOR(j,0,N) {
            colsum[i]+=(win[j][i]-'0');
        }
    }
 
    LL ans = 0;
    int rowsum[1002];
    int colsel[4],csize;
 
    FOR(n,0,(1<<M)) {
        if(__builtin_popcount(n)==K) {
            bool ok = 1;
            csize=0;
            FOR(j,0,M) {
                if(n&(1<<j)) {
                    if(colsum[j]<L) {
                        ok = 0;
                        break;
                    } else {
                        colsel[csize++]=j;
                    }
                }
            }
 
            if(ok) {
                SET(rowsum,0);
                FOR(i,0,N) {
                    FOR(j,0,csize) {
                        rowsum[i]+=win[i][colsel[j]]-'0';
                    }
                }
                int tot=0;
                FOR(i,0,N) {
                    if(rowsum[i]>=K)tot++;
                }
                ans=((LL)ans+nck[tot][L])%MOD;
 
            }
        }
    }
    return ans;
}
int main()
{
    //  freopen("i.txt","r",stdin);
    SET(nck,0);
    FOR(i,0,1001) {
        nck[i][0]=1;
        nck[i][i]=1;
        FOR(j,1,i) {
            nck[i][j]=(nck[i-1][j-1]+nck[i-1][j])%MOD;
        }
    }
    int t;
    cin>>t;
    while(t--) {
        int N,M;
        cin>>N>>M>>L>>K;
 
        FOR(i,0,N) {
            scanf("%s",win[i]);
        }
        cout<<(LL)get(N,M)<<endl;
    }
    return 0;
}
 