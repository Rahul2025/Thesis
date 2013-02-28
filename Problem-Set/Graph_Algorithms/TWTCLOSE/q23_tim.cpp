#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<ctype.h>
#include<climits>
#include<set>
#include<string>

using namespace std;

#define FOR(i, a, b) for(i=(a);i<=(b);i++)
#define FORR(i, a, b) for(i=(a);i>=(b);i--)
#define S(n) scanf("%d", &n)
#define P(k) printf("%d\n", k)
#define pb push_back
#define mp make_pair

int main(){
    int n, k, i, j, t;
    S(n); S(k);
    int tweet[1005];
    FOR(i, 0, 1004) tweet[i] = 0;
    char str[10];
    int ans = 0;
    FOR(i, 0, k-1){
        scanf("%s", str);
        if(strcmp(str, "CLICK") == 0){
            S(t);
            tweet[t] ^= 1;
            ans = (tweet[t] == 0) ? ans-1 : ans+1;
        }
        else{
            FOR(j, 1, n) tweet[j] = 0;
            ans = 0;
        }
        P(ans);
    }
//    system("pause");
    return 0;
}