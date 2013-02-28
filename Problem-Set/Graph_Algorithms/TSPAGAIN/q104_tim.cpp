#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
int T,N,K;
int dist[1010][1010];
int f0[2000];
int f1[2000];
int togo[2000];
int tocome[2000];
int main()
{
  scanf("%d",&T);
  for(int t=1;t<=T;t++)
    {
      scanf("%d %d",&N,&K);
      for(int i=0;i<N;i++)
	for(int j=0;j<N;j++)
	  dist[i][j]=0;
      for(int j=0;j<K;j++)
	{
	  int x,y;
	  scanf("%d %d",&x,&y);
	  dist[x][y]++;
	}

      /*for(int i=0;i<N;i++)
	{
	  for(int j=0;j<N;j++)
	    printf("%02d ",dist[i][j]);
	  printf("\n");
	  }*/
	
      for(int j=0;j<N;j++)
	{
	  int prev=0;
	  for(int i=N-1;i>=0;i--)
	    {
	      dist[i][j]=prev+dist[i][j];
	      prev=dist[i][j];
	    }
	}
      for(int i=0;i<N;i++)
	{
	  int prev=0;
	  for(int j=0;j<N;j++)
	    {
	      dist[i][j]+=prev;
	      prev=dist[i][j];
	    }
	}

      /*for(int i=0;i<N;i++)
	{
	  for(int j=0;j<N;j++)
	    printf("%02d ",dist[i][j]);
	  printf("\n");
	  }*/
	
      
      togo[0]=0;
      for(int i=1;i<N;i++)
	togo[i]=togo[i-1]+dist[i-1][i];

      tocome[N-1]=0;
      for(int i=N-2;i>=0;i--)
	{
	  tocome[i]=tocome[i+1]+dist[i+1][i];
	}
      
      f0[1]=dist[1][0];
      f1[1]=dist[0][1];
      //printf("dsfsf\n");
      for(int i=2;i<N;i++)
	{
	  int optval0=1000000000;
	  int optval1=1000000000;
	  for(int j=1;j<i;j++)
	    {
	      optval0=min(optval0,dist[i][j-1]+togo[i-1]-togo[j]+f1[j]);
	      optval1=min(optval1,dist[j-1][i]+tocome[j]-tocome[i-1]+f0[j]);
	    }
	  f1[i]=optval1;
	  f0[i]=optval0;
	}

      printf("%d\n",min(f0[N-1]+dist[N-2][N-1],f1[N-1]+dist[N-1][N-2]));
      


     

    }
}