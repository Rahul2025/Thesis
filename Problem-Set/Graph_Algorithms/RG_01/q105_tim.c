#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXV 1000
#define MAXE 500000

int input[MAXE][3];

void WQY_bedge_fast_sort(int st,int end)
{
	int low, high;
	int pivotK0, pivotK1, pivotK2;
	low=st;
	high=end;

	if(st>=end)
		return;

	pivotK0=input[low][0];
	pivotK1=input[low][1];
	pivotK2=input[low][2];
	
	while(low<high)
	{
		while(low<high && input[high][2]<=pivotK2)
		{
			high--;
		}
		input[low][0]=input[high][0];
		input[low][1]=input[high][1];
		input[low][2]=input[high][2];

		while(low<high && input[low][2]>=pivotK2)
		{
			low++;
		}
		input[high][0]=input[low][0];
		input[high][1]=input[low][1];
		input[high][2]=input[low][2];
	}
	input[low][0]=pivotK0;
	input[low][1]=pivotK1;
	input[low][2]=pivotK2;

	WQY_bedge_fast_sort(st,low-1);
	WQY_bedge_fast_sort(high+1,end);
}

int main()
{
	int V, E, u, v;
	int i, j, m, n;
	int results[MAXV][MAXV];
	int label[MAXV][MAXV];
	int group[MAXV];

	scanf("%d%d",&V,&E);

	for(i=0;i<E;i++)
	{
		scanf("%d%d%d",&(input[i][0]),&(input[i][1]),&(input[i][2]));
	}
	WQY_bedge_fast_sort(0,E-1);

	for(i=0;i<V;i++)
		for(j=0;j<V;j++)
			label[i][j]=-!(results[i][j]=0);

	for(i=0;i<V;i++)
	{
		label[i][0]=i;
		group[i]=i;
	}

	for(i=0;i<E;i++)
	{
		if(group[input[i][0]]!=group[input[i][1]])
		{
			u=group[input[i][0]]<group[input[i][1]]?group[input[i][0]]:group[input[i][1]];
			v=group[input[i][0]]>group[input[i][1]]?group[input[i][0]]:group[input[i][1]];
			for(m=0;label[u][m]!=-1;m++)
			{
				for(n=0;label[v][n]!=-1;n++)
				{
					results[label[u][m]][label[v][n]]=input[i][2];
					results[label[v][n]][label[u][m]]=input[i][2];
				}
			}
			for(n=0;label[v][n]!=-1;n++,m++)
			{
				label[u][m]=label[v][n];
				group[label[v][n]]=group[label[u][0]];
			}
		}
	}

	for(i=0;i<V;i++)
	{
		for(j=0;j<V;j++)
			printf("%d ",results[i][j]);
		printf("\n");
	}

	return 0;
}