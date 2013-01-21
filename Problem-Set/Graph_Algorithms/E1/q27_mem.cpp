// codechef.cpp : Defines the entry point for the console application.
//


#include <iostream>
#include <string.h>
#include <math.h>
#define MAX(a,b) (a) > (b) ? (a) : (b)
#define VALID(i,j) ((i)>=0)&&((i)<n)&&((j)<n)


    


int main()
    {       
     
    int t=0;
    scanf("%d",&t);
    while(t--)
	  {
	  int n=0;
	  int ki=0, kj=0;
	  scanf("%d\n",&n);
	  bool **knight = new bool*[n];
	  bool **pawns = new bool*[n];
	  short **count = new short*[n];
	  char input=0;
	  int max=0;
	  for(int i=0;i<n;i++)
		{
		knight[i] = new bool[n];
		pawns[i] = new bool[n];
		count[i] = new short[n];
		for(int j=0;j<n;j++)
		    {
		    scanf("%c",&input);
		    knight[i][j]=false;
		    pawns[i][j]=false;
		    count[i][j]=0;
		    switch(input)
			  {
			  case 'K':	  knight[i][j]=true;	ki=i; kj=j;	break;
			  case 'P':	  pawns[i][j]=true; break;
			  }		    
		    }
		scanf("\n");
		}
	  for(int j=kj; j<n; j++)
		{
		for(int i=0; i<n;i++)
		    {
		    if(!knight[i][j])
			  continue;
		    if(pawns[i][j])
			  count[i][j]++;
		    if(VALID(i+1,j+2)) {    knight[i+1][j+2]=true;  count[i+1][j+2]=MAX(count[i][j],count[i+1][j+2]);} 
		    if(VALID(i-1,j+2)) {    knight[i-1][j+2]=true;  count[i-1][j+2]=MAX(count[i][j],count[i-1][j+2]);} 
		    if(VALID(i+2,j+1)) {    knight[i+2][j+1]=true;  count[i+2][j+1]=MAX(count[i][j],count[i+2][j+1]);} 
		    if(VALID(i-2,j+1)) {    knight[i-2][j+1]=true;  count[i-2][j+1]=MAX(count[i][j],count[i-2][j+1]);}
		    if(count[i][j]>max)
			  max=count[i][j];		   
		    }
		}
	  for(int i=0;i<n;i++)
		{		
		delete []count[i];
		delete []knight[i];
		delete []pawns[i];
		}
	  printf("%d\n",max);	  	  
	  } 
	  
    
    return 0;
    }