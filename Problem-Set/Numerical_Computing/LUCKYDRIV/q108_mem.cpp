# include <cstdio>
# include <cstring>
# include <cstdlib>
# include <iostream>
# include <string>
# include <cmath>
# include <vector>
# include <algorithm>
# include <ctime>
# define INF 0x7FFFFFFF
# define REP(i,n) for(int i=0;i<n;i++)
# define REP1(i,n) for(int i=1;i<=n;i++)
# define CLR(i,x) memset(i,x,sizeof(i))
# define For(i,a,b)  for(int i=a;i<=b;i++)
# define shr(a,b) ((a)>>(b))
# define shl(a,b) ((a)<<(b))
# define vi vector<int>
# define it iterator
# define pb push_back
# define ALL(i,a) i=a.begin();i!=a.end();i++
using namespace std;

typedef long long int64;
void setIO(string name){
	string is=name+".in";
	string os=name+".out";
	freopen(is.c_str(),"r",stdin);
//	freopen(os.c_str(),"w",stdout);
}

const int maxn=10010,M=1e9+7;
int f[5][39],n;
char str[maxn];
void work(){
	scanf("%s",str);n=strlen(str);
	CLR(f,0);f[0][0]=1;
	REP(i,n){
		int a=str[i]-'0';
		for(int j=3;j>=0;j--)
			for(int k=0;k<=9*j;k++)	if(f[j][k]){
				f[j+1][k+a]+=f[j][k];
				if(f[j+1][k+a]>=M)	f[j+1][k+a]-=M;
			}
	}
	int ans=0;
	REP1(i,4)	REP1(j,i){
		ans+=f[i][9*j];
		if(ans>=M)	ans-=M;
	}
	cout<<ans<<endl;
}


int main(){
	//setIO("LUCKDRIV");
	int Case;scanf("%d",&Case);
	while(Case--)	work();
	return 0;
}