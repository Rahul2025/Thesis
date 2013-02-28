#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string.h>
#include <queue>

#define MAXV 1010
#define MAXE 2020

using namespace std;

const int MAX_SIZE = 20000;
static char input[MAX_SIZE];
struct Scanner
{
	Scanner()
	{
		int sz = fread(input, 1, sizeof(input), stdin);
		curPos = input;
	}
	int nextInt()
	{
		int gap = input + MAX_SIZE - curPos;
		if (gap < 100)
		{
			memcpy(input, curPos, gap);
			fread(input + gap, 1, sizeof(input) - gap, stdin);
			curPos = input;

		}
		while (*curPos < '0') curPos++;

		int res = 0;
		while (*curPos >= '0') 
		{
			res = res * 10 + (*curPos) - '0';
			curPos++;
		}
		return res;
	}
	char* curPos;
};


int V,E;

int last[MAXV];
int next[MAXE];
int adj[MAXE];
int weight[MAXE];
int ne;

void addedge(int u, int v, int w)
{
	next[ne] = last[u];
	adj[ne] = v;
	weight[ne] = w;
	last[u] = ne;
	ne++;
}

int parent[MAXV];
int rank[MAXV];

int find(int u)
{
	if(parent[u] == -1) return u;
	else return parent[u] = find(parent[u]);
}

int _union(int u, int v)
{
	if(rank[u] >= rank[v]) parent[v] = u;
	if(rank[v] > rank[u]) parent[u] = v; 
	if(rank[u] == rank[v]) rank[u]++;
}

struct edges
{
	int s,t,w;
}e[1000010];

bool func(edges a, edges b)
{
	return a.w < b.w;
}

unsigned dist[MAXV];
char vis[MAXV];

void getScore(int s)
{
	memset(dist, -1, sizeof dist);
	memset(vis, 0, sizeof vis);

	queue<int> q;
	q.push(s);
	dist[s] = 100000009;
	vis[s] = 1;

	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for(int e = last[u]; e!=-1; e = next[e])
		{
			int v = adj[e];
			int w = weight[e];
			if(vis[v] == 0)
			{
				q.push(v);
				dist[v] = min((unsigned)w,dist[u]);
				vis[v] = 1;
			}
		}
	}
	
	dist[s] = 0;
}

int cmp(const void *a, const void *b)
{
	edges *A = (edges *)a;
	edges *B = (edges *)b;
	
	if(A->w < B->w) return -1;
	return 1;
}

int main()
{
	scanf("%d %d",&V,&E);

	ne = 0;
	memset(last, -1, sizeof last);
	memset(next, -1, sizeof next);
	memset(parent, -1, sizeof parent);
	memset(rank, 0, sizeof rank);

	Scanner inp;

	for(int i=0 ; i<E ; i++)
	{
		//scanf("%d %d %d", &e[i].s, &e[i].t, &e[i].w);
		e[i].s = inp.nextInt();
		e[i].t = inp.nextInt();
		e[i].w = inp.nextInt();
		e[i].w = - e[i].w;
	}

	//for(int i=0 ; i<V ; i++) parent[i] = i, rank[i] = 0;

	qsort(&e, E, sizeof(edges), cmp);

	int k=0;	
	for(int i=0 ; i<E && k<V-1; i++)
	{
		int u = find(e[i].s);
		int v = find(e[i].t);
		if(u != v)
		{
			addedge(e[i].s, e[i].t, -e[i].w);
			addedge(e[i].t, e[i].s, -e[i].w);
			k++;
			_union(u,v);
		}
	}
	
	for(int i=0 ; i<V ; i++)
	{
		getScore(i);
		for(int j=0 ; j<V ; j++)
			printf("%d ", dist[j]);
		printf("\n");
	}
}
