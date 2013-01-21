// codechef.cpp : Defines the entry point for the console application.
//


#include <iostream>
#include <string.h>
#include<stdio.h>
#include <math.h>
#define MAX(a,b) ((a) > (b)) ? (a) : (b)  
#define MIN(a,b) (a) < (b) ? (a) : (b)

int flip(int n, int k, int kpow)
    {
    int temp=0;
    int i=1;
    for(;i<=k/2;i++,kpow>>=1)
	  temp+=((n & kpow)>>(k-2*i+1));
    if(k%2)
	  {
	  temp+=(n & kpow);
	  kpow>>=1;
	  i++;
	  }
    for(;i<=k;i++, kpow>>=1)
	  temp+=((n & kpow)<<(2*i-1-k));    
    return temp;
    }

int main()
    {      
     
    int t=0;
    char buf[65537];
    scanf("%d",&t);
    while(t--)
	  {
	  int k=0;
	  scanf("%d",&k);
	  int kpow=(int)pow((float)2, k-1);
	  int realpow=(kpow*2);
	  /*char *buf = new char[realpow + 1];	*/ 	  
	  scanf("%s",buf);	  
	  for(int i=0;i<realpow;i++)
		printf("%c",buf[flip(i,k,kpow)]);
	  printf("\n");
	  /*delete []buf;*/
	  }

    return 0;
    }