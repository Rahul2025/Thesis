// codechef.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string.h>
#include <math.h>
#define RNUM 3
#define MAX(a,b) ((a) > (b)) ? (a) : (b)  
#define MIN(a,b) (a) < (b) ? (a) : (b)


long long comb3(long long n)
    {
    if(n<3)
	  return 0;
    long long num= n*(n-1)*(n-2)/6;
    return num;
    }

    

int main()
    {      
      
    int t=0;
    scanf("%d",&t);
    while(t--)
	  {
	  int n=0, a=0, b=0, c=0;
	  scanf("%d %d %d %d\n",&n,&a,&b,&c);
	  a++; b++; c++;
	  long long ans=comb3(3+n) - comb3(3+n-a-b-c) + (comb3(3+n-a-b)+comb3(3+n-b-c)+comb3(3+n-a-c)) -(comb3(3+n-a)+comb3(3+n-b)+comb3(3+n-c));
	  printf("%lld\n",ans);
	  }   
    return 0;
    }
