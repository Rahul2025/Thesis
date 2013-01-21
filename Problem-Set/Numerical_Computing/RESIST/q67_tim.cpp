#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cstdlib>
#include <cmath>
#include <bitset>
#include <cassert>
using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define forsn(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define forall(i,c) for(typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define dforn(i,n) for(int i=((int)(n)-1);i>=0;i--)
#define dforsn(i,s,n) for(int i=((int)(n)-1);i>=(int)(n);i--)
#define esta(i,c) ((c).find(i) != (c).end())
#define estal(i,c) (find((c).begin(),(c).end(),(i))!=(c).end())
#define all(c) (c).begin(),(c).end()

#define dbg(x) cerr << #x << " = " << x << endl;
#define raya cerr << string(80,'=') << endl;

typedef long long tint;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector< pair<int,int> > vii;
typedef pair<tint,tint> ptt;
typedef vector<tint> vt;
typedef vector< vector<tint> > vtt;

int m;
void print(const vtt & mat){
	forn(i,2){
		forn(j,2) cerr << mat[i][j] << " ";
		cerr << endl;
	}
}
vtt mult(vtt & mat1, vtt & mat2){
	vtt res = mat1;
	
	forn(i,2)
	forn(j,2)
	{
		res[i][j] = 0;
		forn(k,2) res[i][j] = (res[i][j]+((mat1[i][k]%m)*(mat2[k][j]%m)%m))%m;
	}
	return res;
} 
vtt orifibo;
vtt modfibo(int x){
	if(x == 0){ 
		vtt res(2); res[0].resize(2); res[1].resize(2);
		res[0][0]=1,res[0][1]=0,res[1][0]=0,res[1][1]=1; 

		return res;
	}
	vtt mat = modfibo(x/2);
	mat = mult(mat,mat);
	if(x&1) mat = mult(mat,orifibo);

	return mat;
}

int main(){
	#ifdef JUAMPI
		freopen("RESIST.in","r",stdin);
	#endif
	
	int t;
	scanf("%d",&t);

	orifibo = vtt(2); orifibo[0].resize(2); orifibo[1].resize(2);
	orifibo[0][0]=1,orifibo[0][1]=1,orifibo[1][0]=1,orifibo[1][1]=0;
	
	while(t--){
		int n; scanf("%d%d",&n,&m);

		vtt mat = modfibo(2*n-1);
		tint x = mat[0][0], y = mat[0][1];
		
		printf("%lld/%lld\n",y,x);
	}
	return 0;
}