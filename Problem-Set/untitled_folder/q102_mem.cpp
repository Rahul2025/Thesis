#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<string>
#include<utility>
#include<cassert>
using namespace std;

#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int N;
int edge1[100][100], edge2[100][100];
int res[100], res_score;
int now[100], now_score;

int cal_score(int now[]){
  int i,j,score=0;
  rep(i,N) rep(j,N) if(edge1[i][j] && edge2[now[i]][now[j]]) score++;
  return score;
}

int main(){
  int T;

  int i,j,k,loop;
  int res[100], inv[100];
  
  assert( scanf("%d",&T) == 1 );
  assert( T == 5 );

  while(T--){
    assert( scanf("%d",&N) == 1 );
    assert( 30 <= N && N <= 75 );
    rep(i,N) rep(j,N) assert( scanf("%d",edge1[i]+j)==1 && 0 <= edge1[i][j] && edge1[i][j] <= 1 );
    rep(i,N) rep(j,N) assert( scanf("%d",edge2[i]+j)==1 && 0 <= edge2[i][j] && edge2[i][j] <= 1 );
    rep(i,N) assert( edge1[i][i] == 0 && edge2[i][i] == 0 );
    rep(i,N) REP(j,i+1,N) assert( edge1[i][j] == edge1[j][i] && edge2[i][j] == edge2[j][i] );

    rep(i,N){
      if(i) putchar(' ');
      printf("%d",i+1);
    }
    puts("");

    rep(i,N) now[i] = res[i] = i;
    res_score = cal_score(res);

    rep(loop,5000){
      random_shuffle(now,now+N);
      now_score = cal_score(now);
      if(res_score < now_score){
        res_score = now_score;
        rep(i,N) res[i] = now[i];
      }
    }

    rep(i,N) inv[res[i]] = i;
    rep(i,N){
      if(i) putchar(' ');
      printf("%d",inv[i]+1);
    }
    puts("");
  }

  return 0;
}