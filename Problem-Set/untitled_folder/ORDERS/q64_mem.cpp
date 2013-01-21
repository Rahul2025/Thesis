#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int tree[200005],T,N,S[200005],sum,hi,lo,mid,tmp;

void U(int x){
	while(x <= N){
		++tree[x];
		x += (x&-x);
	}
}

void U2(int x){
	while(x <= N){
		--tree[x];
		x += (x&-x);
	}
}

int Q(int x){
	sum = 0;
	while(x > 0){
		sum += tree[x];
		x -= (x&-x);
	}
	return sum;
}

int main(){
	scanf("%d",&T);
	while(T>0){
		--T;
		scanf("%d",&N);
		for(int i=1;i<=N;++i) scanf("%d",&S[i]);
		for(int i=1;i<=N;++i) U(i);
		for(int i=N;i>0;--i){
			lo = 1;
			hi = N;
			tmp = i-S[i];
			while(hi >= lo){
				mid = (hi+lo)/2;
				if(Q(mid) > tmp) hi = mid-1;
				else if(Q(mid) < tmp) lo = mid+1;
				else if(Q(mid) == tmp){
					if(Q(mid)-Q(mid-1) == 1) break;
					else hi = mid-1;
				}
			}
			if(lo > 0 && Q(lo) == tmp && Q(lo)-Q(lo-1) == 1){
				S[i] = lo;
				U2(lo);
			}
			else if(mid > 0 && Q(mid) == tmp && Q(mid)-Q(mid-1) == 1){
				S[i] = mid;
				U2(mid);
			}
			else if(hi > 0 && Q(hi) == tmp && Q(hi)-Q(hi-1) == 1){
				S[i] = hi;
				U2(hi);
			}
		}
		for(int i=1;i<=N;++i) printf("%d ",S[i]);
		printf("\n");
	}
//	system("pause");
}