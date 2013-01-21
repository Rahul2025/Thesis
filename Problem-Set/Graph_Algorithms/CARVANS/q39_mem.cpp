#include<iostream>
#include<stdio.h>

using namespace std;

int main()
{
 int n, t,speed[10000],count=1,i,j;
 scanf("%d", &t);
 for ( i=0;i<t;++i)
  {
   scanf("%d",&n);
    for ( j=0;j<n;++j)
     {
       scanf("%d", &speed[j]);
       }

    if(n>1)
    {
        for (j=1;j<n; ++j)
        {
            if(speed[j]<speed[j-1])
            count=count+1;
            else
            speed[j]=speed[j-1];
        }
    }
    printf("%d \n", count);
    count=1;
    }
    return 0;
}